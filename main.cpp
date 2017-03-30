#include <iostream>

#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/secblock.h>

#include "include/Util.hpp"

int main() {
  CryptoPP::AutoSeededRandomPool rnd;
  CryptoPP::SecByteBlock key(0x00, CryptoPP::AES::MAX_KEYLENGTH);
  rnd.GenerateBlock(key, key.size());

  byte iv[CryptoPP::AES::BLOCKSIZE];
  rnd.GenerateBlock(iv, CryptoPP::AES::BLOCKSIZE);

  std::string hex = BibleBlack::Util::BytesToHex((unsigned char*)key.data(), key.size());

  std::cout << "Key: " << std::string((char*)key.data(), key.size()) << std::endl;
  std::cout << "Key (hexadecimal): " << hex << std::endl;
  std::cout << "Key length: " << std::to_string(key.size() * 8) << " bits" << std::endl;

  char plaintext[] = "test";
  int len = (int)strlen(plaintext)+1;

  std::cout << "Plaintext: " << plaintext << std::endl;

  CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption aesCfbEncryption(key, key.size(), iv);
  aesCfbEncryption.ProcessData((byte*)plaintext, (byte*)plaintext, len);

  std::cout << "Ciphertext: " << plaintext << std::endl;

  hex = BibleBlack::Util::BytesToHex((unsigned char*)plaintext, len);

  std::cout << "Ciphertext (hexadecimal): " << hex << std::endl;

  CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption aesCfbDecryption(key, key.size(), iv);
  aesCfbDecryption.ProcessData((byte*) plaintext, (byte*)plaintext, len);

  std::cout << "Decrypted: " << plaintext << std::endl;

  return 5;
}
