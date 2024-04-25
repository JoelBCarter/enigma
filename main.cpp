#include "Enigma.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    // Prompt for the encryption key
    std::string key;
    std::cout << "Enter the encryption key: ";
    getline(std::cin, key); // Using getline to allow spaces in the key, if that's a requirement

    // Create an Enigma object with the key
    Enigma enigmaMachine(key);

    // Read plaintext from the file into a vector<string>
    std::vector<std::string> plaintextLines;
    std::ifstream plaintextFile("plaintext.txt");
    std::string line;

    if (!plaintextFile) {
        std::cerr << "Could not open plaintext.txt for reading." << std::endl;
        return 1;
    }

    while (getline(plaintextFile, line)) {
        plaintextLines.push_back(line);
    }
    plaintextFile.close();

    // Encrypt the plaintext
    std::vector<std::string> encryptedLines;
    enigmaMachine.Encrypt(plaintextLines, encryptedLines);

    // Write the encrypted text to a file
    std::ofstream encryptedFile("encrypted.txt");
    if (!encryptedFile) {
        std::cerr << "Could not open encrypted.txt for writing." << std::endl;
        return 1;
    }

    for (const auto& encryptedLine : encryptedLines) {
        encryptedFile << encryptedLine << '\n';
    }
    encryptedFile.close();

    std::cout << "Encryption completed. Encrypted text written to encrypted.txt." << std::endl;

    return 0;
}
