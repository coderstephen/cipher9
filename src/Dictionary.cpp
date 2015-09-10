#include <algorithm>
#include <fstream>
#include <string>
#include "Dictionary.hpp"

using namespace std;


bool Dictionary::lookup(string word)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    ifstream file("/usr/share/dict/words");
    string current;

    while (file.good()) {
        file >> current;
        current[0] = tolower(current[0]);

        if (file.good() && current == word) {
            return true;
        }
    }

    return false;
}
