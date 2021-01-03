"""Used by the make system to generate layouts.h from info.json.
"""
from milc import cli

from qmk.constants import COL_LETTERS, ROW_LETTERS
from qmk.decorators import automagic_keyboard, automagic_keymap
from qmk.info import info_json
from qmk.path import is_keyboard, normpath

usb_properties = {
    'vid': 'VENDOR_ID',
    'pid': 'PRODUCT_ID',
    'device_ver': 'DEVICE_VER',
}


@cli.argument('-o', '--output', arg_only=True, type=normpath, help='File to write to')
@cli.argument('-q', '--quiet', arg_only=True, action='store_true', help="Quiet mode, only output error messages")
@cli.argument('-kb', '--keyboard', help='Keyboard to generate config.h for.')
@cli.subcommand('Used by the make system to generate layouts.h from info.json', hidden=True)
@automagic_keyboard
@automagic_keymap
def generate_layouts(cli):
    """Generates the layouts.h file.
    """
    # Determine our keyboard(s)
    if not cli.config.generate_layouts.keyboard:
        cli.log.error('Missing paramater: --keyboard')
        cli.subcommands['info'].print_help()
        return False

    if not is_keyboard(cli.config.generate_layouts.keyboard):
        cli.log.error('Invalid keyboard: "%s"', cli.config.generate_layouts.keyboard)
        return False

    # Build the info.json file
    kb_info_json = info_json(cli.config.generate_layouts.keyboard)

    # Build the layouts.h file.
    layouts_h_lines = ['/* This file was generated by `qmk generate-layouts`. Do not edit or copy.' ' */', '', '#pragma once']

    if 'matrix_pins' in kb_info_json:
        if 'direct' in kb_info_json['matrix_pins']:
            col_num = len(kb_info_json['matrix_pins']['direct'][0])
            row_num = len(kb_info_json['matrix_pins']['direct'])
        elif 'cols' in kb_info_json['matrix_pins'] and 'rows' in kb_info_json['matrix_pins']:
            col_num = len(kb_info_json['matrix_pins']['cols'])
            row_num = len(kb_info_json['matrix_pins']['rows'])
        else:
            cli.log.error('%s: Invalid matrix config.', cli.config.generate_layouts.keyboard)
            return False

    for layout_name in kb_info_json['layouts']:
        if kb_info_json['layouts'][layout_name]['c_macro']:
            continue

        layout_keys = []
        layout_matrix = [['KC_NO' for i in range(col_num)] for i in range(row_num)]

        for i, key in enumerate(kb_info_json['layouts'][layout_name]['layout']):
            row = key['matrix'][0]
            col = key['matrix'][1]
            identifier = 'k%s%s' % (ROW_LETTERS[row], COL_LETTERS[col])

            try:
                layout_matrix[row][col] = identifier
                layout_keys.append(identifier)
            except IndexError:
                key_name = key.get('label', identifier)
                cli.log.error('Matrix data out of bounds for layout %s at index %s (%s): %s, %s', layout_name, i, key_name, row, col)
                return False

        layouts_h_lines.append('')
        layouts_h_lines.append('#define %s(%s) {\\' % (layout_name, ', '.join(layout_keys)))

        rows = ', \\\n'.join(['\t {' + ', '.join(row) + '}' for row in layout_matrix])
        rows += ' \\'
        layouts_h_lines.append(rows)
        layouts_h_lines.append('}')

    # Show the results
    layouts_h = '\n'.join(layouts_h_lines) + '\n'

    if cli.args.output:
        cli.args.output.parent.mkdir(parents=True, exist_ok=True)
        if cli.args.output.exists():
            cli.args.output.replace(cli.args.output.name + '.bak')
        cli.args.output.write_text(layouts_h)

        if not cli.args.quiet:
            cli.log.info('Wrote info_config.h to %s.', cli.args.output)

    else:
        print(layouts_h)
