#ifndef CAESARCIPHER_HPP
#define CAESARCIPHER_HPP

#include <string>
#include <tuple>
#include "Dictionary.hpp"
#include "ICipher.hpp"


class CaesarCipher : public ICipher
{
    public:
        CaesarCipher(Dictionary* dictionary);
        virtual std::string encrypt(int key, std::string text);
        virtual std::string decrypt(int key, std::string text);
        virtual std::tuple<int, std::string> crack(std::string text);

    private:
        Dictionary* dictionary;
};

#endif
