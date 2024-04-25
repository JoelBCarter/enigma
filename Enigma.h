#ifndef ENIGMA_H
#define ENIGMA_H
#include <string>
#include <vector>

class Enigma {
public:
    Enigma(const std::string& key);
    void Encrypt(const std::vector<std::string>& plaintext, std::vector<std::string>& encryptedText);
    void Decrypt(const std::vector<std::string>& encryptedText, std::vector<std::string>& plaintext);

private:
    std::string key;
    size_t keyIndex;
    char shiftChar(char c, int shift);
};

#endif // ENIGMA_H
