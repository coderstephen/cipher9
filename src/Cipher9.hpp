#ifndef CIPHER9_HPP
#define CIPHER9_HPP

#include <string>


/**
 * Main program instance.
 */
class Cipher9
{
    public:
        /**
         * Creates a new program instance with the given command line arguments.
         */
        Cipher9(int argc, char** argv);

        /**
         * Runs cipher9.
         */
        void run();

    private:
        /**
         * Indicates the encrypt operation.
         */
        bool doEncrypt;

        /**
         * Indicates the decrypt operation.
         */
        bool doDecrypt;

        /**
         * The name of the cipher to use.
         */
        std::string* cipherName;

        /**
         * The cipher key to use.
         */
        int key;

        /**
         * The input text to parse.
         */
        std::string inputText;

        /**
         * Parses the given arguments.
         *
         * @param argc The number of arguments.
         * @param argv An array of argument strings.
         */
        void parseArgs(int argc, char** argv);
};

#endif
