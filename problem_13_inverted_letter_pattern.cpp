//Problem_13: Inverted Letter Pattern
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
        if (value > 26) {
            std::cout << "❌ Max allowed is 26 (A-Z).\n";
            clearInputBuffer();
            continue;
        }
        std::cout << "❌ Invalid input. Please enter a positive number.\n";
        std::cin.clear();
        clearInputBuffer();
    }
}

/**
 * Core Logic: Prints letters in descending order in an inverted triangle shape.
 * Example for height 3:
 * C C C
 * B B
 * A
 */
void printInvertedLetterPattern(long long number) 
{
    std::cout << "\n--- Pattern Start ---\n";

    for (char i = static_cast<char>('A'+ number - 1) ; i >=  'A' ; i--)
    {
        int repeatCount = i - 'A' + 1;
        for (int j = 1 ; j <= repeatCount; j++)
        {
            std::cout << i << " ";
        }
        
        std::cout<< "\n";
    }
    std::cout << "--- Pattern End ---\n";
    
    
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
        printInvertedLetterPattern(height);
    } while (askToRepeat());
}

int main() {
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}  
