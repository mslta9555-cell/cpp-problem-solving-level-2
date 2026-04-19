// Problem_36: Dynamic Filtering - Copying Odd Numbers Only
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// Container for the source array
struct stArray_1 {
    int arr_1[100];
};

// Container for the filtered array with a dynamic length tracker
struct stArray_2 {
    int arr_2[100];
    int length = 0; 
};

// Application settings
struct stConfig {
    int arrLength{0};
    int minRange{0}; 
    int maxRange{0};
};

// Standard helper to clean input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Generates a random number within range
int randomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

// Logic: Checks if the number is odd (Not divisible by 2)
bool isOddNumber(int number)
{
    return (number % 2 != 0);
}

// UI: Validates positive input (1-100)
int readPositiveNumber(const std::string& prompt) {
    int number{0};
    while (true) {
        std::cout << prompt;
        if (std::cin >> number && number > 0 && number <= 100) {
            clearInputBuffer();
            return number;
        }
        std::cout << "❌ Invalid! Range (1-100).\n";
        clearInputBuffer();
    }
}

// UI: Collects all configuration from user
stConfig readData() {
    stConfig data;
    data.arrLength = readPositiveNumber("\nEnter number of elements: ");
    do {
        data.minRange = readPositiveNumber("Enter min range: ");
        data.maxRange = readPositiveNumber("Enter max range: ");
        if (data.minRange > data.maxRange)
            std::cout << "❌ Min > Max! Try again.\n";
    } while (data.minRange > data.maxRange);
    return data;
}

// Populates Array 1 with random values
void fillArraysWithRandomNumbers(stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr_1[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/** * Logic: Adds a number to the end of the second array 
 * and automatically updates its current length index.
 */
void addArrayElement(int number, stArray_2 &arr_2)
{
    if (arr_2.length >= 100) {
        std::cout << "⚠️ Array is full!\n";
        return;
    }
    arr_2.arr_2[arr_2.length++] = number;
}

/**
 * Logic: Filtering Process
 * Iterates through Array 1 and copies only Odd numbers to Array 2
 */
void filterOddNumbers(stArray_1 &arr, const stConfig &data, stArray_2 &arr_2)
{
    for (int i = 0; i < data.arrLength; i++)
    {
        if (isOddNumber(arr.arr_1[i]))
        {
            addArrayElement(arr.arr_1[i], arr_2);
        }
    }
}

// UI: Prints Array 1 based on user-defined length
void PrintArray(const stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++)
        std::cout << "[" << arr.arr_1[i] << "] ";    
}

// UI: Prints Array 2 based on its own actual filtered length
void PrintArray(const stArray_2 &arr_2) {
    for (int i = 0; i < arr_2.length; i++)
        std::cout << "[" << arr_2.arr_2[i] << "] ";    
}

// Control: Reruns the program if user wants
bool askToRepeat() {
    std::cout << "\n\nTry another set? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

// Orchestrator: Main program flow
void runProgram() {
    srand((unsigned)time(NULL)); 
    do {
        stArray_1 arr1;
        stArray_2 arr2; 
        stConfig data = readData();

        fillArraysWithRandomNumbers(arr1, data);
        filterOddNumbers(arr1, data, arr2); // Filtering happens here

        std::cout << "\nArray 1 Elements (Random): ";
        PrintArray(arr1, data);

        std::cout << "\nArray 2 Elements (Odd Only): ";
        PrintArray(arr2); 

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
