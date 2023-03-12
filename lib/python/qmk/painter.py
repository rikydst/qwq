"""Functions that help us work with Quantum Painter's file formats.
"""
import math
import re
from string import Template
from PIL import Image, ImageOps

# The list of valid formats Quantum Painter supports
valid_formats = {
    'rgb888': {
        'image_format': 'IMAGE_FORMAT_RGB888',
        'bpp': 24,
        'has_palette': False,
        'num_colors': 16777216,
        'image_format_byte': 0x09,  # see qp_internal_formats.h
    },
    'rgb565': {
        'image_format': 'IMAGE_FORMAT_RGB565',
        'bpp': 16,
        'has_palette': False,
        'num_colors': 65536,
        'image_format_byte': 0x08,  # see qp_internal_formats.h
    },
    'pal256': {
        'image_format': 'IMAGE_FORMAT_PALETTE',
        'bpp': 8,
        'has_palette': True,
        'num_colors': 256,
        'image_format_byte': 0x07,  # see qp_internal_formats.h
    },
    'pal16': {
        'image_format': 'IMAGE_FORMAT_PALETTE',
        'bpp': 4,
        'has_palette': True,
        'num_colors': 16,
        'image_format_byte': 0x06,  # see qp_internal_formats.h
    },
    'pal4': {
        'image_format': 'IMAGE_FORMAT_PALETTE',
        'bpp': 2,
        'has_palette': True,
        'num_colors': 4,
        'image_format_byte': 0x05,  # see qp_internal_formats.h
    },
    'pal2': {
        'image_format': 'IMAGE_FORMAT_PALETTE',
        'bpp': 1,
        'has_palette': True,
        'num_colors': 2,
        'image_format_byte': 0x04,  # see qp_internal_formats.h
    },
    'mono256': {
        'image_format': 'IMAGE_FORMAT_GRAYSCALE',
        'bpp': 8,
        'has_palette': False,
        'num_colors': 256,
        'image_format_byte': 0x03,  # see qp_internal_formats.h
    },
    'mono16': {
        'image_format': 'IMAGE_FORMAT_GRAYSCALE',
        'bpp': 4,
        'has_palette': False,
        'num_colors': 16,
        'image_format_byte': 0x02,  # see qp_internal_formats.h
    },
    'mono4': {
        'image_format': 'IMAGE_FORMAT_GRAYSCALE',
        'bpp': 2,
        'has_palette': False,
        'num_colors': 4,
        'image_format_byte': 0x01,  # see qp_internal_formats.h
    },
    'mono2': {
        'image_format': 'IMAGE_FORMAT_GRAYSCALE',
        'bpp': 1,
        'has_palette': False,
        'num_colors': 2,
        'image_format_byte': 0x00,  # see qp_internal_formats.h
    }
}

license_template = """\
// Copyright ${year} QMK -- generated source code only, ${generated_type} retains original copyright
// SPDX-License-Identifier: GPL-2.0-or-later

// This file was auto-generated by `${generator_command}`
"""


def render_license(subs):
    license_txt = Template(license_template)
    return license_txt.substitute(subs)


header_file_template = """\
${license}
#pragma once

#include <qp.h>

extern const uint32_t ${var_prefix}_${sane_name}_length;
extern const uint8_t  ${var_prefix}_${sane_name}[${byte_count}];
"""


def render_header(subs):
    header_txt = Template(header_file_template)
    return header_txt.substitute(subs)


source_file_template = """\
${license}
#include <qp.h>

const uint32_t ${var_prefix}_${sane_name}_length = ${byte_count};

// clang-format off
const uint8_t ${var_prefix}_${sane_name}[${byte_count}] = {
${bytes_lines}
};
// clang-format on
"""


def render_source(subs):
    source_txt = Template(source_file_template)
    return source_txt.substitute(subs)


def render_bytes(bytes, newline_after=16):
    lines = ''
    for n in range(len(bytes)):
        if n % newline_after == 0 and n > 0 and n != len(bytes):
            lines = lines + "\n   "
        elif n == 0:
            lines = lines + "   "
        lines = lines + " 0x{0:02X},".format(bytes[n])
    return lines.rstrip()


def clean_output(str):
    str = re.sub(r'\r', '', str)
    str = re.sub(r'[\n]{3,}', r'\n\n', str)
    return str


def rescale_byte(val, maxval):
    """Rescales a byte value to the supplied range, i.e. [0,255] -> [0,maxval].
    """
    return int(round(val * maxval / 255.0))


def convert_requested_format(im, format):
    """Convert an image to the requested format.
    """

    # Work out the requested format
    ncolors = format["num_colors"]
    image_format = format["image_format"]

    # Work out where we're getting the bytes from
    if image_format == 'IMAGE_FORMAT_GRAYSCALE':
        # Ensure we have a valid number of colors for the palette
        if ncolors <= 0 or ncolors > 256 or (ncolors & (ncolors - 1) != 0):
            raise ValueError("Number of colors must be 2, 4, 16, or 256.")
        # If mono, convert input to grayscale, then to RGB, then grab the raw bytes corresponding to the intensity of the red channel
        im = ImageOps.grayscale(im)
        im = im.convert("RGB")
    elif image_format == 'IMAGE_FORMAT_PALETTE':
        # Ensure we have a valid number of colors for the palette
        if ncolors <= 0 or ncolors > 256 or (ncolors & (ncolors - 1) != 0):
            raise ValueError("Number of colors must be 2, 4, 16, or 256.")
        # If color, convert input to RGB, palettize based on the supplied number of colors, then get the raw palette bytes
        im = im.convert("RGB")
        im = im.convert("P", palette=Image.ADAPTIVE, colors=ncolors)
    elif image_format == 'IMAGE_FORMAT_RGB565':
        # Ensure we have a valid number of colors for the palette
        if ncolors != 65536:
            raise ValueError("Number of colors must be 65536.")
        # If color, convert input to RGB
        im = im.convert("RGB")
    elif image_format == 'IMAGE_FORMAT_RGB888':
        # Ensure we have a valid number of colors for the palette
        if ncolors != 1677216:
            raise ValueError("Number of colors must be 16777216.")
        # If color, convert input to RGB
        im = im.convert("RGB")

    return im


def rgb_to565(r, g, b):
    msb = ((r >> 3 & 0x1F) << 3) + (g >> 5 & 0x07)
    lsb = ((g >> 2 & 0x07) << 5) + (b >> 3 & 0x1F)
    return [msb, lsb]


def convert_image_bytes(im, format):
    """Convert the supplied image to the equivalent bytes required by the QMK firmware.
    """

    # Work out the requested format
    ncolors = format["num_colors"]
    image_format = format["image_format"]
    shifter = int(math.log2(ncolors))
    pixels_per_byte = int(8 / math.log2(ncolors))
    bytes_per_pixel = math.ceil(math.log2(ncolors) / 8)
    (width, height) = im.size
    if (pixels_per_byte != 0):
        expected_byte_count = ((width * height) + (pixels_per_byte - 1)) // pixels_per_byte
    else:
        expected_byte_count = width * height * bytes_per_pixel

    if image_format == 'IMAGE_FORMAT_GRAYSCALE':
        # Take the red channel
        image_bytes = im.tobytes("raw", "R")
        image_bytes_len = len(image_bytes)

        # No palette
        palette = None

        bytearray = []
        for x in range(expected_byte_count):
            byte = 0
            for n in range(pixels_per_byte):
                byte_offset = x * pixels_per_byte + n
                if byte_offset < image_bytes_len:
                    # If mono, each input byte is a grayscale [0,255] pixel -- rescale to the range we want then pack together
                    byte = byte | (rescale_byte(image_bytes[byte_offset], ncolors - 1) << int(n * shifter))
            bytearray.append(byte)

    elif image_format == 'IMAGE_FORMAT_PALETTE':
        # Convert each pixel to the palette bytes
        image_bytes = im.tobytes("raw", "P")
        image_bytes_len = len(image_bytes)

        # Export the palette
        palette = []
        pal = im.getpalette()
        for n in range(0, ncolors * 3, 3):
            palette.append((pal[n + 0], pal[n + 1], pal[n + 2]))

        bytearray = []
        for x in range(expected_byte_count):
            byte = 0
            for n in range(pixels_per_byte):
                byte_offset = x * pixels_per_byte + n
                if byte_offset < image_bytes_len:
                    # If color, each input byte is the index into the color palette -- pack them together
                    byte = byte | ((image_bytes[byte_offset] & (ncolors - 1)) << int(n * shifter))
            bytearray.append(byte)

    if image_format == 'IMAGE_FORMAT_RGB565':
        # Take the red, green, and blue channels
        red = im.tobytes("raw", "R")
        green = im.tobytes("raw", "G")
        blue = im.tobytes("raw", "B")

        # No palette
        palette = None

        bytearray = [byte for r, g, b in zip(red, green, blue) for byte in rgb_to565(r, g, b)]

    if image_format == 'IMAGE_FORMAT_RGB888':
        # Take the red, green, and blue channels
        red = im.tobytes("raw", "R")
        green = im.tobytes("raw", "G")
        blue = im.tobytes("raw", "B")

        # No palette
        palette = None

        bytearray = [byte for r, g, b in zip(red, green, blue) for byte in (r, g, b)]

    if len(bytearray) != expected_byte_count:
        raise Exception(f"Wrong byte count, was {len(bytearray)}, expected {expected_byte_count}")

    return (palette, bytearray)


def compress_bytes_qmk_rle(bytearray):
    debug_dump = False
    output = []
    temp = []
    repeat = False

    def append_byte(c):
        if debug_dump:
            print('Appending byte:', '0x{0:02X}'.format(int(c)), '=', c)
        output.append(c)

    def append_range(r):
        append_byte(127 + len(r))
        if debug_dump:
            print('Appending {0} byte(s):'.format(len(r)), '[', ', '.join(['{0:02X}'.format(e) for e in r]), ']')
        output.extend(r)

    for n in range(0, len(bytearray) + 1):
        end = True if n == len(bytearray) else False
        if not end:
            c = bytearray[n]
            temp.append(c)
            if len(temp) <= 1:
                continue

        if debug_dump:
            print('Temp buffer state {0:3d} bytes:'.format(len(temp)), '[', ', '.join(['{0:02X}'.format(e) for e in temp]), ']')

        if repeat:
            if temp[-1] != temp[-2]:
                repeat = False
            if not repeat or len(temp) == 128 or end:
                append_byte(len(temp) if end else len(temp) - 1)
                append_byte(temp[0])
                temp = [temp[-1]]
                repeat = False
        else:
            if len(temp) >= 2 and temp[-1] == temp[-2]:
                repeat = True
                if len(temp) > 2:
                    append_range(temp[0:(len(temp) - 2)])
                    temp = [temp[-1], temp[-1]]
                continue
            if len(temp) == 128 or end:
                append_range(temp)
                temp = []
                repeat = False
    return output
