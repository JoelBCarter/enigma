#include "gtest/gtest.h"
#include "Enigma.h"

class EnigmaTest : public ::testing::Test
{
};

TEST_F(EnigmaTest, Encrypt)
{
    std::string key = "GBRXMD";
    Enigma enigma(key);
    std::vector<std::string> plaintext = {"THE", "QUICK", "BROWN", "FOX", "JUMPS", "OVER", "THE", "LAZY", "DOG"};
    std::vector<std::string> expected = {"AJW", "OHMJM", "TPBAU", "HGV", "WYTRK", "MIIY", "VZC", "YEGA", "VMT"};
    std::vector<std::string> encrypted;

    enigma.Encrypt(plaintext, encrypted);

    ASSERT_EQ(encrypted.size(), expected.size()); // Ensure the sizes are the same
    for (size_t i = 0; i < plaintext.size(); ++i)
    {
        EXPECT_EQ(encrypted[i], expected[i]); // Compare each encrypted string with the expected string
    }
}

TEST_F(EnigmaTest, Decrypt)
{
    std::string key = "GBRXMD";
    Enigma enigma(key);
    std::vector<std::string> encrypted = {"AJW", "OHMJM", "TPBAU", "HGV", "WYTRK", "MIIY", "VZC", "YEGA", "VMT"};
    std::vector<std::string> plaintext = {"THE", "QUICK", "BROWN", "FOX", "JUMPS", "OVER", "THE", "LAZY", "DOG"};
    std::vector<std::string> decrypted;

    enigma.Decrypt(encrypted, decrypted);

    ASSERT_EQ(decrypted.size(), encrypted.size()); // Ensure the sizes are the same
    for (size_t i = 0; i < plaintext.size(); ++i)
    {
        EXPECT_EQ(decrypted[i], plaintext[i]); // Compare each decrypted string with the plaintext string
    }
}

TEST_F(EnigmaTest, EncryptDecryptRoundTrip)
{
    std::string key = "GBRXMD";
    Enigma enigma(key);
    std::vector<std::string> plaintext = {"THE", "QUICK", "BROWN", "FOX", "JUMPS", "OVER", "THE", "LAZY", "DOG"};
    std::vector<std::string> encrypted;
    std::vector<std::string> decrypted;

    enigma.Encrypt(plaintext, encrypted);
    enigma.Decrypt(encrypted, decrypted);

    ASSERT_EQ(plaintext.size(), decrypted.size());
    for (size_t i = 0; i < plaintext.size(); ++i)
    {
        EXPECT_EQ(plaintext[i], decrypted[i]);
    }
}

TEST_F(EnigmaTest, EncryptDecryptRoundTripWithSpaces)
{
    std::string key = "GBRXMD";
    Enigma enigma(key);
    std::vector<std::string> plaintext = {"THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG"};
    std::vector<std::string> encrypted;
    std::vector<std::string> decrypted;

    enigma.Encrypt(plaintext, encrypted);
    enigma.Decrypt(encrypted, decrypted);

    ASSERT_EQ(plaintext.size(), decrypted.size());
    for (size_t i = 0; i < plaintext.size(); ++i)
    {
        EXPECT_EQ(plaintext[i], decrypted[i]);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
