// Problem_21: Array Frequency Counter
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// Structure to group array storage and its current length
struct stArrayData
{
    int arr[100];
    int arrLength{0};
};

/**
 * Utility to clear input buffer for clean re-entry
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Function to ensure the user enters a valid positive integer
 */
int readPositiveNumber(const std::string& prompt) {
    int number{0};
    while (true) {
        std::cout << prompt;
        if (std::cin >> number && number > 0) {
            clearInputBuffer();
            return number;
        }
        std::cout << "❌ Invalid input. Please enter a positive number.\n";
        clearInputBuffer();
    }
}

/**
 * Reads array size (validated 1-100) and populates elements
 */
void readArray(stArrayData &data)
{
    do
    {
        std::cout << "Enter number of elements : \n";
        std::cin >> data.arrLength;
        std::cout << "\n";
        
        // Validation for array boundaries
        if (data.arrLength <= 0 || data.arrLength > 100)
        {
            std::cout << "❌ Invalid size! Please enter between 1 and 100.\n";
            clearInputBuffer();
            continue;
        }   
        
    } while (data.arrLength <= 0 || data.arrLength > 100);
    
    // Looping to fill array elements
    for (int i = 0; i < data.arrLength; i++)
    {
        std::cout << "Elements [" << i + 1 << "] : ";
        std::cin >> data.arr[i];
    }
    std::cout << "\n";
}

/**
 * Displays all array elements on a single line
 */
void printArray(const stArrayData &data)
{
    for (int i = 0; i < data.arrLength; i++)
        std::cout << data.arr[i] << " ";
    
    std::cout << "\n";
}

/**
 * Core Logic: Counts how many times a number appears in the array
 */
int countOccurrences(const stArrayData &data, int number)
{
    int count = 0;
    for (int i = 0; i < data.arrLength ; i++)
    {
        if (data.arr[i] == number)
            count++;
    }
    return count;
}

/**
 * Formats and prints the final analysis results
 */
void printResult(const stArrayData &data, int numberToCheck)
{
    std::cout << "\nOriginal array : ";
    printArray(data);

    std::cout << "\nNumber " << numberToCheck;
    std::cout << " is repeated ";
    std::cout << countOccurrences(data, numberToCheck) << " time(s).\n";
}

/**
 * Asks user if they want to run the program again
 */
bool askToRepeat() {
    std::cout << "\nGenerate more? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Program Coordinator
 */
void runProgram() {
    do {
        stArrayData data;
        readArray(data);

        int numberToCheck = readPositiveNumber("Please enter Enter the number you want to check :");

        printResult(data, numberToCheck);

    } while (askToRepeat());
}

int main() { 
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
