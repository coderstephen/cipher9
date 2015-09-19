#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <ostream>
#include <string>
#include <tuple>
#include <unistd.h>
#include "AlphabeticAnalyzer.hpp"
#include "CaesarCipher.hpp"
#include "Cipher9.hpp"
#include "Dictionary.hpp"
#include "SubstitutionCipher.hpp"

using namespace std;


Cipher9::Cipher9(int argc, char** argv)
{
    // Parse the given arguments.
    int c;
    opterr = 0;

    while ((c = getopt(argc, argv, "ac:def:hk:p")) != -1) {
        switch (c) {
            case 'a':
                doAnalyze = true;
                break;
            case 'c':
                cipherName = new string(optarg);
                break;
            case 'd':
                doDecrypt = true;
                break;
            case 'e':
                doEncrypt = true;
                break;
            case 'f':
                fileName = new string(optarg);
                break;
            case 'h':
                doHelp = true;
                break;
            case 'k':
                key = new string(optarg);
                break;
            case 'p':
                printKey = true;
                break;
            case '?':
                doHelp = true;
                if (optopt == 'c' || optopt == 'f' || optopt == 'k') {
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
    cout << "Usage: cipher9 [-a|-d|-e] [OPTION]...\n\n"
            "Reads cipher text from stdin and attempts to crack it, outputting\n"
            "the plain text. Default cipher used is \"caesar\". Specify another\n"
            "cipher to use with `-c'.\n\n"
            "  -a            Analyze the input string and print the letter frequencies.\n"
            "  -c [CIPHER]   Specify the cipher to use.\n"
            "  -d            Decrypt the input text instead. Use with `-k'.\n"
            "  -e            Encrypt the input text instead. Use with `-k'.\n"
            "  -f [FILE]     Specify a file to read input from instead of stdin.\n"
            "  -h            Show this help message.\n"
            "  -k [KEY]      Specify the integer key to use.\n"
            "  -p            Print the cracked key along with the source text.\n";
}

void Cipher9::run()
{
    if (doHelp) {
        printUsage();
        return;
    }

    string inputText;

    // Read input from the given file.
    if (fileName != NULL) {
        ifstream file(fileName->c_str());
        istream_iterator<char> it(file);
        istream_iterator<char> end;
        inputText = string(it, end);
        file.close();
    } else {
        // Read the text to parse from stdin.
        cin >> noskipws;
        istream_iterator<char> it(cin);
        istream_iterator<char> end;
        inputText = string(it, end);
    }

    // Analyze the input.
    if (doAnalyze) {
        runAnalysis(inputText);
    } else {
        runCipher(inputText);
    }
}

void Cipher9::runCipher(string inputText)
{
    string outputText;

    if (cipherName == NULL) {
        // Create a dictionary and a Caesar cipher.
        Dictionary* dict = new Dictionary();
        CaesarCipher* cipher = new CaesarCipher(dict);

        int key = atoi(this->key->c_str());

        if (doEncrypt) {
            outputText = cipher->encrypt(key, inputText);
        } else if (doDecrypt) {
            outputText = cipher->decrypt(key, inputText);
        } else {
            tuple<int, string> result = cipher->crack(inputText);
            key = get<0>(result);
            outputText = get<1>(result);
        }
    }

    else if (*cipherName == "sub") {
        SubstitutionCipher* cipher = new SubstitutionCipher();

        if (doEncrypt) {
            outputText = cipher->encrypt(*key, inputText);
        } else if (doDecrypt) {
            outputText = cipher->decrypt(*key, inputText);
        }
    }

    // Print the result.
    if (printKey) {
        cout << "Key: " << key << endl << "Text: ";
    }
    cout << outputText;
}

void Cipher9::runAnalysis(string inputText)
{
    AlphabeticAnalyzer analyzer;

    tuple<map<char, unsigned int>, unsigned int> result = analyzer.analyze(inputText);
    map<char, unsigned int> frequencies = get<0>(result);
    float ratio;
    int graphLength;

    // Loop over each letter frequency result and display the results.
    for (map<char, unsigned int>::iterator it = frequencies.begin(); it != frequencies.end(); ++it) {
        cout << it->first << setw(6) << it->second << " ";

        // Display a bar graph relative to the total count.
        ratio = (float)it->second / (float)get<1>(result);
        graphLength = (int)(ratio * 30);
        for (int i = 0; i < graphLength; ++i) {
            cout << "=";
        }
        cout << endl;
    }
    cout << endl;

    // Display digram frequencies.
    map<string, unsigned int> digrams = analyzer.digrams(inputText);
    for (map<string, unsigned int>::iterator it = digrams.begin(); it != digrams.end(); ++it) {
        cout << it->first << " " << setw(6) << it->second << endl;
    }
}
