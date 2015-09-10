# cipher9
A little code breaker program for experimentation. Part of a class project.

Reads cipher text from stdin and attempts to crack it, outputting
the plain text. Default cipher used is "caesar". Specify another
cipher to use with `-c`.

## Usage
    cipher9 [OPTION]...

- `-c [CIPHER]`: Specify the cipher to use.
- `-d`:          Decrypt the input text instead. Use with `-k'
- `-e`:          Encrypt the input text instead. Use with `-k'
- `-h`:          Show this help message.
- `-k [KEY]`:    Specify the integer key to use.
- `-p`:          Print the cracked key along with the source text.

## License
This program is licensed under the [MIT license](https://opensource.org/licenses/MIT). See the [LICENSE](LICENSE) file for details.
