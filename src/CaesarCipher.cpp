#include <algorithm>
#include <string>
#include <sstream>
#include <tuple>
#include "CaesarCipher.hpp"
#include "Dictionary.hpp"

using namespace std;


CaesarCipher::CaesarCipher(Dictionary* dictionary)
{
    this->dictionary = dictionary;
}

string CaesarCipher::encrypt(int key, string text)
{
    for (unsigned int i = 0; i < text.length(); ++i) {
        int c = tolower(text[i]);

        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + key) % 26;
            if (c < 0) {
                c += 26;
            }
            c += 'a';
        }

        text[i] = c;
    }

    return text;
}

string CaesarCipher::decrypt(int key, string text)
{
    for (unsigned int i = 0; i < text.length(); ++i) {
        int c = tolower(text[i]);

        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' - key) % 26;
            if (c < 0) {
                c += 26;
            }
            c += 'a';
        }

        text[i] = c;
    }

    return text;
}

tuple<int, string> CaesarCipher::crack(string text)
{
    string plain, word;

    // Try all possible keys.
    for (int key = 0; key < 26; ++key) {
        plain = decrypt(key, text);

        stringstream s(plain);
        while (s >> word) {
            if (dictionary->lookup(word)) {
                return tuple<int, string>(key, plain);
            }
        }
    }

    return tuple<int, string>(0, text);
}
