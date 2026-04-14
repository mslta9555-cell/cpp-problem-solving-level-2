// Problem_24: Find Max, Min, and Stats in Random Array
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// Storage for array elements
struct stArray {
    int arr[100];
};

// Configuration settings for array generation
struct stConfig {
    int arrLength{0};
    int minRange{0}; 
    int maxRange{0};
};

// Structure to store calculation results
struct stResults {
    int maxNumber{0};
    int minNumber{0};
};

/**
 * Utility: Clears input buffer to handle errors
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Logic: Generates a random number within a range
 */
int randomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

/**
 * Input: Validates positive number entry
 */
int readPositiveNumber(const std::string& prompt) {
    int number{0};
    while (true) {
        std::cout << prompt;
        if (std::cin >> number && number > 0 && number <= 100) {
            clearInputBuffer();
            return number;
        }
        std::cout << "❌ Invalid! Enter a number between 1 and 100.\n";
        clearInputBuffer();
    }
}

/**
 * UI: Reads all configuration settings from user
 */
stConfig readData() {
    stConfig data;
    data.arrLength = readPositiveNumber("\nEnter number of elements (1-100): ");
    do {
        data.minRange = readPositiveNumber("Enter min range value: ");
        data.maxRange = readPositiveNumber("Enter max range value: ");
        if (data.minRange > data.maxRange)
            std::cout << "❌ Min cannot be greater than Max. Try again.\n";
    } while (data.minRange > data.maxRange);
    return data;
}

/**
 * Logic: Fills the array with random numbers based on config
 */
void fillArrayWithRandomNumbers(stArray &arr, const stConfig& data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/**
 * Core Algorithm: Finds Max and Min in a single loop (O(n))
 */
stResults getStats(const stArray &arr, const stConfig& data) {
    stResults results;
    // Start by assuming the first element is both max and min
    results.maxNumber = arr.arr[0];
    results.minNumber = arr.arr[0];

    for (int i = 1; i < data.arrLength; i++) {
        if (arr.arr[i] > results.maxNumber) {
            results.maxNumber = arr.arr[i];
        }

        if (arr.arr[i] < results.minNumber) {
            results.minNumber = arr.arr[i];
        }
    }
    return results;
}

/**
 * UI: Displays the array and the final results
 */
void printResults(const stArray &arr, const stConfig& data, const stResults& results) {
    std::cout << "\nArray Elements: ";
    for (int i = 0; i < data.arrLength; i++) {
        std::cout << arr.arr[i] << " ";
    }
    
    std::cout << "\n" << std::string(30, '-');
    std::cout << "\nMax Number is : " << results.maxNumber;
    std::cout << "\nMin Number is : " << results.minNumber;
    std::cout << "\n" << std::string(30, '-') << "\n";
}

/**
 * Control: Handles program repetition
 */
bool askToRepeat() {
    std::cout << "\nGenerate another random array? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Coordinator: Orchestrates the program flow
 */
void runProgram() {
    srand((unsigned)time(NULL)); // Seed random generator once
    do {
        stConfig data;
        stArray arr;
        stResults results;

        data = readData();
        fillArrayWithRandomNumbers(arr, data);
        
        results = getStats(arr, data);

        printResults(arr, data, results);

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
