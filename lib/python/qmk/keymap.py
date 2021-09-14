"""Functions that help you work with QMK keymaps.
"""
import json
import re
import sys
from pathlib import Path
from subprocess import DEVNULL

import argcomplete
from milc import cli
from pygments.lexers.c_cpp import CLexer
from pygments.token import Token
from pygments import lex

import qmk.path
from qmk.keyboard import find_keyboard_from_dir, rules_mk
from qmk.errors import CppError

# The `keymap.c` template to use when a keyboard doesn't have its own
DEFAULT_KEYMAP_C = """#include QMK_KEYBOARD_H
__INCLUDES__

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
__KEYMAP_GOES_HERE__
};

"""

# Compiled regexes
macro_cmd_re = re.compile(r'\{(delay|down|tap|up),([0-9A-Z_,]+)\}')


def template_json(keyboard):
    """Returns a `keymap.json` template for a keyboard.

    If a template exists in `keyboards/<keyboard>/templates/keymap.json` that text will be used instead of an empty dictionary.

    Args:
        keyboard
            The keyboard to return a template for.
    """
    template_file = Path('keyboards/%s/templates/keymap.json' % keyboard)
    template = {'keyboard': keyboard}
    if template_file.exists():
        template.update(json.load(template_file.open(encoding='utf-8')))

    return template


def template_c(keyboard):
    """Returns a `keymap.c` template for a keyboard.

    If a template exists in `keyboards/<keyboard>/templates/keymap.c` that text will be used instead of an empty dictionary.

    Args:
        keyboard
            The keyboard to return a template for.
    """
    template_file = Path('keyboards/%s/templates/keymap.c' % keyboard)
    if template_file.exists():
        template = template_file.read_text(encoding='utf-8')
    else:
        template = DEFAULT_KEYMAP_C

    return template


def _strip_any(keycode):
    """Remove ANY() from a keycode.
    """
    if keycode.startswith('ANY(') and keycode.endswith(')'):
        keycode = keycode[4:-1]

    return keycode


def find_keymap_from_dir():
    """Returns `(keymap_name, source)` for the directory we're currently in.

    """
    relative_cwd = qmk.path.under_qmk_firmware()

    if relative_cwd and len(relative_cwd.parts) > 1:
        # If we're in `qmk_firmware/keyboards` and `keymaps` is in our path, try to find the keyboard name.
        if relative_cwd.parts[0] == 'keyboards' and 'keymaps' in relative_cwd.parts:
            current_path = Path('/'.join(relative_cwd.parts[1:]))  # Strip 'keyboards' from the front

            if 'keymaps' in current_path.parts and current_path.name != 'keymaps':
                while current_path.parent.name != 'keymaps':
                    current_path = current_path.parent

                return current_path.name, 'keymap_directory'

        # If we're in `qmk_firmware/layouts` guess the name from the community keymap they're in
        elif relative_cwd.parts[0] == 'layouts' and is_keymap_dir(relative_cwd):
            return relative_cwd.name, 'layouts_directory'

        # If we're in `qmk_firmware/users` guess the name from the userspace they're in
        elif relative_cwd.parts[0] == 'users':
            # Guess the keymap name based on which userspace they're in
            return relative_cwd.parts[1], 'users_directory'

    return None, None


def keymap_completer(prefix, action, parser, parsed_args):
    """Returns a list of keymaps for tab completion.
    """
    try:
        if parsed_args.keyboard:
            return list_keymaps(parsed_args.keyboard)

        keyboard = find_keyboard_from_dir()

        if keyboard:
            return list_keymaps(keyboard)

    except Exception as e:
        argcomplete.warn(f'Error: {e.__class__.__name__}: {str(e)}')
        return []

    return []


def is_keymap_dir(keymap, c=True, json=True, additional_files=None):
    """Return True if Path object `keymap` has a keymap file inside.

    Args:
        keymap
            A Path() object for the keymap directory you want to check.

        c
            When true include `keymap.c` keymaps.

        json
            When true include `keymap.json` keymaps.

        additional_files
            A sequence of additional filenames to check against to determine if a directory is a keymap. All files must exist for a match to happen. For example, if you want to match a C keymap with both a `config.h` and `rules.mk` file: `is_keymap_dir(keymap_dir, json=False, additional_files=['config.h', 'rules.mk'])`
    """
    files = []

    if c:
        files.append('keymap.c')

    if json:
        files.append('keymap.json')

    for file in files:
        if (keymap / file).is_file():
            if additional_files:
                for additional_file in additional_files:
                    if not (keymap / additional_file).is_file():
                        return False

            return True


def generate_json(keymap, keyboard, layout, layers):
    """Returns a `keymap.json` for the specified keyboard, layout, and layers.

    Args:
        keymap
            A name for this keymap.

        keyboard
            The name of the keyboard.

        layout
            The LAYOUT macro this keymap uses.

        layers
            An array of arrays describing the keymap. Each item in the inner array should be a string that is a valid QMK keycode.
    """
    new_keymap = template_json(keyboard)
    new_keymap['keymap'] = keymap
    new_keymap['layout'] = layout
    new_keymap['layers'] = layers

    return new_keymap


def generate_c(keymap_json):
    """Returns a `keymap.c`.

    `keymap_json` is a dictionary with the following keys:

        keyboard
            The name of the keyboard

        layout
            The LAYOUT macro this keymap uses.

        layers
            An array of arrays describing the keymap. Each item in the inner array should be a string that is a valid QMK keycode.

        macros
            A sequence of strings containing macros to implement for this keyboard.
    """
    new_keymap = template_c(keymap_json['keyboard'])
    layer_txt = []

    for layer_num, layer in enumerate(keymap_json['layers']):
        if layer_num != 0:
            layer_txt[-1] = layer_txt[-1] + ','
        layer = map(_strip_any, layer)
        layer_keys = ', '.join(layer)
        layer_txt.append('\t[%s] = %s(%s)' % (layer_num, keymap_json['layout'], layer_keys))

    keymap = '\n'.join(layer_txt)
    new_keymap = new_keymap.replace('__KEYMAP_GOES_HERE__', keymap)

    if keymap_json.get('macros'):
        macro_txt = [
            'bool process_record_user(uint16_t keycode, keyrecord_t *record) {',
            '    if (record->event.pressed) {',
            '        switch (keycode) {',
        ]

        for i, macro_array in enumerate(keymap_json['macros']):
            macro = []
            for macro_fragment in macro_array:
                if isinstance(macro_fragment, str):
                    macro.append('"' + macro_fragment.replace('"', r'\"') + '"')

                elif isinstance(macro_fragment, dict):
                    newstring = []

                    if macro_fragment['action'] == 'delay':
                        newstring.append(f"SS_DELAY({macro_fragment['duration']})")

                    elif macro_fragment['action'] == 'beep':
                        newstring.append(r'"\a"')

                    elif macro_fragment['action'] == 'tap' and len(macro_fragment['keycodes']) > 1:
                        last_keycode = macro_fragment['keycodes'].pop()

                        for keycode in macro_fragment['keycodes']:
                            newstring.append(f'SS_DOWN(X_{keycode})')

                        newstring.append(f'SS_TAP(X_{last_keycode})')

                        for keycode in reversed(macro_fragment['keycodes']):
                            newstring.append(f'SS_UP(X_{keycode})')

                    else:
                        for keycode in macro_fragment['keycodes']:
                            newstring.append(f"SS_{macro_fragment['action'].upper()}(X_{keycode})")

                    macro.append(''.join(newstring))

            macro_txt.append(f'            case MACRO_{i}:')
            macro_txt.append(f'                SEND_STRING({"".join(macro)});')
            macro_txt.append('                return false;')

        macro_txt.append('        }')
        macro_txt.append('    }')
        macro_txt.append('\n    return true;')
        macro_txt.append('};')
        macro_txt.append('')

        new_keymap = '\n'.join((new_keymap, *macro_txt))

    if keymap_json.get('host_language'):
        new_keymap = new_keymap.replace('__INCLUDES__', f'#include "keymap_{keymap_json["host_language"]}.h"\n#include "sendstring_{keymap_json["host_language"]}.h"\n')
    else:
        new_keymap = new_keymap.replace('__INCLUDES__', '')

    return new_keymap


def write_file(keymap_filename, keymap_content):
    keymap_filename.parent.mkdir(parents=True, exist_ok=True)
    keymap_filename.write_text(keymap_content)

    cli.log.info('Wrote keymap to {fg_cyan}%s', keymap_filename)

    return keymap_filename


def write_json(keyboard, keymap, layout, layers, macros=None):
    """Generate the `keymap.json` and write it to disk.

    Returns the filename written to.

    Args:
        keyboard
            The name of the keyboard

        keymap
            The name of the keymap

        layout
            The LAYOUT macro this keymap uses.

        layers
            An array of arrays describing the keymap. Each item in the inner array should be a string that is a valid QMK keycode.
    """
    keymap_json = generate_json(keyboard, keymap, layout, layers, macros=None)
    keymap_content = json.dumps(keymap_json)
    keymap_file = qmk.path.keymap(keyboard) / keymap / 'keymap.json'

    return write_file(keymap_file, keymap_content)


def write(keymap_json):
    """Generate the `keymap.c` and write it to disk.

    Returns the filename written to.

    `keymap_json` should be a dict with the following keys:
        keyboard
            The name of the keyboard

        keymap
            The name of the keymap

        layout
            The LAYOUT macro this keymap uses.

        layers
            An array of arrays describing the keymap. Each item in the inner array should be a string that is a valid QMK keycode.

        macros
            A list of macros for this keymap.
    """
    keymap_content = generate_c(keymap_json)
    keymap_file = qmk.path.keymap(keymap_json['keyboard']) / keymap_json['keymap'] / 'keymap.c'

    return write_file(keymap_file, keymap_content)


def locate_keymap(keyboard, keymap):
    """Returns the path to a keymap for a specific keyboard.
    """
    if not qmk.path.is_keyboard(keyboard):
        raise KeyError('Invalid keyboard: ' + repr(keyboard))

    # Check the keyboard folder first, last match wins
    checked_dirs = ''
    keymap_path = ''

    for dir in keyboard.split('/'):
        if checked_dirs:
            checked_dirs = '/'.join((checked_dirs, dir))
        else:
            checked_dirs = dir

        keymap_dir = Path('keyboards') / checked_dirs / 'keymaps'

        if (keymap_dir / keymap / 'keymap.c').exists():
            keymap_path = keymap_dir / keymap / 'keymap.c'
        if (keymap_dir / keymap / 'keymap.json').exists():
            keymap_path = keymap_dir / keymap / 'keymap.json'

    if keymap_path:
        return keymap_path

    # Check community layouts as a fallback
    rules = rules_mk(keyboard)

    if "LAYOUTS" in rules:
        for layout in rules["LAYOUTS"].split():
            community_layout = Path('layouts/community') / layout / keymap
            if community_layout.exists():
                if (community_layout / 'keymap.json').exists():
                    return community_layout / 'keymap.json'
                if (community_layout / 'keymap.c').exists():
                    return community_layout / 'keymap.c'


def list_keymaps(keyboard, c=True, json=True, additional_files=None, fullpath=False):
    """List the available keymaps for a keyboard.

    Args:
        keyboard
            The keyboards full name with vendor and revision if necessary, example: clueboard/66/rev3

        c
            When true include `keymap.c` keymaps.

        json
            When true include `keymap.json` keymaps.

        additional_files
            A sequence of additional filenames to check against to determine if a directory is a keymap. All files must exist for a match to happen. For example, if you want to match a C keymap with both a `config.h` and `rules.mk` file: `is_keymap_dir(keymap_dir, json=False, additional_files=['config.h', 'rules.mk'])`

        fullpath
            When set to True the full path of the keymap relative to the `qmk_firmware` root will be provided.

    Returns:
        a sorted list of valid keymap names.
    """
    # parse all the rules.mk files for the keyboard
    rules = rules_mk(keyboard)
    names = set()

    if rules:
        keyboards_dir = Path('keyboards')
        kb_path = keyboards_dir / keyboard

        # walk up the directory tree until keyboards_dir
        # and collect all directories' name with keymap.c file in it
        while kb_path != keyboards_dir:
            keymaps_dir = kb_path / "keymaps"

            if keymaps_dir.is_dir():
                for keymap in keymaps_dir.iterdir():
                    if is_keymap_dir(keymap, c, json, additional_files):
                        keymap = keymap if fullpath else keymap.name
                        names.add(keymap)

            kb_path = kb_path.parent

        # if community layouts are supported, get them
        if "LAYOUTS" in rules:
            for layout in rules["LAYOUTS"].split():
                cl_path = Path('layouts/community') / layout
                if cl_path.is_dir():
                    for keymap in cl_path.iterdir():
                        if is_keymap_dir(keymap, c, json, additional_files):
                            keymap = keymap if fullpath else keymap.name
                            names.add(keymap)

    return sorted(names)


def _c_preprocess(path, stdin=DEVNULL):
    """ Run a file through the C pre-processor

    Args:
        path: path of the keymap.c file (set None to use stdin)
        stdin: stdin pipe (e.g. sys.stdin)

    Returns:
        the stdout of the pre-processor
    """
    cmd = ['cpp', str(path)] if path else ['cpp']
    pre_processed_keymap = cli.run(cmd, stdin=stdin)
    if 'fatal error' in pre_processed_keymap.stderr:
        for line in pre_processed_keymap.stderr.split('\n'):
            if 'fatal error' in line:
                raise (CppError(line))
    return pre_processed_keymap.stdout


def _get_layers(keymap):  # noqa C901 : until someone has a good idea how to simplify/split up this code
    """ Find the layers in a keymap.c file.

    Args:
        keymap: the content of the keymap.c file

    Returns:
        a dictionary containing the parsed keymap
    """
    layers = list()
    opening_braces = '({['
    closing_braces = ')}]'
    keymap_certainty = brace_depth = 0
    is_keymap = is_layer = is_adv_kc = False
    layer = dict(name=False, layout=False, keycodes=list())
    for line in lex(keymap, CLexer()):
        if line[0] is Token.Name:
            if is_keymap:
                # If we are inside the keymap array
                # we know the keymap's name and the layout macro will come,
                # followed by the keycodes
                if not layer['name']:
                    if line[1].startswith('LAYOUT') or line[1].startswith('KEYMAP'):
                        # This can happen if the keymap array only has one layer,
                        # for macropads and such
                        layer['name'] = '0'
                        layer['layout'] = line[1]
                    else:
                        layer['name'] = line[1]
                elif not layer['layout']:
                    layer['layout'] = line[1]
                elif is_layer:
                    # If we are inside a layout macro,
                    # collect all keycodes
                    if line[1] == '_______':
                        kc = 'KC_TRNS'
                    elif line[1] == 'XXXXXXX':
                        kc = 'KC_NO'
                    else:
                        kc = line[1]
                    if is_adv_kc:
                        # If we are inside an advanced keycode
                        # collect everything and hope the user
                        # knew what he/she was doing
                        layer['keycodes'][-1] += kc
                    else:
                        layer['keycodes'].append(kc)

        # The keymaps array's signature:
        # const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS]
        #
        # Only if we've found all 6 keywords in this specific order
        # can we know for sure that we are inside the keymaps array
            elif line[1] == 'PROGMEM' and keymap_certainty == 2:
                keymap_certainty = 3
            elif line[1] == 'keymaps' and keymap_certainty == 3:
                keymap_certainty = 4
            elif line[1] == 'MATRIX_ROWS' and keymap_certainty == 4:
                keymap_certainty = 5
            elif line[1] == 'MATRIX_COLS' and keymap_certainty == 5:
                keymap_certainty = 6
        elif line[0] is Token.Keyword:
            if line[1] == 'const' and keymap_certainty == 0:
                keymap_certainty = 1
        elif line[0] is Token.Keyword.Type:
            if line[1] == 'uint16_t' and keymap_certainty == 1:
                keymap_certainty = 2
        elif line[0] is Token.Punctuation:
            if line[1] in opening_braces:
                brace_depth += 1
                if is_keymap:
                    if is_layer:
                        # We found the beginning of a non-basic keycode
                        is_adv_kc = True
                        layer['keycodes'][-1] += line[1]
                    elif line[1] == '(' and brace_depth == 2:
                        # We found the beginning of a layer
                        is_layer = True
                elif line[1] == '{' and keymap_certainty == 6:
                    # We found the beginning of the keymaps array
                    is_keymap = True
            elif line[1] in closing_braces:
                brace_depth -= 1
                if is_keymap:
                    if is_adv_kc:
                        layer['keycodes'][-1] += line[1]
                        if brace_depth == 2:
                            # We found the end of a non-basic keycode
                            is_adv_kc = False
                    elif line[1] == ')' and brace_depth == 1:
                        # We found the end of a layer
                        is_layer = False
                        layers.append(layer)
                        layer = dict(name=False, layout=False, keycodes=list())
                    elif line[1] == '}' and brace_depth == 0:
                        # We found the end of the keymaps array
                        is_keymap = False
                        keymap_certainty = 0
            elif is_adv_kc:
                # Advanced keycodes can contain other punctuation
                # e.g.: MT(MOD_LCTL | MOD_LSFT, KC_ESC)
                layer['keycodes'][-1] += line[1]

        elif line[0] is Token.Literal.Number.Integer and is_keymap and not is_adv_kc:
            # If the pre-processor finds the 'meaning' of the layer names,
            # they will be numbers
            if not layer['name']:
                layer['name'] = line[1]

        else:
            # We only care about
            # operators and such if we
            # are inside an advanced keycode
            # e.g.: MT(MOD_LCTL | MOD_LSFT, KC_ESC)
            if is_adv_kc:
                layer['keycodes'][-1] += line[1]

    return layers


def parse_keymap_c(keymap_file, use_cpp=True):
    """ Parse a keymap.c file.

    Currently only cares about the keymaps array.

    Args:
        keymap_file: path of the keymap.c file (or '-' to use stdin)

        use_cpp: if True, pre-process the file with the C pre-processor

    Returns:
        a dictionary containing the parsed keymap
    """
    if keymap_file == '-':
        if use_cpp:
            keymap_file = _c_preprocess(None, sys.stdin)
        else:
            keymap_file = sys.stdin.read()
    else:
        if use_cpp:
            keymap_file = _c_preprocess(keymap_file)
        else:
            keymap_file = keymap_file.read_text(encoding='utf-8')

    keymap = dict()
    keymap['layers'] = _get_layers(keymap_file)
    return keymap


def c2json(keyboard, keymap, keymap_file, use_cpp=True):
    """ Convert keymap.c to keymap.json

    Args:
        keyboard: The name of the keyboard

        keymap: The name of the keymap

        layout: The LAYOUT macro this keymap uses.

        keymap_file: path of the keymap.c file

        use_cpp: if True, pre-process the file with the C pre-processor

    Returns:
        a dictionary in keymap.json format
    """
    keymap_json = parse_keymap_c(keymap_file, use_cpp)

    dirty_layers = keymap_json.pop('layers', None)
    keymap_json['layers'] = list()
    for layer in dirty_layers:
        layer.pop('name')
        layout = layer.pop('layout')
        if not keymap_json.get('layout', False):
            keymap_json['layout'] = layout
        keymap_json['layers'].append(layer.pop('keycodes'))

    keymap_json['keyboard'] = keyboard
    keymap_json['keymap'] = keymap
    return keymap_json
