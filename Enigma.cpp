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
            int shift = key[keyIndex] - 'A' + 1;
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
            int shift = -(key[keyIndex] - 'A') - 1;
            decryptedLine += shiftChar(c, shift);
            keyIndex = (keyIndex + 1) % key.length();
        }
        plaintext.push_back(decryptedLine);
    }
}

char Enigma::shiftChar(char c, int shift)
{
    // Check if the character is an uppercase letter
    if (c < 'A' || c > 'Z')
    {
        return c; // Return the character unchanged if it is not a capital letter
    }

    // Shift the character within the range of 'A' to 'Z'
    int alphaIndex = c - 'A';                     // Convert character to a 0-25 index
    int shiftedIndex = (alphaIndex + shift) % 26; // Apply the shift and wrap around using modulo 26
    if (shiftedIndex < 0)
    {
        shiftedIndex += 26; // Adjust if the result is negative (for negative shifts)
    }

    return 'A' + shiftedIndex; // Convert back to the ASCII character
}
