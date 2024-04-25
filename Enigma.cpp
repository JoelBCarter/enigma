#include "Enigma.h"

Enigma::Enigma(const std::string& key) : key(key), keyIndex(0) {}

void Enigma::Encrypt(const std::vector<std::string>& plaintext, std::vector<std::string>& encryptedText) {
    encryptedText.clear();
    for (const auto& line : plaintext) {
        std::string encryptedLine;
        for (char c : line) {
            int shift = key[keyIndex] - 'A'; // assuming key is all uppercase
            encryptedLine += shiftChar(c, shift);
            keyIndex = (keyIndex + 1) % key.length();
        }
        encryptedText.push_back(encryptedLine);
    }
}

void Enigma::Decrypt(const std::vector<std::string>& encryptedText, std::vector<std::string>& plaintext) {
    plaintext.clear();
    for (const auto& line : encryptedText) {
        std::string decryptedLine;
        for (char c : line) {
            int shift = -(key[keyIndex] - 'A'); // Make the shift negative for decryption
            decryptedLine += shiftChar(c, shift);
            keyIndex = (keyIndex + 1) % key.length(); // Increment key index and wrap around
        }
        plaintext.push_back(decryptedLine);
    }
}

char Enigma::shiftChar(char c, int shift) {
    // Check if the character is alphabetic; if not, return it unchanged
    if (!isalpha(c)) {
        return c;
    }

    // Determine the range: 'A' to 'Z' or 'a' to 'z'
    char offset = isupper(c) ? 'A' : 'a';
    // Shift within the bounds of 0-25 (modulus 26)
    int shifted = static_cast<int>(c - offset + shift) % 26;
    if (shifted < 0) {
        shifted += 26; // Ensure positive result after modulo operation
    }
    return static_cast<char>(shifted + offset);
}
