#include "SubstitutionCipher.hpp"

using namespace std;


string SubstitutionCipher::encrypt(string key, string text)
{
    // Loop over every character in the plain text.
    for (size_t i = 0; i < text.length(); ++i) {
        // Convert the character to lower case.
        int c = tolower(text[i]);

        // If the character is a letter, substitute it with a character from the key
        if (c >= 'a' && c <= 'z') {
            // Select the corresponding character from the key, wrapping around if necessary.
            c = key[(c - 'a') % key.length()];
        }

        // Update the character value at the current spot in the string.
        text[i] = c;
    }

    return text;
}

string SubstitutionCipher::decrypt(string key, string text)
{
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
