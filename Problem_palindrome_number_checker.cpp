// Problem_10: Palindrome Number Checker
#include <iostream>
#include <limits>
#include <cctype>

/**
 * Standard utility to clear the input buffer.
 * This prevents infinite loops if the user enters a string instead of a number.
 */
void clearInputBuffer()
{
    std::cin.clear(); // Reset error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid characters
}

/**
 * Validates and reads a positive integer from the user.
 * It ensures the program doesn't crash on invalid data types.
 */
long long readPositiveInteger(const std::string& prompt)
{
    long long value{0};

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Check if input is a non-numeric value
        if (std::cin.fail())
        {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        
        // Logical validation: Palindrome logic usually applies to positive integers
        if (value <= 0)
        {
            std::cout << "Invalid input. Please enter a positive number: ";
            clearInputBuffer();
            continue;
        }
        return value;
    }
}

/**
 * Reverses a number mathematically.
 * Example: Input 123 -> Process (3, 32, 321) -> Returns 321.
 */
long long reverseNumber(long long value)
{
    long long remainder{0};
    long long reversed{0};

    while (value > 0)
    {
        remainder = value % 10;          // Extract the last digit
        value /= 10;                     // Remove the last digit from original
        reversed = reversed * 10 + remainder; // Append the digit to the new reversed number
    }
    return reversed;
}

/**
 * Core Logic: A number is a Palindrome if it reads the same forwards and backwards.
 */
bool isPalindrome(long long value) 
{
    // Compare the original number with its reversed version
    return value == reverseNumber(value);
}

/**
 * UI Layer: Displays the analysis results in a readable format.
 */
void printResult(long long original, long long reversed) {
    std::cout << "\n------------------------------";
    std::cout << "\nOriginal Number: " << original;
    std::cout << "\nReversed Number: " << reversed << "\n";
    
    // Final check and output
    if (isPalindrome(original))
        std::cout << "✅ Result: Yes, it is a Palindrome number.\n";
    else    
        std::cout << "❌ Result: No, it is NOT a Palindrome number.\n";
    std::cout << "------------------------------\n";
}

/**
 * Navigation: Handles the user's choice to repeat the process.
 */
bool askToRepeat()
{
    while (true)
    {
        std::cout << "\nTry another number? (y/n): ";
        char input{};
        std::cin >> input;
        clearInputBuffer();

        // Convert to lowercase for better User Experience (accepts 'Y' or 'y')
        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));
        if (input == 'y') return true;
        if (input == 'n') return false;

        std::cout << "❌ Please enter 'y' or 'n'.\n";
    }
}

/**
 * Orchestrator: Wraps the application flow in a clean loop.
 */
void runProgram()
{
    do
    {
       long long originalValue = readPositiveInteger("Please enter a positive number: ");
       long long reversedValue = reverseNumber(originalValue);
        
       printResult(originalValue, reversedValue);

    } while (askToRepeat());
}

int main() 
{
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
