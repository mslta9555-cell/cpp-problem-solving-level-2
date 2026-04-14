// Problem_25: Sum and Stats of Random Array
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// Struct to hold the array data
struct stArray {
    int arr[100];
};

// Struct to hold array generation settings
struct stConfig {
    int arrLength{0};
    int minRange{0}; 
    int maxRange{0};
};

// Struct to store the final calculated statistics
struct stResults {
    int maxNumber{0};
    int minNumber{0};
    int sumNumbers{0};
};

/**
 * Utility to clear the input buffer and reset cin state
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Helper to generate a random integer within a specific range
 */
int randomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

/**
 * Input function that ensures only positive numbers (1-100) are accepted
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
 * Collects array size and random range boundaries from the user
 */
stConfig readData() {
    stConfig data;
    data.arrLength = readPositiveNumber("\nEnter number of elements (1-100): ");
    do {
        data.minRange = readPositiveNumber("Enter min range value: ");
        data.maxRange = readPositiveNumber("Enter max range value: ");
        
        // Validation: prevent min from being larger than max
        if (data.minRange > data.maxRange)
            std::cout << "❌ Min cannot be greater than Max. Try again.\n";
            
    } while (data.minRange > data.maxRange);
    return data;
}

/**
 * Fills the array struct with random values using the config settings
 */
void fillArrayWithRandomNumbers(stArray &arr, const stConfig& data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/**
 * Core Logic: Calculates Max, Min, and Sum in a single pass (O(n))
 */
stResults getStats(const stArray &arr, const stConfig& data) {
    stResults results;
    
    // Initializing with the first element of the array
    results.maxNumber = arr.arr[0];
    results.minNumber = arr.arr[0];
    results.sumNumbers = arr.arr[0];
    
    // Loop starting from the second element
    for (int i = 1; i < data.arrLength; i++) {
        
        if (arr.arr[i] > results.maxNumber) {
            results.maxNumber = arr.arr[i];
        }

        if (arr.arr[i] < results.minNumber) {
            results.minNumber = arr.arr[i];
        }

        results.sumNumbers += arr.arr[i];    
    }
    return results;
}

/**
 * Output function to display the array content and its stats
 */
void printResults(const stArray &arr, const stConfig& data, const stResults& results) {
    std::cout << "\nArray Elements: ";
    for (int i = 0; i < data.arrLength; i++) {
        std::cout << arr.arr[i] << " ";
    }
    
    std::cout << "\n" << std::string(30, '-');
    std::cout << "\nMax Number is : " << results.maxNumber;
    std::cout << "\nMin Number is : " << results.minNumber;
    std::cout << "\nSum Of all Number is : " << results.sumNumbers;
    std::cout << "\n" << std::string(30, '-') << "\n";
}

/**
 * Asks user if they want to repeat the entire process
 */
bool askToRepeat() {
    std::cout << "\nGenerate another random array? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Orchestrates the program flow
 */
void runProgram() {
    srand((unsigned)time(NULL)); // Initialize random seed
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
