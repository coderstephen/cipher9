#ifndef SUBSTITUTIONCIPHER_HPP
#define SUBSTITUTIONCIPHER_HPP

#include <string>
#include <tuple>
#include "Dictionary.hpp"
#include "ICipher.hpp"


/**
 * Implementation of a monoalphabetic substitution cipher.
 */
class SubstitutionCipher : public ICipher<std::string>
{
    public:
        /**
         * Parses a key word and returns a full 26 character key.
         *
         * @param  key The key word.
         * @return     The substitution key.
         */
        std::string createKey(std::string key);

        /**
         * Encrypts the given text using a Caesar cipher.
         *
         * @param  key  The cipher key to use.
         * @param  text The plain text to encrypt.
         * @return      The encrypted cipher text.
         */
        virtual std::string encrypt(std::string key, std::string text);

        /**
         * Decrypts the given text encrypted with a Caesar cipher.
         *
         * @param  key  The cipher key to decrypt with.
         * @param  text The cipher text to decrypt.
         * @return      The decrypted plain text.
         */
        virtual std::string decrypt(std::string key, std::string text);
};

#endif
