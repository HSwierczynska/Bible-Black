#include <iostream>

#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>

#include "SymmetricEncrypter.hpp"
#include "Util.hpp"

SymmetricEncrypter::SymmetricEncrypter(void)
{
  CryptoPP::AutoSeededRandomPool rnd;
  mKey = CryptoPP::SecByteBlock(0x00, CryptoPP::AES::MAX_KEYLENGTH);
  rnd.GenerateBlock(mKey, mKey.size());
  rnd.GenerateBlock(mIV, CryptoPP::AES::BLOCKSIZE);

  std::string hex = getKeyHex();
}

SymmetricEncrypter::~SymmetricEncrypter(void){}

std::string SymmetricEncrypter::getKeyHex()
{
  return BibleBlack::Util::BytesToHex((unsigned char*)mKey.data(), mKey.size());
}

byte* SymmetricEncrypter::encrypt(byte* data, int len)
{
  CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption aesCfbEncryption(mKey, mKey.size(), mIV);
  aesCfbEncryption.ProcessData(data, data, len);
  return data;
}

byte* SymmetricEncrypter::decrypt(byte* data, int len)
{
  CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption aesCfbDecryption(mKey, mKey.size(), mIV);
  aesCfbDecryption.ProcessData(data, data, len);
  return data;
}
