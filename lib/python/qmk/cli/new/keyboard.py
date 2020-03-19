"""This script automates creating the files necessary for a new QMK keyboard.
"""
import shutil
import hashlib
import re
from qmk.constants import mcus
from qmk.keyboard import generate_pid
from qmk.questions import question

from milc import cli
from pathlib import Path
from datetime import datetime


@cli.argument('-kb', '--keyboard', help='Specify keyboard name. Example: clueboard/66')
@cli.argument('-pr', '--project', help='The human-friendly name of the keyboard. Example: Clueboard 66%%')
@cli.argument('-mcu', '--microcontroller', help='Specify the microcontroller used for the keyboard.')
@cli.argument('-u', '--username', help='Your GitHub username. Will be pasted into generated files.')
@cli.subcommand('Creates a new keyboard project.')
def new_keyboard(cli):
    """Creates a new keyboard project.
    """

    # Root path for template files
    template_root_path = Path("quantum/template")
    template_base_path = template_root_path / "base"
    year = datetime.now().year
    valid_keyboard_name = re.compile(r'^[a-z0-9][a-z0-9_/]+$')

    # Rewrites the %YEAR%, %YOUR_NAME%, %KEYBOARD% and %PID% placeholders in the
    #   new files.
    def rewrite_source(file):
        rw_file = Path(keyboard_path) / file
        file_contents = rw_file.read_text() \
            .replace("%YEAR%", str(year)) \
            .replace("%YOUR_NAME%", user_name) \
            .replace("%KEYBOARD%", str(keyboard)) \
            .replace("%FINAL_DIR%", str(final_directory)) \
            .replace("%KEYBOARD_NAME%", keyboard_name) \
            .replace("%PID%", pid) \
            .replace("%MCU%", mcu)
        rw_file.write_text(file_contents)


    if cli.args.keyboard:
        keyboard = keyboard_name = cli.args.keyboard
    else:
        # ask for user input if keyboard was not provided in the command line
        cli.echo("""What is the keyboard's project name?

    This will be the name used to compile firmware for your keyboard. The
    project name may only contain lower case letters, numbers, and the
    underscore character, and must not begin with an underscore.

    Files will be placed in `qmk_firmware/keyboards/<project_name>/`.""")
        keyboard = question("Project Name: ")
        #keyboard = Path(re.sub(r'[^a-z0-9_/]', "", keyboard.lower()))
        keyboard = Path(keyboard.lower())


    if cli.args.project:
        keyboard_name = cli.args.project
    else:
        # Ask the common name of the keyboard, if not specified by --project
        cli.echo("""What is the keyboard's common name?

    This is the name that people will use to refer to your keyboard. It should
    be something human-friendly, like \"Clueboard 66%%\" or \"Ergodox EZ\".""")
        keyboard_name = question("Name: ")


    if cli.args.microcontroller:
        mcu = cli.args.microcontroller.lower()
        for key, value in enumerate(mcus):
            if re.match( r'^' + value[0] + '$', mcu, re.I ):
                arch = value[1]
                break
        else:
            cli.log.error(mcu + " is not a valid microcontroller option.")
            options = [];
            for i in range(0, len(mcus)):
                options.append( mcus[i][0] )
            print("  Valid Options: ", ", ".join(mcu[0] for mcu in mcus) )
            exit(1)
    else:
    # Ask what microcontroller is being used
        cli.echo("Select the microcontroller used:\n")
        for i, mcu in enumerate(mcus, 1):
            cli.echo("    %s: %s (%s)", str(i).rjust(2, " "), mcu[0], mcu[1] )

        mcu = int(input("\n    Microcontroller: (1-" + str(len(mcus)) + "): "))
        # user-facing text is 1-indexed, but data is 0-indexed internally
        mcu -= 1
        arch = mcus[mcu][1]
        mcu = mcus[mcu][0]
        mcu = mcu.lower()
    # Set the path to the MCU architecture's template files
    template_arch_path = template_root_path / arch


    # (Erovia) introducing the user.name variable would probably be better
    if cli.args.username:
        user_name = cli.args.username
    elif cli.config.user.keymap:
        user_name = cli.config.user.keymap
    else:
        # Ask the user for their GitHub username
        cli.echo("""What is your GitHub username?

    This value will be pasted into the new files in copyright headers, and used
    as the listed Keyboard Maintainer in the readme file.""")
        user_name = question("GitHub Username: ")

    # generate keyboard paths
    keyboard_path = Path("keyboards") / keyboard

    # check directories
    if keyboard_path.exists():
        cli.log.error('Keyboard %s already exists!', keyboard)
        exit(1)
    # if target directory is a subdirectory (keyboard project name contains a
    #   forward slash, create the parent directory first
    elif len(keyboard.parts) > 1:
        keyboard.parent.mkdir(parents=True, exist_ok=True)
    final_directory = keyboard.name

    # create user directory with default keyboard files
    shutil.copytree(template_base_path, keyboard_path, symlinks=True)
    kb_c = keyboard_path / "keyboard.c"
    kb_h = keyboard_path / "keyboard.h"
    kb_c.rename( keyboard_path / Path(final_directory + ".c") )
    kb_h.rename( keyboard_path / Path(final_directory + ".h") )

    # copy architecture files
    shutil.copy(template_arch_path / "config.h", keyboard_path)
    shutil.copy(template_arch_path / "readme.md", keyboard_path)
    shutil.copy(template_arch_path / "rules.mk", keyboard_path)
    if arch == "ps2avrgb":
        # only ps2avrgb keyboards require this file
        shutil.copy(template_arch_path / "usbconfig.h", keyboard_path)
    if arch == "stm32":
        # STM32 MCUs need their names in uppercase
        mcu = mcu.upper()

    # rewrite the %YEAR%, %YOUR_NAME%, %KEYBOARD% and %PID% placeholders

    # generate and assign the Product ID value
    # Required before using rewrite_source()
    pid = generate_pid(keyboard_name)

    rewrite_source("config.h")
    rewrite_source("info.json")
    rewrite_source("readme.md")
    rewrite_source("rules.mk")
    rewrite_source(final_directory + ".c")
    rewrite_source(final_directory + ".h")
    rewrite_source("keymaps/default/keymap.c")
    rewrite_source("keymaps/default/config.h")
    rewrite_source("keymaps/default/readme.md")

    # end message to user
    cli.log.info("%s keyboard directory created in: %s", keyboard_name, keyboard_path)
    cli.log.info("Compile a firmware with your new keymap by typing: \n" + "qmk compile -kb %s -km default", keyboard)
