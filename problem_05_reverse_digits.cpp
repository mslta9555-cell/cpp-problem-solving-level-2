// Problem_5: Print digits of a number in reverse order
#include <iostream>
#include <limits>
#include <cctype>
#include <string>

/**
 * Utility: Standard input cleanup
 */
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Robust Integer Reader
 */
long long readInteger(const std::string& prompt)
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
 * Core Logic: Prints each digit separated by a space
 * Process: Uses modulo 10 to isolate the last digit and division to discard it.
 */
void printDigits(long long number)
{
    if (number == 0)
    {
        std::cout << "Digits: 0\n";
        return;
    }

    std::cout << "Digits in reverse order: ";
    while (number > 0)
    {
        std::cout << "["<< number % 10 << "] " ;
        number /= 10;
    }
    std::cout << '\n';
}

/**
 * Navigation: User choice to re-run the app
 */
bool askUserToRepeat()
{
    while (true)
    {
        std::cout << "\nTry another number? (y/n): ";
        char input{};
        std::cin >> input;
        clearInputBuffer();

        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));
        if (input == 'y') return true;
        if (input == 'n') return false;

        std::cout << "❌ Please enter 'y' or 'n'.\n";
    }
}

void runProgram()
{
    do
    { 
        long long number = readInteger("Please enter a positive number: ");
        printDigits(number);
    } while (askUserToRepeat());
}

int main()
{
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
