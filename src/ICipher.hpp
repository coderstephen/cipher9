#ifndef ICIPHER_HPP
#define ICIPHER_HPP

#include <string>
#include <tuple>


class ICipher
{
    public:
        virtual std::string encrypt(int key, std::string text) = 0;
        virtual std::string decrypt(int key, std::string text) = 0;
        virtual std::tuple<int, std::string> crack(std::string text) = 0;
        virtual ~ICipher() {}
};

#endif
