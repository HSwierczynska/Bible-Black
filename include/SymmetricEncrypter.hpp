#include <cryptopp/aes.h>
#include <cryptopp/secblock.h>

class SymmetricEncrypter
{
public:
  SymmetricEncrypter(void);
  virtual ~SymmetricEncrypter(void);

  std::string getKeyHex();
  byte* encrypt(byte* data, int len);
  byte* decrypt(byte* data, int len);

protected:
  CryptoPP::SecByteBlock mKey;
  byte mIV[CryptoPP::AES::BLOCKSIZE];

};
