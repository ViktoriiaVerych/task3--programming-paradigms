#include <iostream>
#include <cstring>

char* encrypt(char* rawText, int key) {
    int length = strlen(rawText);
    char* encryptedText = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        char ch = rawText[i];
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            encryptedText[i] = (ch - base + key) % 26 + base;
        } else {
            encryptedText[i] = ch;
        }
    }
    encryptedText[length] = '\0';
    return encryptedText;
}

char* decrypt(char* encryptedText, int key) {
    int length = strlen(encryptedText);
    char* decryptedText = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        char ch = encryptedText[i];
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';

            decryptedText[i] = (ch - base - key + 26) % 26 + base;
        } else {
            decryptedText[i] = ch;
        }
    }
    decryptedText[length] = '\0';
    return decryptedText;
}

int main() {
    std::cout << "Enter the text to encrypt: ";
    std::string inputText;
    std::getline(std::cin, inputText);

    int key;
    std::cout << "Enter the encryption key (an integer): ";
    std::cin >> key;

    char* encryptedText = encrypt(&inputText[0], key);
    char* decryptedText = decrypt(encryptedText, key);

    std::cout << "Encrypted Text: " << encryptedText << std::endl;
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    delete[] encryptedText;
    delete[] decryptedText;

    return 0;
}
