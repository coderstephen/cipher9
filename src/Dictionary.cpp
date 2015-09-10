#include <algorithm>
#include <fstream>
#include <string>
#include "Dictionary.hpp"

using namespace std;


Dictionary::Dictionary()
{
    ifstream file("/usr/share/dict/words");
    string word;

    while (file.good()) {
        file >> word;
        word[0] = tolower(word[0]);
        words.insert(word);
    }

    file.close();
}

bool Dictionary::lookup(string word)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    return words.count(word) > 0;
}
