#include <algorithm>
#include <map>
#include <string>
#include "AlphabeticAnalyzer.hpp"

using namespace std;


/**
 * Time complexity is Θ(n), where n is the string length.
 */
tuple<map<char, unsigned int>, unsigned int> AlphabeticAnalyzer::analyze(string text)
{
    map<char, unsigned int> frequencies;
    unsigned int current, maxCount = 0;

    // Loop over every character in the cipher text.
    for (size_t i = 0; i < text.length(); ++i) {
        // Convert the character to lower case.
        char c = tolower(text[i]);

        // If the character is a letter, count it.
        if (c >= 'a' && c <= 'z') {
            if (frequencies.count(c) == 0) {
                current = 1;
            } else {
                current = frequencies[c] + 1;
            }

            frequencies[c] = current;

            // Record the largest count encountered.
            if (current > maxCount) {
                maxCount = current;
            }
        }
    }

    return tuple<map<char, unsigned int>, unsigned int>(frequencies, maxCount);
}

/**
 * Time complexity is Θ(n), where n is the string length.
 */
map<string, unsigned int> AlphabeticAnalyzer::digrams(string text)
{
    map<string, unsigned int> frequencies;
    unsigned int wordLength = 0;
    string word;

    // Loop over every character in the cipher text.
    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];

        // If the character is a letter or an apostrophe, count it.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            ++wordLength;

            if (wordLength == 2) {
                word = text.substr(i - 1, 2);
                transform(word.begin(), word.end(), word.begin(), ::tolower);

                if (frequencies.count(word) == 0) {
                    frequencies[word] = 1;
                } else {
                    ++frequencies[word];
                }
            }
        } else {
            wordLength = 0;
        }
    }

    return frequencies;
}
