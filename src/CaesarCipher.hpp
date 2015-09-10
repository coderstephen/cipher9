#ifndef CAESARCIPHER_HPP
#define CAESARCIPHER_HPP

#include <string>
#include <tuple>
#include "Dictionary.hpp"
#include "ICipher.hpp"


/**
 * Implementation of the Caesar cipher.
 */
class CaesarCipher : public ICipher
{
    public:
        /**
         * Creates a new Caesar cipher instance using the given dictionary.
         */
        CaesarCipher(Dictionary* dictionary);

        /**
         * @inheritDoc
         */
        virtual std::string encrypt(int key, std::string text);

        /**
         * @inheritDoc
         */
        virtual std::string decrypt(int key, std::string text);

        /**
         * @inheritDoc
         */
        virtual std::tuple<int, std::string> crack(std::string text);

    private:
        /**
         * The dictionary to use.
         */
        Dictionary* dictionary;
};

#endif
