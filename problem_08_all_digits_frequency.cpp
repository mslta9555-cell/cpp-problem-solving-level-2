// Problem_8: Count frequency of all digits in a number
#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// Utility: Clear input buffer
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Reads a valid non-negative integer
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

// Core Logic: Count how many times a digit appears
int countDigitOccurrences(long long number, int digitToCheck)
{
    if (number == 0 && digitToCheck == 0)
        return 1;

    int frequency{};
    while (number > 0)
    {
        int remainder = number % 10;
        if (remainder == digitToCheck)
            frequency++;

        number /= 10;
    }
    return frequency;
}

// Presentation: Print frequency of all digits
void printAllDigitsFrequency(long long number)
{
    std::cout << "\nDigit Frequency Analysis:\n";

    for (int digit = 0; digit <= 9; digit++)
    {
        int freq = countDigitOccurrences(number, digit);
        if (freq > 0)
        {
            std::cout << "Digit " << digit
                      << " Frequency is "
                      << freq << " Time(s).\n";
        }
    }
}

// Controls repetition
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

void runProgram()
{
    do
    {
        long long number = readNonNegativeInteger("Enter a positive number: ");
        printAllDigitsFrequency(number);

    } while (askToRepeat());
}

int main()
{
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
