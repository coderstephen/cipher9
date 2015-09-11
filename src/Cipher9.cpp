#include <cstdlib>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <string>
#include <tuple>
#include <unistd.h>
#include "CaesarCipher.hpp"
#include "Cipher9.hpp"
#include "Dictionary.hpp"

using namespace std;


Cipher9::Cipher9(int argc, char** argv)
{
    // Parse the given arguments.
    int c;
    opterr = 0;

    while ((c = getopt(argc, argv, "dehpc:k:")) != -1) {
        switch (c) {
            case 'c':
                cipherName = new string(optarg);
                break;
            case 'd':
                doDecrypt = true;
                break;
            case 'e':
                doEncrypt = true;
                break;
            case 'h':
                doHelp = true;
                break;
            case 'k':
                key = atoi(optarg);
                break;
            case 'p':
                printKey = true;
                break;
            case '?':
                doHelp = true;
                if (optopt == 'c' || optopt == 'k') {
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                } else if (isprint(optopt)) {
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                } else {
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
                }
                break;
        }
    }
}

void Cipher9::printUsage()
{
    cout << "Usage: cipher9 [OPTION]...\n\n"
            "Reads cipher text from stdin and attempts to crack it, outputting\n"
            "the plain text. Default cipher used is \"caesar\". Specify another\n"
            "cipher to use with `-c'.\n\n"
            "  -c [CIPHER]\tSpecify the cipher to use.\n"
            "  -d\t\tDecrypt the input text instead. Use with `-k'.\n"
            "  -e\t\tEncrypt the input text instead. Use with `-k'.\n"
            "  -h\t\tShow this help message.\n"
            "  -k [KEY]\tSpecify the integer key to use.\n"
            "  -p\t\tPrint the cracked key along with the source text.\n";
}

void Cipher9::run()
{
    if (doHelp) {
        printUsage();
        return;
    }

    // Read the text to parse from stdin.
    cin >> noskipws;
    istream_iterator<char> it(cin);
    istream_iterator<char> end;
    string inputText(it, end);

    string outputText;

    // Create a dictionary and a Caesar cipher.
    Dictionary* dict = new Dictionary();
    CaesarCipher* cipher = new CaesarCipher(dict);

    // Perform the specified operation on the given input text.
    if (doEncrypt) {
        outputText = cipher->encrypt(key, inputText);
    } else if (doDecrypt) {
        outputText = cipher->decrypt(key, inputText);
    } else {
        tuple<int, string> result = cipher->crack(inputText);
        key = get<0>(result);
        outputText = get<1>(result);
    }

    // Print the result.
    if (printKey) {
        cout << "Key: " << key << endl << "Text: ";
    }
    cout << outputText;
}
