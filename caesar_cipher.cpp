// Problem_17: Caesar Cipher (Encryption/Decryption)
#include <iostream>
#include <limits>
#include <string>

/**
 * Utility to clear input buffer
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Reads a positive number to be used as an encryption key
 */
int readPositiveNumber(const std::string& prompt) {
    int number{0};
    while (true) {
        std::cout << prompt;
        if (std::cin >> number && number > 0) {
            clearInputBuffer();
            return number;
        }
        std::cout << "❌ Invalid input. Please enter a positive number.\n";
        clearInputBuffer();
    }
}

/**
 * Reads text from user (Single word)
 */
std::string readText(const std::string& prompt) {
    std::string text = "";
    std::cout << prompt;
    std::cin >> text;
    return text;
}

/**
 * Logic: Shifts each character forward by the key value
 */
std::string encryptText(std::string text, short encryptionKey) {
    for (int i = 0; i < text.length(); i++) {
        // Shift character value up
        text[i] = char((int)text[i] + encryptionKey);
    }
    return text;
}

/**
 * Logic: Shifts each character backward by the key value
 */
std::string decryptText(std::string text, short encryptionKey) {
    for (int i = 0; i < text.length(); i++) {
        // Shift character value down
        text[i] = char((int)text[i] - encryptionKey);
    }
    return text;
}

void printResult(std::string original, std::string encrypted, std::string decrypted) {
    std::cout << "\n======================================";
    std::cout << "\nText Before Encryption : " << original;
    std::cout << "\nText After Encryption  : " << encrypted;
    std::cout << "\nText After Decryption  : " << decrypted;
    std::cout << "\n======================================\n";
}

bool askToRepeat() {
    std::cout << "\nTry another text? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Orchestrator: Managing the flow of Encryption/Decryption
 */
void runProgram() {
    do {
        std::string originalText = readText("Please enter text: ");
        short key = (short)readPositiveNumber("Please enter encryption key: ");

        // Step 1: Encrypt the original text
        std::string textAfterEncryption = encryptText(originalText, key);
        
        // Step 2: Decrypt the encrypted text to get the original back
        // Senior Fix: Pass 'textAfterEncryption' instead of 'textAfterDecryption'
        std::string textAfterDecryption = decryptText(textAfterEncryption, key);

        printResult(originalText, textAfterEncryption, textAfterDecryption);

    } while (askToRepeat());
}

int main() {
    runProgram();
    std::cout << "\n🙏 Encryption Test Complete. See you next time!\n";
    return 0;
}
