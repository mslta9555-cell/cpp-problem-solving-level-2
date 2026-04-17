// Problem_32: Ultimate Flexible License Key Generator (Optimized)
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>

// Structure to store generated keys in a fixed-size array
struct stArr {
    std::string arr[100]; 
};

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
    config.numberOfKeys = readPositiveNumber("How many keys (Max 100)? ");
    config.lettersPerPart = readPositiveNumber("Letters per part? ");
    config.numberOfParts = readPositiveNumber("Parts per key? ");
    
    do {
        std::cout << "\nChoose Character Type:\n";
        std::cout << "1: Capital Letters, 2: Small Letters, 3: Special, 4: Digits, 5: Mix All\n";
        config.passwordType = readPositiveNumber("Selection (1-5): ");
        if (config.passwordType > 5) std::cout << "⚠️ Invalid Selection.\n";
    } while (config.passwordType > 5);
    
    return config;
}

int randomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

// Logic: Picks a character based on type, handles Mix mode internally
char getRandomCharacter(int type) {
    if (type == enCharType::Mix) {
        type = randomNumber(1, 4);
    }
    switch (type) {
        case enCharType::CapitalLetter:   return (char)randomNumber('A', 'Z');
        case enCharType::SmallLetter:     return (char)randomNumber('a', 'z');
        case enCharType::SpecialCharacter: return (char)randomNumber(33, 47);
        case enCharType::Digit:            return (char)randomNumber('0', '9');
        default:                           return 'X';
    }
}

std::string generatePart(int type, int lettersCount) {
    std::string part = "";
    for (int i = 1; i <= lettersCount; i++) {
        part += getRandomCharacter(type);
    }
    return part;
}

// Logic: Constructs a key like XXXX-XXXX-XXXX
std::string generateFullKey(stKeyConfig config) {
    std::string key = "";
    for (int i = 1; i <= config.numberOfParts; i++) {
        key += generatePart(config.passwordType, config.lettersPerPart);
        if (i < config.numberOfParts) key += "-";
    }
    return key;
}

// Logic: Fills the array correctly starting from index 0
void fillArrayWithKeys(stArr &arr, stKeyConfig config)
{
    for (int i = 0; i < config.numberOfKeys; i++) // Fixed: i < count
    {
        arr.arr[i] = generateFullKey(config);
    }
}

// UI: Prints all stored keys from the array
void printKeys(const stArr &arr, const stKeyConfig config) {
    std::cout << "\n--- Generated Keys List ---\n";
    for (int i = 0; i < config.numberOfKeys; i++) { // Fixed: Start from 0
        std::cout << "Array[" << i << "] : " << arr.arr[i] << "\n";
    }
    std::cout << "---------------------------\n";
}

bool askToRepeat() {
    std::cout << "\nGenerate another set? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

void runProgram() {
    do {
        stArr arr;
        stKeyConfig config = readConfig(); 
        fillArrayWithKeys(arr, config);
        printKeys(arr, config);
    } while (askToRepeat());
}

int main() {
    srand((unsigned)time(NULL)); 
    runProgram();
    return 0;
}
