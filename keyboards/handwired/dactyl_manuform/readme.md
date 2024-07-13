# Dactyl ManuForm

![Imgur](https://i.imgur.com/7y0Vbydh.jpg)  
*Pair of Dactyl ManuForm 4x6*

Forked from the [Dactyl](/keyboards/handwired/dactyl), the *Dactyl ManuForm* is a parameterized, handwired, split bodied, tented, concave key-well design that incorporates the thumb cluster from the [ManuForm](https://geekhack.org/index.php?topic=46015.0).  
The *Dactyl ManuForm* requires two development boards, one per half, which differs from the *Dactyl's* original implementation of a development board and an I/O expander. 

* Keyboard Maintainer: [Tom Short](https://github.com/tshort)
* Hardware Supported: Pro Micro development board
* Hardware Availability: [Github](https://github.com/tshort/dactyl-keyboard)

## Variants

*Dactyl ManuForms* are built in variations that cater for different row and column counts; there is no default.  

Standard key layout (per half): 
- The finger keywell bottom row has 2 keys, 1 each in ring and middle columns
- The thumb cluster has 6 keys, arranged in a staggered 2 columns by 3 rows 

Variants are denoted as `RowCount`*x*`ColumnCount`*(_`Alteration`)*

### Row
| Count | Description |
| :---: | :---: |
| 4 | Three rows, typically for alphabet and some puncuation characters, with 2 key (finger keywell) bottom row |
| 5 | As *4 row* with number row above |
| 6 | As *5 row* with function row above |

### Column
| Count | Description |
| :---: | :---: |
| 5 | A column for each finger with additional column for first finger |  
| 6 | As *5 column* with additional pinky finger column |
| 7 | As *6 column* with additional pinky column |  

### Alteration
| Code | Description | Diagram </br> *4x6 example* |
| :---: | :---: | :---: | 
| ex | **Ex**tended Bottom Row: Key count on the finger well bottom row is extended outward from the default 2 |  ![ex](https://i.imgur.com/ifhDa7Zh.png) |
| eic | **E**xtended **I**nner **C**olumn: Each half gains an additional inner column though the bottom key of said column is ommitted | ![eic](https://i.imgur.com/stuHtsXh.png) |
| exic | *ex* and *eic* combined | ![exic](https://i.imgur.com/t37nF0uh.png) |

### Legacy "5x7" variant

Is the [5x6_exic](./5x6_exic/) variant.
 
## Case Files Generator

[Dactyl Generator](https://ryanis.cool/dactyl), created by [rianadon](https://github.com/rianadon), is a web based file generator that negates having to compose case files using programming languages, which was the matter when using the original *Dactyl* and *Dactyl ManuForm* GitHub repos, by instead compiling case files based on options and parameters configured in a web front end.

Readme.md in each variant's directory will detail the required settings to reproduce the variant with the linked *Dactyl Generator*.

## Compile

Make examples for this keyboard (after setting up your build environment):

    make handwired/dactyl_manuform/4x6:default
    make handwired/dactyl_manuform/4x6_ex:default
    make handwired/dactyl_manuform/5x6_eic:default
    make handwired/dactyl_manuform/5x6_exic:default

Flashing examples for this keyboard:

    make handwired/dactyl_manuform/4x6:default:flash
    make handwired/dactyl_manuform/4x6_ex:default:flash
    make handwired/dactyl_manuform/5x6_eic:default:flash
    make handwired/dactyl_manuform/5x6_exic:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: If enabled, hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB or controller - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
