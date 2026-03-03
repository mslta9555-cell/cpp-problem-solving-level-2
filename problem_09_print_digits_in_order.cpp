// Problem_9: Mathematical Number Reversal
#include <iostream>
#include <limits>
#include <cctype>
#include <string>

/**
 * Cleanup: Clear the buffer to prevent program hang or skip
 */
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Input Handler: Ensures only positive long long numbers are accepted
 */
long long readNonNegativeInteger(const std::string& prompt)
{
    long long value{};
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value && value >= 0)
        {
            clearInputBuffer();
            return value;
        }

        std::cout << "❌ Invalid input! Please enter a non-negative number.\n";
        clearInputBuffer();
    }
}

/**
 * Logic: Construct the reverse number mathematically
 * Algorithm: Shift existing digits left (x10) then add the new remainder
 */
long long reverseNumbers (long long number)
{
    long long remainder{};
    long long reverse{};
    
    while (number > 0)
    {
        // 1. Get last digit
        remainder = number % 10;
        // 2. Remove last digit from original
        number /= 10;
        // 3. Append digit to the new reversed value
        reverse = (reverse * 10) + remainder;
    }
    return reverse;
}

/**
 * Prints the digits of the reversed number
 * Note: Printing a reversed number digit-by-digit returns it to original order!
 */
void PrintDigits(long long reverse)
{
    long long remainder{};
    std::cout << "Result: ";
    
    while (reverse > 0)
    {
        remainder = reverse % 10;
        reverse /= 10;
        std::cout << remainder << " ";
    }
    std::cout << std::endl;
}

/**
 * Navigation: Controls the main application loop
 */
bool askToRepeat()
{
    while (true)
    {
        std::cout << "\nTry another number? (y/n): ";
        char choice{};
        std::cin >> choice;
        clearInputBuffer();

        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));

        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Please enter 'y' or 'n'.\n";
    }
}

/**
 * Orchestrator: Connects logical components together
 */
void runProgram()
{
    do
    {
        long long number = readNonNegativeInteger("Enter a positive number: ");
        long long reverse = reverseNumbers(number);
        
        std::cout << "Reversed Value: " << reverse << std::endl;
        PrintDigits(reverse);
        
    } while (askToRepeat());
}

int main()
{
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
