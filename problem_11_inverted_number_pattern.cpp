// Problem_11: Inverted Number Pattern
#include <iostream>
#include <limits>
#include <cctype>

/**
 * Standard utility to clear the input buffer.
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Input Layer: Ensures a valid positive integer is provided.
 */
long long readPositiveInteger(const std::string& prompt) {
    long long value{0};
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value > 0) {
            clearInputBuffer();
            return value;
        }
        std::cout << "❌ Invalid input. Please enter a positive number.\n";
        std::cin.clear();
        clearInputBuffer();
    }
}

/**
 * Core Logic: Prints an inverted pattern.
 * If number = 3:
 * 3 3 3
 * 2 2
 * 1
 */
void printInvertedNumberPattern(long long number) {
    std::cout << "\n--- Pattern Start ---\n";
    
    // Outer loop: Controls the rows (starts from the max number down to 1)
    for (long long i = number; i >= 1; i--) {
        
        // Inner loop: Controls how many times the number 'i' is printed in the row
        // We stop at 'j <= i' to create the inverted triangle shape
        for (long long j = 1; j <= i; j++) {
            std::cout << i << " ";
        }
        
        // Move to the next line after finishing a row
        std::cout << "\n";
    }
    std::cout << "--- Pattern End ---\n";
}

/**
 * Navigation: Choice to repeat.
 */
bool askToRepeat() {
    while (true) {
        std::cout << "\nTry another pattern? (y/n): ";
        char input{};
        std::cin >> input;
        clearInputBuffer();
        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));
        if (input == 'y') return true;
        if (input == 'n') return false;
        std::cout << "❌ Please enter 'y' or 'n'.\n";
    }
}

void runProgram() {
    do {
        long long number = readPositiveInteger("Enter pattern height: ");
        printInvertedNumberPattern(number);
    } while (askToRepeat());
}

int main() {
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
