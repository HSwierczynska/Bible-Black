#include <string>
#include <sstream>

namespace BibleBlack {
  namespace Util {
    std::string BytesToHex(unsigned char* bytes, unsigned int length)
    {
      std::string result;
      for (unsigned int i=0; i<length; i++)
        {
          char s[length];
          sprintf(s, "%02x", bytes[i]);
          result += s;
        }
      return result;
    }

    std::vector<unsigned char> hexToBytes(const std::string& hex)
    {
      std::vector<unsigned char> result;
      for(unsigned int i=0; i<hex.length(); i+=2)
        {
          std::string bytestr = hex.substr(i, 2);
          unsigned char byte = (unsigned char) strtoul(bytestr.c_str(), NULL, 16);
          result.push_back(byte);
        }

      return result;
    }
  }
}
