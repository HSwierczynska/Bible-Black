#include <iostream>

#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/secblock.h>

#include "SymmetricEncrypter.hpp"

int main() {

  SymmetricEncrypter e = SymmetricEncrypter();

  std::cout << "Key: (hexadecimal): " << e.getKeyHex() << std::endl;

  char plaintext[] = "test";
  int len = (int)strlen(plaintext)+1;

  std::cout << "Plaintext: " << plaintext << std::endl;

  e.encrypt((byte*)plaintext, len);

  std::cout << "Ciphertext: " << plaintext << std::endl;

  e.decrypt((byte*)plaintext, len);

  std::cout << "Decrypted: " << plaintext << std::endl;

  return 5;
}
