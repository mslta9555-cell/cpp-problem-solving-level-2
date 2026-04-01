// Problem_19: Random Character Generator (ASCII Logic)
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cctype>

// Define Enum for Character Types to make code more readable
enum enCharType { 
    SmallLetter = 1, 
    CapitalLetter = 2, 
    SpecialCharacter = 3, 
    Digit = 4 
};

/**
 * Utility to clear input buffer
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Generates a random number between two values (inclusive)
 */
int generateRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

/**
 * Core Logic: Map the Enum type to its corresponding ASCII range
 * Small Letters: 97 - 122
 * Capital Letters: 65 - 90
 * Special Characters: 33 - 47
 * Digits: 48 - 57
 */
char getRandomCharacter(enCharType charType) {
    switch (charType) {
        case SmallLetter:
            return static_cast<char>(generateRandomNumber('a', 'z'));
        case CapitalLetter:
            return static_cast<char>(generateRandomNumber('A', 'Z'));
        case Digit:
            return static_cast<char>(generateRandomNumber('0', '9'));
        case SpecialCharacter:
            return static_cast<char>(generateRandomNumber('!', '/'));
        default:
            throw std::invalid_argument("Invalid character type");
    }
}

/**
 * UI Layer: Display different random characters
 */
void printAllRandomTypes() {
    std::cout << "\n--- Random Character Results ---";
    std::cout << "\nSmall Letter      : " << getRandomCharacter(enCharType::SmallLetter);
    std::cout << "\nCapital Letter    : " << getRandomCharacter(enCharType::CapitalLetter);
    std::cout << "\nSpecial Character : " << getRandomCharacter(enCharType::SpecialCharacter);
    std::cout << "\nDigit             : " << getRandomCharacter(enCharType::Digit);
    std::cout << "\n--------------------------------\n";
}

bool askToRepeat() {
    std::cout << "\nGenerate again? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

void runProgram() {
    
    do {
        printAllRandomTypes();
    } while (askToRepeat());
}

int main() {

    // Seed the random generator using time
    srand(static_cast<unsigned>(time(NULL)));
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
