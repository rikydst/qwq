#!/bin/bash

read -rd '' USAGE << EOF
Usage: $0
       $0 keyboard:keymap[:target]
       $0 keyboard [keymap] [target]
EOF

# Check preconditions
if [[ $* =~ "--help" ]]; then
    echo "$USAGE"
    exit 0
elif [[ $# -gt 3 ]]; then
    echo "$USAGE"
    exit 1
elif [[ ! $(command -v docker) ]]; then
    echo "Error: docker not found" >&2
    echo "See https://docs.docker.com/install/#supported-platforms for installation instructions" >&2
    exit 2
fi

# Determine arguments
if [[ $# -eq 0 ]]; then
    # Empty form
    read -rp "keyboard=" keyboard
    [[ -n $keyboard ]] && read -rp "keymap=" keymap
    [[ -n $keymap   ]] && read -rp "target=" target
elif [[ $# -eq 1 && $1 == *":"* ]]; then
    # keyboard:keymap[:target] form
    IFS=':' read -ra args <<< "$1"
    if [[ ${#args[@]} -gt 3 ]]; then
        echo "$USAGE"
        exit 1
    fi
    keyboard=${args[0]}
    keymap=${args[1]}
    target=${args[2]}
else
    # keyboard [keymap] [target] form
    keyboard=$1
    keymap=$2
    target=$3
fi
dir=$(pwd -W 2>/dev/null) || dir=$PWD  # Use Windows path if on Windows

# Run container and build firmware
docker run --rm -v "$dir:/qmk:rw" qmkfm/qmk_firmware \
    make "$keyboard${keymap:+:$keymap}${target:+:$target}"
