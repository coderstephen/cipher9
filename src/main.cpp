#include <iostream>
#include "Cipher9.hpp"
#include "CaesarCipher.hpp"
#include "Dictionary.hpp"

using namespace std;


int main()
{
    Dictionary* dict = new Dictionary();
    CaesarCipher* cipher = new CaesarCipher(dict);

    string ciphertext = cipher->encrypt(12, "hello world");
    cout << ciphertext << endl;
    std::cout << get<1>(cipher->crack(ciphertext)) << std::endl;
}
