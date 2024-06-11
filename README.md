# Linenoise-Arduino

A Linenoise port for Aruino Serial port object I/O.

Linenoise is an interactive line editor with history and optional support for tab key completion.

See the original [README](Linenoise/src/README.markdown) for more details about Linenoise. It is provided in the [src](Linenoise/src/) folder.

## Changes from the original
- Rename to .cpp to use Arduino Serial object for I/O
- Remove some of the terminal environment detection which is not applicable for a small embedded environment
- Tab character is filtered except for completion
- Added Home and End key escape sequences to navigate to the start and end of the line
- Default maximum history length changed to 20
- Maximum line length changed to 256

## How to use
1. Copy the [Linenoise](Linenoise/) folder to your Arduino libraries.
2. #include <Linenoise.h> in your sketch.
2. Use the `linenoise` function to input a line of text from the Serial port. See the [blocking example](Linenoise/examples/blocking/blocking.ino) sketch.
4. Use a terminal emulator with ANSI/VT100 escape sequence support.

## Terminal Software configuration
- Make sure VT100/VT101/VT102 or ANSI escape sequences are enabled.
- Configure the Enter key to send a carriage return (CR).
- Configure new line receive as line-feed (LF) (or implicit CR for every LF).
- Configure the Backspace key as ASCII character 127 or CTRL-H.
- The Delete key must send an escape sequence otherwise it will probably behave like Backspace.

## Windows serial port Terminal Emulators with ANSI/VT100
1. [Tera Term](https://teratermproject.github.io/index-en.html) - Recommended. In Setup/Keyboard uncheck the DEL key options.
2. [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/) - Under Terminal options, enable implicit CR in every LF.
3. [KiTTY](https://github.com/cyd01/KiTTY) (PuTTY alternate) - Under Terminal options, enable implicit CR in every LF.
4. [Realterm](https://realterm.sourceforge.io/) (may trigger virus warning, is it safe?)
