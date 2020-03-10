"""Functions that help you work with QMK keymaps.
"""
import os
from pathlib import Path
import shutil
import re
import math

import qmk.path
import qmk.makefile
from qmk.constants import DYNAMIC_KEYMAP_EEPROM_SIZE, VIA_DEFAULT_NUMBER_OF_LAYERS
from qmk.errors import KeymapAlreadyExistsError, NoSuchKeyboardError


# The `keymap.c` template to use when a keyboard doesn't have its own
DEFAULT_KEYMAP_C = """#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by QMK CLI. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
__KEYMAP_GOES_HERE__
};
"""


def template(keyboard):
    """Returns the `keymap.c` template for a keyboard.

    If a template exists in `keyboards/<keyboard>/templates/keymap.c` that
    text will be used instead of `DEFAULT_KEYMAP_C`.

    Args:
        keyboard
            The keyboard to return a template for.
    """
    template_file = Path('keyboards/%s/templates/keymap.c' % keyboard)

    if template_file.exists():
        return template_file.read_text()

    return DEFAULT_KEYMAP_C


def generate(keyboard, layout, layers):
    """Returns a keymap.c for the specified keyboard, layout, and layers.

    Args:
        keyboard
            The name of the keyboard

        layout
            The LAYOUT macro this keymap uses.

        layers
            An array of arrays describing the keymap. Each item in the inner array should be a string that is a valid QMK keycode.
    """
    layer_txt = []
    for layer_num, layer in enumerate(layers):
        if layer_num != 0:
            layer_txt[-1] = layer_txt[-1] + ','
        layer_keys = ', '.join(layer)
        layer_txt.append('\t[%s] = %s(%s)' % (layer_num, layout, layer_keys))

    keymap = '\n'.join(layer_txt)
    keymap_c = template(keyboard)

    return keymap_c.replace('__KEYMAP_GOES_HERE__', keymap)


def copy_default(keyboard, keymap, keymap_only=False):
    """
    Create user directory with default keymap files

    Args:
        keyboard
            The name of the keyboard

        keymap
            The name of the new keymap

        keymap_only
            If 'True', only copy the 'keymap.c' file

    Raises:
        FileExistsError: if keymap_only and the keymap dir already exists
    """
    keymap_path = qmk.path.keymap(keyboard)
    keymap_path_default = keymap_path / 'default'
    keymap_path_new = keymap_path / keymap
    if keymap_only:
        keymap_path_new.mkdir()
        shutil.copy(str(keymap_path_default / 'keymap.c'), str(keymap_path_new / 'keymap.c'), follow_symlinks=True)
    else:
        shutil.copytree(str(keymap_path_default), str(keymap_path_new), symlinks=True)


def via_keymap(keyboard):
    """ Create a new keymap for VIA support

    Args:
        keyboard
            The name of the keyboard
    """
    default_keymap = parse(keyboard, 'default')
    config_h = parse_config_h(keyboard)
    layers = list()
    # Use the default keymap's first layer as first layer
    layers.append([kc if kc.startswith('KC_') else 'KC_NO' for kc in default_keymap['layers'][0]['keycodes']])
    # Create empty layer
    empty_layer = ['KC_NO'] * len(default_keymap['layers'][0]['keycodes'])
    # Calculate how many layers can be used with the given keyboard
    recommended_layer_number = math.floor(DYNAMIC_KEYMAP_EEPROM_SIZE / (2 * int(config_h['rows']) * int(config_h['cols'])))
    if recommended_layer_number > VIA_DEFAULT_NUMBER_OF_LAYERS:
        recommended_layer_number = VIA_DEFAULT_NUMBER_OF_LAYERS
    # Use the empty layer to fill up the keymaps array
    for i in range(1, recommended_layer_number):
        layers.append(empty_layer)
    layout = 'LAYOUT'
    if default_keymap['layers'][0]['layout']:
        layout += '_%s' % default_keymap['layers'][0]['layout']
    write(keyboard, 'via', layout, layers)
    if recommended_layer_number != VIA_DEFAULT_NUMBER_OF_LAYERS:
        write_config_h(keyboard, ['DYNAMIC_KEYMAP_LAYER_COUNT %s' % recommended_layer_number], 'via')

    rules_mk = Path(qmk.path.keymap(keyboard) / 'via' / 'rules.mk')
    rules_mk.touch()
    via_rules = """VIA_ENABLE = yes
LTO_ENABLE = yes
# These features are not (yet) supported by VIA
LEADER_ENABLE = no
FAUXCLICKY_ENABLE = no
MIDI_ENABLE = no
BLUETOOTH_ENABLE = no
KEY_LOCK_ENABLE = no
TERMINAL_ENABLE = no
MOUSEKEY_ENABLE = no
"""
    rules_mk.write_text(via_rules)


def write(keyboard, keymap, layout, layers):
    """Generate the `keymap.c` and write it to disk.

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
    keymap_file = qmk.path.keymap(keyboard) / keymap / 'keymap.c'
    if keymap_file.exists():
        raise KeymapAlreadyExistsError('The %s keymap for %s already exists!' % (keymap, keyboard))
    keymap_c = generate(keyboard, layout, layers)

    keymap_file.parent.mkdir(parents=True, exist_ok=True)
    keymap_file.write_text(keymap_c)

    return keymap_file


def list_keymaps(keyboard_name):
    """ List the available keymaps for a keyboard.

    Args:
        keyboard_name: the keyboards full name with vendor and revision if necessary, example: clueboard/66/rev3

    Returns:
        a set with the names of the available keymaps
    """
    # parse all the rules.mk files for the keyboard
    rules_mk = qmk.makefile.get_rules_mk(keyboard_name)
    names = set()

    if rules_mk:
        # qmk_firmware/keyboards
        keyboards_dir = Path.cwd() / "keyboards"
        # path to the keyboard's directory
        kb_path = keyboards_dir / keyboard_name
        # walk up the directory tree until keyboards_dir
        # and collect all directories' name with keymap.c file in it
        while kb_path != keyboards_dir:
            keymaps_dir = kb_path / "keymaps"
            if keymaps_dir.exists():
                names = names.union([keymap for keymap in os.listdir(str(keymaps_dir)) if (keymaps_dir / keymap / "keymap.c").is_file()])
            kb_path = kb_path.parent

        # if community layouts are supported, get them
        if "LAYOUTS" in rules_mk:
            for layout in rules_mk["LAYOUTS"].split():
                cl_path = Path.cwd() / "layouts" / "community" / layout
                if cl_path.exists():
                    names = names.union([keymap for keymap in os.listdir(str(cl_path)) if (cl_path / keymap / "keymap.c").is_file()])

    return sorted(names)


def parse(keyboard, keymap):
    """ Parse a 'keymap.c' file

    Args:
        keyboard
            The name of the keyboard

        keymap
            The name of the keymap

    Returns:
        A dictionary with the following keys:
            layers: The layers in the keymap
    """
    keymap_file = (qmk.path.keymap(keyboard) / keymap / 'keymap.c').read_text()
    keymap = dict()
    # Capture group 1: Name of the layout
    # Capture group 2: Macro's name (optional)
    # Capture group 3: Keycodes
    found_layers = re.findall(r'\s*\[(\w+)\]\s*=\s*LAYOUT(?:_(\w+))?\s*\((.*?)\)(?!,\s+KC)', keymap_file, re.S)
    if found_layers:
        layers = list()
        for layer in found_layers:
            layers.append(dict(name=layer[0], layout=layer[1], keycodes=[kc.strip() for kc in layer[2].split(',')]))
        keymap['layers'] = layers

    return keymap


def parse_config_h(keyboard, keymap = None):
    if keymap:
        config_h_file = Path('keyboards') / keyboard / 'keymaps' / keymap / 'config.h'
    else:
        config_h_file = Path('keyboards') / keyboard / 'config.h'
    if config_h_file.exists():
        config_h = config_h_file.read_text().split('\n')
        content = dict(name = "", vid = "", pid = "", rows = "", cols = "")
        for line in config_h:
            l = line.strip().split()
            if len(l) == 3 and l[0].startswith('#'):
                if not content['vid'] and l[1] == 'VENDOR_ID':
                    content['vid'] = l[2]
                elif not content['pid'] and l[1] == 'PRODUCT_ID':
                    content['pid'] = l[2]
                elif not content['rows'] and l[1] == 'MATRIX_ROWS':
                    content['rows'] = l[2]
                elif not content['cols'] and l[1] == 'MATRIX_COLS':
                    content['cols'] = l[2]
                elif l[1] == 'MANUFACTURER':
                    content['name'] = ('%s %s' % (l[2], content['name'])).strip()
                elif l[1] == 'PRODUCT':
                    content['name'] = ('%s %s' % (content['name'], l[2])).strip()
        return content
    else:
        raise NoSuchKeyboardError


def write_config_h(keyboard, content, keymap = None):
    if keymap:
        config_h_file = Path('keyboards') / keyboard / 'keymaps' / keymap / 'config.h'
    else:
        config_h_file = Path('keyboards') / keyboard / 'config.h'
    if not config_h_file.exists():
        if isinstance(content, list):
            content = ['#define %s' % i for i in content]
            content.insert(0, '#pragma once')
            config_h_file.write_text('\n'.join(content))
