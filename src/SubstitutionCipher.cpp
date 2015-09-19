#include "SubstitutionCipher.hpp"

using namespace std;


string SubstitutionCipher::createKey(string key)
{
    string parsedKey;

    // Add only unique characters in the key word.
    for (size_t i = 0; i < key.length(); ++i) {
        if (parsedKey.find(key[i]) == string::npos) {
            parsedKey.append(1, key[i]);
        }
    }

    // Fill the key if it is less than 26 characters.
    if (parsedKey.length() < 26) {
        // Add each letter in order not yet in the key.
        for (size_t i = 0; i < 26; ++i) {
            if (parsedKey.find(i + 'a') == string::npos) {
                parsedKey.append(1, i + 'a');
            }
        }
    }

    return parsedKey;
}

string SubstitutionCipher::encrypt(string key, string text)
{
    key = createKey(key);

    // Loop over every character in the plain text.
    for (size_t i = 0; i < text.length(); ++i) {
        // Convert the character to lower case.
        int c = tolower(text[i]);

        // If the character is a letter, substitute it with a character from the key
        if (c >= 'a' && c <= 'z') {
            // Select the corresponding character from the key.
            c = key[(c - 'a')];
        }

        // Update the character value at the current spot in the string.
        text[i] = c;
    }

    return text;
}

string SubstitutionCipher::decrypt(string key, string text)
{
    key = createKey(key);

    // Loop over every character in the cipher text.
    for (size_t i = 0; i < text.length(); ++i) {
        // Convert the character to lower case.
        int c = tolower(text[i]);

        // If the character is a letter, restore it with a character from the key.
        if (c >= 'a' && c <= 'z') {
            // Find the position that produces the given substitution.
            c = key.find(c) + 'a';
        }

        // Update the character value at the current spot in the string.
        text[i] = c;
    }

    return text;
}
