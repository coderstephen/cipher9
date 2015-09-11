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
         * Encrypts the given text using a Caesar cipher.
         *
         * @param  key  The cipher key to use.
         * @param  text The plain text to encrypt.
         * @return      The encrypted cipher text.
         */
        virtual std::string encrypt(int key, std::string text);

        /**
         * Decrypts the given text encrypted with a Caesar cipher.
         *
         * @param  key  The cipher key to decrypt with.
         * @param  text The cipher text to decrypt.
         * @return      The decrypted plain text.
         */
        virtual std::string decrypt(int key, std::string text);

        /**
         * Cracks cipher text using brute force and dictionary lookups.
         *
         * @param  text The cipher text to crack.
         * @return      The cracked key and the resulting plain text.
         */
        virtual std::tuple<int, std::string> crack(std::string text);

    private:
        /**
         * The dictionary to use.
         */
        Dictionary* dictionary;
};

#endif
