#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <set>
#include <string>


/**
 * A word dictionary that can be used to look up words.
 *
 * Uses the system's dictionary for the current user, if available.
 */
class Dictionary
{
    public:
        /**
         * Loads a new dictionary instance.
         */
        Dictionary();

        /**
         * Checks if a word can be found in the dictionary.
         *
         * @param  word The word to look up.
         * @return      True if the word is in the dictionary, otherwise false.
         */
        bool lookup(std::string word);

    private:
        /**
         * A set of defined words.
         */
        std::set<std::string> words;
};

#endif
