// Problem_14: Normal Letter Pattern (Ascending Triangle)
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
 * Input Layer: Reads a positive integer (Range 1-26).
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
 * Core Logic: Prints letters in ascending triangle shape.
 * Example for height 3:
 * A
 * B B
 * C C C
 */
void PrintLetterPattern(long long number) 
{
    std::cout << "\n--- Pattern Start ---\n";

    // Outer loop: Starts from 'A' and moves forward (i++)
    for (char i = 'A'; i <= 'A' + number - 1; i++)
    {
        // Calculate how many times the current letter should repeat
        int repeatCount = i - 'A' + 1;

        // Inner loop: Prints the letter 'i', exactly 'repeatCount' times
        for (int j = 1; j <= repeatCount; j++)
        {
          std::cout << i << " ";
        }
        
        // Move to the next line after finishing the row
        std::cout << "\n";
    }
    
    std::cout << "--- Pattern End ---\n";
}

/**
 * Navigation: User choice to repeat.
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

/**
 * Orchestrator: Connects user input to logic.
 */
void runProgram() {
    do {
        long long height = readPositiveInteger("Enter pattern height (1-26): ");
        PrintLetterPattern(height);
    } while (askToRepeat());
}

int main() {
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
