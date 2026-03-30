// Problem_15: Word Combination Generator (AAA to ZZZ)
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
 * Input Layer: Reads a number between 1 and 26 to define the character range.
 */
long long readPositiveInteger(const std::string& prompt) {
    long long value{0};
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value > 0 && value <= 26) {
            clearInputBuffer();
            return value;
        }
        std::cout << "❌ Invalid input. Please enter a number between 1 and 26.\n";
        std::cin.clear();
        clearInputBuffer();
    }
}

/**
 * Core Logic: Generates all 3-letter combinations based on the given range.
 * This is a Triple Nested Loop (O(N^3) Complexity).
 */
void PrintWordsFromAAAtoZZZ(long long number)
{
    std::cout << "\n--- Word Combinations ---\n";
    
    // Define the ending character based on the input number
    char EndChar = (char)('A' + number - 1);

    // Loop 1: Controls the FIRST letter (Thousands place logic)
    for (char i = 'A'; i <= EndChar; i++)
    {
        // Loop 2: Controls the SECOND letter (Hundreds place logic)
        for (char j = 'A'; j <= EndChar; j++)
        {
            // Loop 3: Controls the THIRD letter (Units place logic)
            for (char k = 'A'; k <= EndChar; k++)
            {
                // Print the current combination
                std::cout << i << j << k << "\n";
            }  
        }
        // Visual separator after each major group (e.g., after all AAx, ABx)
        std::cout << "-----\n";
    }
}

/**
 * Navigation: User choice to repeat.
 */
bool askToRepeat() {
    while (true) {
        std::cout << "\nTry another range? (y/n): ";
        char input{};
        std::cin >> input;
        clearInputBuffer();
        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));
        if (input == 'y') return true;
        if (input == 'n') return false;
        std::cout << "❌ Please enter 'y' or 'n'.\n";
    }
}

/**
 * Orchestrator: Connects user input to the combination logic.
 */
void runProgram() {
    do {
        long long range = readPositiveInteger("Enter alphabet range (1-26): ");
        PrintWordsFromAAAtoZZZ(range);
    } while (askToRepeat());
}

int main() {
    runProgram();
    std::cout << "\n🙏 Happy Coding! See you next time!\n";
    return 0;
}
