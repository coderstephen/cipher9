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
    // Loop over every character in the plain text.
    for (size_t i = 0; i < text.length(); ++i) {
        // Convert the character to lower case.
        int c = tolower(text[i]);

        // If the character is a letter, encrypt it.
        if (c >= 'a' && c <= 'z') {
            // The character is first shifted to its index in the alphabet (0-25),
            // then the key shift is added to the value, wrapping around on overflow.
            c = (c - 'a' + key) % 26;
            if (c < 0) {
                c += 26;
            }
            // Shift the letter back to ASCII code.
            c += 'a';
        }

        // Update the character value at the current spot in the string.
        text[i] = c;
    }

    return text;
}

string CaesarCipher::decrypt(int key, string text)
{
    // Decrypting a Caesar cipher text is the inverse operation, so just negate
    // the key and perform the encryption operation with the negated key.
    return encrypt(0 - key, text);
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

        // If at least 50% of the words are in the dictionary, mark the current
        // key as the solution.
        if (matchedWords > count / 2) {
            return tuple<int, string>(key, plain);
        }
    }

    // If no keys attempted could decrypt the text into English, assume the text
    // is not a plain text message, which breaking cannot be automated.
    return tuple<int, string>(0, text);
}
