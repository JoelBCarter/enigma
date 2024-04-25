#include "Enigma.h"

Enigma::Enigma(const std::string &key) : key(key), keyIndex(0) {}

void Enigma::Encrypt(const std::vector<std::string> &plaintext, std::vector<std::string> &encryptedText)
{
    encryptedText.clear();
    keyIndex = 0; // Reset key index at the start
    for (const auto &line : plaintext)
    {
        std::string encryptedLine;
        for (char c : line)
        {
            int shift = key[keyIndex] - 'A';
            encryptedLine += shiftChar(c, shift);
            keyIndex = (keyIndex + 1) % key.length();
        }
        encryptedText.push_back(encryptedLine);
    }
}

void Enigma::Decrypt(const std::vector<std::string> &encryptedText, std::vector<std::string> &plaintext)
{
    plaintext.clear();
    keyIndex = 0; // Reset key index at the start
    for (const auto &line : encryptedText)
    {
        std::string decryptedLine;
        for (char c : line)
        {
            int shift = -(key[keyIndex] - 'A');
            decryptedLine += shiftChar(c, shift);
            keyIndex = (keyIndex + 1) % key.length();
        }
        plaintext.push_back(decryptedLine);
    }
}

char Enigma::shiftChar(char c, int shift) {
    if (!isalpha(c)) {
        return c;  // Non-alphabetic characters are not shifted.
    }

    char base = isupper(c) ? 'A' : 'a';
    int alphaIndex = (c - base + shift) % 26;  // Calculate index in the alphabet with the shift
    if (alphaIndex < 0) {
        alphaIndex += 26;  // Ensure the index is positive
    }
    return base + alphaIndex;  // Convert back to the ASCII character
}
