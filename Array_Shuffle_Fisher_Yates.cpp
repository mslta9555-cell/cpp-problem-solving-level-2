// Problem_30: Shuffle Array Elements (Fisher-Yates Algorithm)
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// Structure to hold the array data
struct stArray_1 {
    int arr_1[100];
};

// Structure for user-defined configurations
struct stConfig {
    int arrLength{0};
    int minRange{0}; 
    int maxRange{0};
};

/**
 * Utility: Clears the input buffer to prevent program errors
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Logic: Swaps two integers in memory using references (&)
 */
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * Logic: Generates a random number within a range [From, To]
 */
int randomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

/**
 * Input: Reads and validates a positive number from user
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
 * UI: Reads all setup data (Length, Min, Max)
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
 * Logic: Fills the array with random numbers based on config
 */
void fillArraysWithRandomNumbers(stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr_1[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/**
 * UI: Displays the array elements in brackets
 */
void PrintArray(const stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++)
        std::cout << "[" << arr.arr_1[i] << "] ";    
}

/**
 * CORE LOGIC: Shuffles the array by swapping each element 
 * with a random one from the remaining unshuffled portion.
 */
void ShuffleArray(stArray_1 &arr, const stConfig &data) {
    // Start from the last element and move backwards
    for (int i = data.arrLength - 1; i > 0; i--) {
        // Pick a random index 'j' from 0 up to 'i'
        int j = randomNumber(0, i);
        // Swap current element with the randomly chosen one
        Swap(arr.arr_1[i], arr.arr_1[j]);
    }
}

/**
 * UI: Asks the user if they want to repeat the process
 */
bool askToRepeat() {
    std::cout << "\n\nTry another set? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Coordination: Orchestrates the overall program flow
 */
void runProgram() {
    srand((unsigned)time(NULL)); // Seed random generator once
    do {
        stArray_1 arr1;
        stConfig data = readData();

        fillArraysWithRandomNumbers(arr1, data);

        std::cout << "\nArray before shuffle: ";
        PrintArray(arr1, data);

        ShuffleArray(arr1, data); // Apply the shuffle logic

        std::cout << "\nArray after shuffle : ";
        PrintArray(arr1, data);

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
