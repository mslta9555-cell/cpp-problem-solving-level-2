// Problem_20: Ultimate Flexible License Key Generator (Optimized Mix Mode)
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <set>

enum enCharType { 
    CapitalLetter = 1, SmallLetter = 2, SpecialCharacter = 3, Digit = 4, Mix = 5 
};

struct stKeyConfig {
    int numberOfKeys{0}; 
    int lettersPerPart{0};
    int numberOfParts{0};
    int passwordType{0}; 
};

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

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

stKeyConfig readConfig() {
    stKeyConfig config;
    config.numberOfKeys = readPositiveNumber("How many keys? ");
    config.lettersPerPart = readPositiveNumber("Letters per part? ");
    config.numberOfParts = readPositiveNumber("Parts per key? ");
    
    do {
        std::cout << "\nChoose Character Type:\n";
        std::cout << "1: Capital Letters (A-Z)\n";
        std::cout << "2: Small Letters (a-z)\n";
        std::cout << "3: Special Characters (!@#)\n";
        std::cout << "4: Digits (0-9)\n";
        std::cout << "5: Mix All Types\n"; // خيار واحد يجمع كل شيء بذكاء
        config.passwordType = readPositiveNumber("Selection (1-5): ");
        
        if (config.passwordType > 5) std::cout << "⚠️ Invalid Selection.\n";
    } while (config.passwordType > 5);
    
    return config;
}

int randomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

/**
 * Logic: This is the core fix. 
 * If Mix is chosen, it randomly picks a type for EVERY character.
 */
char getRandomCharacter(int type) {
    // If user chose MIX (5), we randomly re-assign 'type' to 1, 2, 3, or 4
    if (type == enCharType::Mix) {
        type = randomNumber(1, 4);
    }
    switch (type) {
        case enCharType::CapitalLetter:   return (char)randomNumber('A', 'Z');
        case enCharType::SmallLetter:     return (char)randomNumber('a', 'z');
        case enCharType::SpecialCharacter: return (char)randomNumber(33, 47);
        case enCharType::Digit:            return (char)randomNumber('0', '9');
        default:                           throw std::invalid_argument("Invalid type");
    }
}

std::string generatePart(int type, int lettersCount) {
    std::string part = "";
    for (int i = 1; i <= lettersCount; i++) {
        part += getRandomCharacter(type);
    }
    return part;
}

std::string generateFullKey(stKeyConfig config) {
    std::string key = "";
    for (int i = 1; i <= config.numberOfParts; i++) {
        key += generatePart(config.passwordType, config.lettersPerPart);
        if (i < config.numberOfParts) key += "-";
    }
    return key;
}

void printKeys(stKeyConfig config) {
    std::cout << "\n--- Generated Keys ---\n";
    for (int i = 1; i <= config.numberOfKeys; i++) {
        std::cout << "Key [" << i << "] : " << generateFullKey(config) << "\n";
    }
    std::cout << "----------------------\n";
}

void runProgram() {
    do {
        stKeyConfig config = readConfig(); 
        printKeys(config);
    } while (readPositiveNumber("Try again? (1:Yes / 0:No): ") == 1);
}

int main() {
    srand((unsigned)time(NULL)); 
    std::set<std::string> keys;
    runProgram();
    return 0;
}
