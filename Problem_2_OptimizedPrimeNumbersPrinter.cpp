//Problem_2: Optimized Prime Numbers Printer
#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cmath>

// Global settings for the application
namespace config    
{
    constexpr int StartFrom = 1;
}

// Resets the input stream and clears the buffer to handle errors
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Prompts user for a positive integer and validates the input
int readNonNegativeInt(const std::string& prompt)
{
    int value{};
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        // Ensure input is a number and greater than zero
        if (std::cin.fail() || value <= 0)
        {
            std::cout << "❌ Invalid input! Please enter a non-negative integer.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return value;
    }
}

// Efficiently checks if a number is prime using the 6k +/- 1 method
bool isPrime(int num)
{
    if (num <= 1) return false;      
    if (num <= 3) return true;       
    if (num % 2 == 0 || num % 3 == 0) return false;

    // Optimization: check divisibility up to the square root
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }

    return true;
}

// Iterates through the range and prints prime numbers
void printResult(const int& number)
{
    std::cout << "\n Prime Numbers from " << config::StartFrom << " To " << number << " are :\n";

    for (int i = config::StartFrom; i <= number; i++)
    {
        if (isPrime(i))
        {
            std::cout << i << "  ";
        }
    }
}

// Asks the user if they want to restart the application
bool shouldRepeat()
{
    char choice{};
    while (true)
    {
        std::cout << "\nDo you want to repeat the program? (y/n): ";
        std::cin >> choice;
        clearInputBuffer();

        // Convert choice to lowercase for flexible input
        choice = static_cast<char>(std::tolower(static_cast<unsigned char>(choice)));
        if (choice == 'y') return true;
        if (choice == 'n') return false;

        std::cout << "❌ Invalid selection. Please enter 'y' or 'n'.\n";
    }
}

// Main logic controller for the application flow
void runApplication()
{
    do
    {
        int num{ readNonNegativeInt("Please enter a number: ") };
        printResult(num);        
    } while (shouldRepeat());
}

// Application entry point
int main()
{
    runApplication();
    std::cout << "\n🙏 Thanks for using this program!\n";
    return 0;
}
