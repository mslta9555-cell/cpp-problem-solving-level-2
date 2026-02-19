// problem_3: Perfect Number Checker
#include <iostream>
#include <limits>
#include <cctype>
#include <cmath>

// Global configurations for easy maintenance
namespace config
{
    constexpr int kFirstDivisor  = 1;
}

// Function to handle input stream cleanup and prevent infinite loops
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Robust input handler to ensure we only get valid positive long long values
long long ReadInteger(const std::string& prompt)
{
    long long value{};
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Validation: Check if input is a non-numeric string
        if (std::cin.fail())
        {
            std::cout << "❌ Invalid input! Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        
        // Logical Validation: Perfect numbers must be positive
        if (value <= 0)
        {
            std::cout << "❌ Invalid input! Please enter a positive number.\n";   
            clearInputBuffer();
            continue;
        }

        clearInputBuffer(); // Clean buffer after successful read
        return value;
    }
}

// Business Logic: Checks if the sum of divisors equals the number itself
bool IsPerfectNumber(long long number)
{
    long long sum{};
    // Note: Efficiency can be improved further by looping to sqrt(number)
    for (long long i = config::kFirstDivisor ; i < number; i++)
    {
        if (number % i == 0)
           sum += i;
    }
    return sum == number;
}

// UI Function: Responsible only for displaying the final result
void PrintResult(const bool& result, const long long& number)
{
    if (result)
        std::cout << "\n " << number << " Is Perfect Number ✅\n";
    else 
        std::cout << "\n " << number << " Is Not Perfect Number ❌\n";
}

// Controls the application flow and user choice to repeat
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
        // Normalize input to lowercase for better User Experience
        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));

        if (input == 'y') return true;
        if (input == 'n') return false;

        std::cout << "❌ Invalid choice. Please enter 'y' or 'n'.\n";
    }
}

// Orchestrator: Wraps the core logic and repeat loop
void runProgram()
{
    do
    { 
      long long number = ReadInteger("Please enter a Positive number : ");
      bool result = IsPerfectNumber(number);
      PrintResult(result, number);

    } while (askUserToRepeat());
}

// Entry Point
int main()
{
    runProgram();
    std::cout << "\n🙏 Thanks for using this program.\n";
    return 0;
} 
