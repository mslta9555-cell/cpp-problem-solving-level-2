// Problem_31: Copy Array in Reverse Order
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// Structures to organize array data separately
struct stArray_1 {
    int arr_1[100];
};

struct stArray_2 {
    int arr_2[100];
};

// Configuration for array length and random ranges
struct stConfig {
    int arrLength{0};
    int minRange{0}; 
    int maxRange{0};
};

/**
 * Utility: Standard function to clean input buffer
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Logic: Generates a random number within [From, To]
 */
int randomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

/**
 * Input: Validates numbers between 1 and 100
 */
int readPositiveNumber(const std::string& prompt) {
    int number{0};
    while (true) {
        std::cout << prompt;
        if (std::cin >> number && number > 0 && number <= 100) {
            clearInputBuffer();
            return number;
        }
        std::cout << "❌ Invalid! Range must be (1-100).\n";
        clearInputBuffer();
    }
}

/**
 * UI: Collects user settings for the program
 */
stConfig readData() {
    stConfig data;
    data.arrLength = readPositiveNumber("\nEnter number of elements: ");
    do {
        data.minRange = readPositiveNumber("Enter min range: ");
        data.maxRange = readPositiveNumber("Enter max range: ");
        if (data.minRange > data.maxRange)
            std::cout << "❌ Error: Min cannot be greater than Max!\n";
    } while (data.minRange > data.maxRange);
    return data;
}

/**
 * Logic: Populates the source array with random values
 */
void fillArraysWithRandomNumbers(stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr_1[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/**
 * UI: Overloaded functions to print different array types
 */
void PrintArray(const stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++)
        std::cout << "[" << arr.arr_1[i] << "] ";    
}

void PrintArray(const stArray_2 &arr2, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++)
        std::cout << "[" << arr2.arr_2[i] << "] ";    
}

/**
 * CORE LOGIC: Reverse Copying
 * Uses the mathematical mapping: TargetIndex = (Total - 1) - CurrentIndex
 */
void copyArrayInReverseOrder(stArray_2 &arr2, const stArray_1 &arr, const stConfig &data)
{
    for (int i = 0; i < data.arrLength; i++)
    {
        // Example: If length is 5, i=0 copies element at index 4
        arr2.arr_2[i] = arr.arr_1[data.arrLength - 1 - i];
    }
}

/**
 * Control: Loop to rerun the program
 */
bool askToRepeat() {
    std::cout << "\n\nTry another set? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Orchestrator: Connects logic, UI, and data flow
 */
void runProgram() {
    srand((unsigned)time(NULL)); 
    do {
        stArray_1 arr_1;
        stArray_2 arr_2;

        stConfig data = readData(); // Initialize config first

        fillArraysWithRandomNumbers(arr_1, data);
        copyArrayInReverseOrder(arr_2, arr_1, data);

        std::cout << "\nArray 1 Elements :  ";
        PrintArray(arr_1, data);

        std::cout << "\nArray 2 Elements after copy :  ";
        PrintArray(arr_2, data);

    } while (askToRepeat());
}

int main() { 
    runProgram();
}
