#include "gtest/gtest.h"
#include "Enigma.h"

class EnigmaTest : public ::testing::Test
{
};

TEST_F(EnigmaTest, EncryptDecryptConsistency)
{
    std::string key = "KEY";
    Enigma enigma(key);
    std::vector<std::string> plaintext = {"HELLO", "WORLD"};
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

TEST_F(EnigmaTest, EncryptDecryptNonAlphaCharacters)
{
    std::string key = "KEY";
    Enigma enigma(key);
    std::vector<std::string> plaintext = {"HELLO 123", "WORLD!@#"};
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
