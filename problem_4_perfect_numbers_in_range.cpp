// problem_4: Program to find all Perfect Numbers in a given range
#include <iostream>
#include <limits>
#include <cctype>
#include <cmath>

/**
 * Utility: Standard stream cleanup to prevent input-loop crashes
 */
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Input Layer: Validates that the input is both a number AND positive
 */
long long ReadInteger(const std::string& prompt)
{
    long long value{};
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cout << "❌ Invalid input! Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        
        if (value <= 0)
        {
            std::cout << "❌ Invalid input! Please enter a positive number.\n";   
            clearInputBuffer();
            continue;
        }

        clearInputBuffer(); 
        return value;
    }
}

/**
 * Core Logic: Determines if a number is perfect
 * Optimization: Loops only up to N/2, saving 50% of unnecessary iterations
 */
bool IsPerfectNumber(long long number)
{
    if (number <= 1) return false;

    long long sum = 1; 
    for (long long i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
            sum += i;
    }
    return sum == number;
}

/**
 * Presentation Layer: Iterates through the range and prints matches
 */
void PrintPerfectNumbersUpTo(long long number)
{
    bool found = false;
    std::cout << "\nPerfect Numbers found: ";

    for (long long i = 1; i <= number; i++)
    {
        if (IsPerfectNumber(i))
        {
            std::cout << i << "  ";
            found = true;
        }
    }

    if (!found)
        std::cout << "None.";

    std::cout << '\n';
}

/**
 * Flow Control: Handles user choice to restart the application
 */
bool askUserToRepeat()
{
    while (true)
    {
        std::cout << "\nRepeat program? (y/n): ";
        char input{};
        std::cin >> input;

        if (std::cin.fail())
        {
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        // Standardize input to lowercase for robustness
        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));

        if (input == 'y') return true;
        if (input == 'n') return false;

        std::cout << "❌ Invalid choice. Please enter 'y' or 'n'.\n";
    }
}

/**
 * Entry Point Wrapper
 */
void runProgram()
{
    do
    { 
      long long number = ReadInteger("Please enter the range limit: ");
      PrintPerfectNumbersUpTo(number);

    } while (askUserToRepeat());
}

int main()
{
    runProgram();
    std::cout << "\n🙏 Thanks for using this program.\n";
    return 0;
}
