#include <algorithm>
#include <iostream>
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

        // Parse the plaintext into words to do a dictionary match.
        stringstream s(plain);
        unsigned int count = 0, matchedWords = 0;
        for (; s >> word; ++count) {
            // Strip punctuation from the word.
            string strippedWord;
            remove_copy_if(word.begin(), word.end(), back_inserter(strippedWord), ptr_fun<int, int>(&ispunct));

            // Check if the word is in the dictionary.
            if (dictionary->lookup(strippedWord)) {
                ++matchedWords;
            }
        }

        // If at least 50% of the words are in the dictionary, use this key as the solution.
        if (matchedWords > count / 2) {
            return tuple<int, string>(key, plain);
        }
    }

    return tuple<int, string>(0, text);
}
