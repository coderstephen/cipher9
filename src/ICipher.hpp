#ifndef ICIPHER_HPP
#define ICIPHER_HPP

#include <string>
#include <tuple>


/**
 * Interface for all cipher classes.
 */
class ICipher
{
    public:
        /**
         * Encrypts plain text with the cipher using a given key.
         *
         * @param  key  The key to encrypt with.
         * @param  text The plain text to encrypt.
         * @return      The encrypted cipher text.
         */
        virtual std::string encrypt(int key, std::string text) = 0;

        /**
         * Decrypts cipher text using a given key.
         *
         * @param  key  The key to decrypt with.
         * @param  text The cipher text to decrypt.
         * @return      The decrypted plain text.
         */
        virtual std::string decrypt(int key, std::string text) = 0;

        /**
         * Cracks cipher text using the best brute force algorithm for the cipher.
         *
         * @param  text The cipher text to crack.
         * @return      The cracked key and the resulting plain text.
         */
        virtual std::tuple<int, std::string> crack(std::string text) = 0;

        virtual ~ICipher() {}
};

#endif
