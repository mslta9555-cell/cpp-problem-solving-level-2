// Problem_16: Simple Brute Force Password Cracker
#include <iostream>
#include <limits>
#include <string>

/**
 * Utility to clear input buffer for clean interactions
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Reads the target password from user (Expected 3 letters like 'AAF')
 */
std::string readPassword(std::string prompt) {
    std::string password = "";
    std::cout << prompt;
    std::cin >> password;
    return password;
}

/**
 * Core Logic: Tries every combination from AAA to ZZZ
 * This is the classic "Brute Force" algorithm.
 */
bool guessPassword(std::string targetPassword) {
    int counter{0};
    std::string currentTrial = "";

    for (char i = 'A'; i <= 'Z'; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            for (char k = 'A'; k <= 'Z'; k++) {
                
                counter++;
                // Reset and build the 3-letter word for this trial
                currentTrial = ""; 
                currentTrial = std::string() = i + j + k;

                std::cout << "Trial [" << counter << "] : " << currentTrial << "\n";

                // Compare current trial with the target password
                if (currentTrial == targetPassword) {
                    std::cout << "\n✨ Password Found: " << currentTrial << "\n";
                    std::cout << "✅ Found after " << counter << " trial(s).\n";
                    return true; // Stop all loops immediately
                }
            }
        }
    }
    std::cout << "\n❌ Password not found in 3-letter range.\n";
    return false;
}

/**
 * Control Layer: Handles repetition
 */
bool askToRepeat() {
    std::cout << "\nTry another password? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Orchestrator: Connects the password input to the cracker logic
 */
void runProgram() {
    do {
        std::string target = readPassword("Enter a 3-letter password (Uppercase): ");
        guessPassword(target);
    } while (askToRepeat());
}

int main() {
    runProgram();
    std::cout << "\n🙏 Security Test Complete. See you next time!\n";
    return 0;
}
