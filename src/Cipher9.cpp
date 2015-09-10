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


Cipher9::Cipher9(int argc, char** argv) : doEncrypt(false), doDecrypt(false), cipherName(NULL), key(0)
{
    // Parse the given arguments.
    parseArgs(argc, argv);

    // Read the text to parse from stdin.
    cin >> noskipws;
    istream_iterator<char> it(cin);
    istream_iterator<char> end;
    inputText = string(it, end);
}

void Cipher9::run()
{
    Dictionary* dict = new Dictionary();
    CaesarCipher* cipher = new CaesarCipher(dict);

    // Perform the specified operation on the given input text.
    if (doEncrypt) {
        cout << cipher->encrypt(key, inputText);
    } else if (doDecrypt) {
        cout << cipher->decrypt(key, inputText);
    } else {
        cout << get<1>(cipher->crack(inputText));
    }
}

void Cipher9::parseArgs(int argc, char** argv)
{
    int c;

    opterr = 0;

    while ((c = getopt(argc, argv, "dec:k:")) != -1) {
        switch (c)
        {
            case 'd':
                doDecrypt = true;
                break;
            case 'e':
                doEncrypt = true;
                break;
            case 'c':
                cipherName = new string(optarg);
                break;
            case 'k':
                key = atoi(optarg);
                break;
            case '?':
                if (optopt == 'c')
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
                return;
        }
    }
}
