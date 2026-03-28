// Problem_12: Normal Number Pattern (Ascending Triangle)
#include <iostream>
#include <limits>
#include <cctype>

/**
 * Standard utility to clear the input buffer.
 * Essential for robust CLI applications to prevent "skipping" inputs.
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Input Layer: Reads a positive integer from the console.
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
 * Core Logic: Prints a right-angled triangle pattern.
 * Logic:
 * Row 1 (i=1): Print '1' (j=1 time)
 * Row 2 (i=2): Print '2' (j=2 times)
 * Row 3 (i=3): Print '3' (j=3 times)
 */
void printNormalNumberPattern(long long number) {
    std::cout << "\n--- Generated Pattern ---\n";
    // Outer loop controls the current ROW number (1 to N)
    for (long long i = 1; i <= number; i++)
    {
        // Inner loop controls the COLUMNS (prints i times per row)
        for (long long j = 1; j <= i; j++) {
            std::cout << i << " ";
        }
        
        // After finishing all columns in a row, move to the next line
        std::cout << "\n";
    }
    std::cout << "--------------------------\n";
}

/**
 * Navigation: Reusable logic to ask for a repeat.
 */
bool askToRepeat() {
    while (true) {
        std::cout << "\nTry another pattern? (y/n): ";
        char input{};
        std::cin >> input;
        clearInputBuffer();
        
        // Normalize input to lowercase
        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));
        
        if (input == 'y') return true;
        if (input == 'n') return false;
        std::cout << "❌ Please enter 'y' or 'n'.\n";
    }
}

/**
 * Orchestrator: Connects user input to logic.
 */
void runProgram() {
    do {
        long long height = readPositiveInteger("Enter pattern height: ");
        printNormalNumberPattern(height);
    } while (askToRepeat());
}

int main() {
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
