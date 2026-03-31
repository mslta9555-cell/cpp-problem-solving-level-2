// Problem_18: Random Number Generator within Range
#include <iostream>
#include <limits>
#include <string>
#include <cstdlib> 
#include <ctime>   

/**
 * Utility to clear input buffer
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Structure to group range-related data
 */
struct RangeData
{
    int from{0};
    int to{0};
    int count{0}; // How many numbers to generate
};

/**
 * Ensures user inputs a positive integer
 */
int readPositiveNumber(const std::string& prompt)
{
    int number{0};
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> number && number > 0)
        {
            clearInputBuffer();
            return number;
        }
        std::cout << "❌ Invalid input! Please enter a positive number.\n";
        clearInputBuffer();
    }
}

/**
 * Reads and validates the entire range structure
 */
RangeData readRangeValues()
{
    RangeData data;
    while (true)
    {
        data.from = readPositiveNumber("Please enter the start of the range: ");
        data.to = readPositiveNumber("Please enter the end of the range: ");

        if (data.from >= data.to)
        {
            std::cout << "❌ Invalid range! Start must be less than end. Try again.\n";
            continue;
        }
        break;
    }
    data.count = readPositiveNumber("How many random numbers to generate? ");
    return data;
}

/**
 * Logic: Returns a random number between from and to (inclusive)
 * Formula: rand() % (Max - Min + 1) + Min
 */
int generateRandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

/**
 * UI: Prints the generated list
 */
void printRandomNumbers(RangeData data)
{
    std::cout << "\n--- Generating " << data.count << " numbers between [" 
              << data.from << " and " << data.to << "] ---\n";
              
    for (int i = 1; i <= data.count; i++)
    {
        std::cout << "Number [" << i << "] : " << generateRandomNumber(data.from, data.to) << "\n";
    }
}

bool askToRepeat() {
    std::cout << "\nTry another range? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

void runProgram() {
    // Senior Tip: Seed the random generator ONCE using current time
    srand((unsigned)time(NULL));

    do {
        RangeData data = readRangeValues();
        printRandomNumbers(data);
        std::cout << "====================================\n";
    } while (askToRepeat());
}

int main() {
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
