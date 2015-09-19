#ifndef ICIPHER_HPP
#define ICIPHER_HPP

#include <string>
#include <tuple>


/**
 * Interface for all cipher classes.
 */
template <typename K> class ICipher
{
    public:
        /**
         * Encrypts plain text with the cipher using a given key.
         *
         * @param  key  The key to encrypt with.
         * @param  text The plain text to encrypt.
         * @return      The encrypted cipher text.
         */
        virtual std::string encrypt(K key, std::string text) = 0;

        /**
         * Decrypts cipher text using a given key.
         *
         * @param  key  The key to decrypt with.
         * @param  text The cipher text to decrypt.
         * @return      The decrypted plain text.
         */
        virtual std::string decrypt(K key, std::string text) = 0;

        virtual ~ICipher() {}
};

#endif
