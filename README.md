# [cipher9](https://github.com/coderstephen/cipher9)
A little code breaker program for experimentation. Part of a class project.

Reads cipher text from stdin and attempts to crack it, outputting
the plain text. Default cipher used is "caesar". Specify another
cipher to use with `-c`.

## Compiling
Compilation can be done with the standard `make` build tool:

    make

The resulting binary will be placed at `bin/cipher9`.

## Usage
    cipher9 [OPTION]...

* `-a`: Analyze the input string and print the letter frequencies.
* `-c [CIPHER]` - Specify the cipher to use. Valid cipher names are:
    * `caesar`: Caesar cipher. Keys should be an integer indicating the number of letters to shift.
    * `substitute`: Monoalphabetic substitution cipher. Keys should be strings up to 26 letters long.
* `-d`:          Decrypt the input text instead. Use with `-k'
* `-e`:          Encrypt the input text instead. Use with `-k'
* `-f [FILE]`:   Specify a file to read input from instead of stdin.
* `-h`:          Show this help message.
* `-k [KEY]`:    Specify the cipher key to use. Valid key formats depend on the cipher being used.
* `-p`:          Print the cracked key along with the source text.

For example, to encrypt the string "hello world" with a Caesar cipher using the
key `7`, we can run:

    echo "hello world" | cipher9 -e -k 7

The output will be "olssv dvysk". We can crack the encrypted message by giving
cipher9 no arguments:

    echo "olssv dvysk" | cipher9

The output will be the original message, "hello world".

## License
This program is licensed under the [MIT license](https://opensource.org/licenses/MIT). See the [LICENSE](LICENSE) file for details.
