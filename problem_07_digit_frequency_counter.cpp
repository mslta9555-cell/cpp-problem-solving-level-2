// Problem_7: Count occurrences of a specific digit in a number
#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// ==============================
// Data Model
// ==============================
struct Number
{
    long long value{};
    int digit{};
};

// ==============================
// Utility Functions
// ==============================
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Reads a non-negative integer safely
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

// Reads a single digit (0–9)
int readSingleDigit(const std::string& prompt)
{
    int digit{};
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> digit && digit >= 0 && digit <= 9)
        {
            clearInputBuffer();
            return digit;
        }

        std::cout << "❌ Invalid input! Please enter a single digit (0–9).\n";
        clearInputBuffer();
    }
}

// ==============================
// Input Layer
// ==============================
Number readNumber()
{
    return {
        readNonNegativeInteger("Enter a positive number: "),
        readSingleDigit("Enter a digit to check (0–9): ")
    };
}

// ==============================
// Business Logic
// ==============================
long long countDigitOccurrences(Number num)
{
    // Special case: number = 0
    if (num.value == 0)
        return (num.digit == 0) ? 1 : 0;

    long long count{};
    while (num.value > 0)
    {
        if (num.value % 10 == num.digit)
            ++count;

        num.value /= 10;
    }
    return count;
}

// ==============================
// Presentation Layer
// ==============================
void printResult(const Number& num, long long count)
{
    std::cout << "\nDigit " << num.digit
              << " appears " << count
              << " time(s) in number " << num.value << ".\n";
}

// ==============================
// Flow Control
// ==============================
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
        Number num = readNumber();
        long long result = countDigitOccurrences(num);
        printResult(num, result);

    } while (askToRepeat());
}

// ==============================
// Entry Point
// ==============================
int main()
{
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
