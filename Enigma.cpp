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
            // Convert the key character to a number (1 - 26) to add to the ASCII value of the text character
            int shift = key[keyIndex] - 'A' + 1;
            // Add the key number to the ASCII value of the text character to get the encrypted character
            encryptedLine += shiftChar(c, shift);
            // Move to the next key character, wrapping around if past end of key
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
            // Convert the key character to a number (1 - 26) to subtract from the ASCII value of the text character
            int shift = -(key[keyIndex] - 'A') - 1;
            // Subtract the key number from the ASCII value of the text character to get the decrypted character
            decryptedLine += shiftChar(c, shift);
            // Move to the next key character, wrapping around if past end of key
            keyIndex = (keyIndex + 1) % key.length();
        }
        plaintext.push_back(decryptedLine);
    }
}

char Enigma::shiftChar(char c, int shift)
{
    // If the character is not an uppercase letter
    if (c < 'A' || c > 'Z')
    {
        // Return the character unchanged
        return c;
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
