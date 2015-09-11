#include <algorithm>
#include <fstream>
#include <string>
#include "Dictionary.hpp"

using namespace std;


Dictionary::Dictionary()
{
    // Read the system dictionary file.
    ifstream file("/usr/share/dict/words");
    string word;

    // Copy the words in the dictionary into memory for fast lookups later.
    while (file.good()) {
        file >> word;
        word[0] = tolower(word[0]);
        words.insert(word);
    }

    file.close();
}

bool Dictionary::lookup(string word)
{
    // Make word lowercase for comparison first.
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    // Simply check if the word is in the dictionary at least once.
    return words.count(word) > 0;
}
