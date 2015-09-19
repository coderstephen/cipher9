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
         *
         * @param argc The number of arguments.
         * @param argv An array of argument strings.
         */
        Cipher9(int argc, char** argv);

        /**
         * Prints the program usage to standard output.
         */
        void printUsage();

        /**
         * Runs cipher9.
         */
        void run();

    private:
        /**
         * Runs the cipher operations.
         */
        void runCipher(std::string inputText);

        /**
         * Runs the analysis operations.
         */
        void runAnalysis(std::string inputText);

        /**
         * Indicates the analyze operation.
         */
        bool doAnalyze = false;

        /**
         * Indicates the encrypt operation.
         */
        bool doEncrypt = false;

        /**
         * Indicates the decrypt operation.
         */
        bool doDecrypt = false;

        /**
         * Indicates the help message should be shown.
         */
        bool doHelp = false;

        /**
         * Indicates if the key should be printed with the text.
         */
        bool printKey = false;

        /**
         * The name of an input file.
         */
        std::string* fileName = NULL;

        /**
         * The name of the cipher to use.
         */
        std::string* cipherName = NULL;

        /**
         * The cipher key to use.
         */
        std::string* key = NULL;
};

#endif
