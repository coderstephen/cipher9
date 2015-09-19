#ifndef ALPHABETICANALYZER_HPP
#define ALPHABETICANALYZER_HPP

#include <map>
#include <string>
#include <tuple>


/**
 * Analyzes frequencies and patterns in an alphabetic cipher text.
 */
class AlphabeticAnalyzer
{
    public:
        /**
         * Analyzes the given cipher text and returns the frequencies of each letter.
         *
         * @param  text The cipher text to analyze.
         * @return      A map of characters to their frequencies in the text, and
         *              the largest frequency count.
         */
        std::tuple<std::map<char, unsigned int>, unsigned int> analyze(std::string text);

        /**
         * Finds all digrams and returns their frequencies.
         *
         * @param  text The cipher text to analyze.
         * @return      A map of digrams to their frequencies in the text.
         */
        std::map<std::string, unsigned int> digrams(std::string text);
};

#endif
