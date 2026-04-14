// Problem_26: Array Statistics (Max, Min, Sum, Average)
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// Holds the fixed-size array data
struct stArray {
    int arr[100];
};

// Holds user configurations for array generation
struct stConfig {
    int arrLength{0};
    int minRange{0}; 
    int maxRange{0};
};

// Holds the calculated statistical results
struct stResults {
    int maxNumber{0};
    int minNumber{0};
    int sumNumbers{0};
    float average{0};
};

/**
 * Utility to clear input buffer to prevent input errors
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Returns a random number within a specified range [From, To]
 */
int randomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

/**
 * Ensures user enters a valid positive number within array bounds
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
 * Reads array length and value ranges from the user
 */
stConfig readData() {
    stConfig data;
    data.arrLength = readPositiveNumber("\nEnter number of elements (1-100): ");
    do {
        data.minRange = readPositiveNumber("Enter min range value: ");
        data.maxRange = readPositiveNumber("Enter max range value: ");
        
        // Range validation check
        if (data.minRange > data.maxRange)
            std::cout << "❌ Min cannot be greater than Max. Try again.\n";
            
    } while (data.minRange > data.maxRange);
    return data;
}

/**
 * Populates the array with random numbers based on stConfig
 */
void fillArrayWithRandomNumbers(stArray &arr, const stConfig& data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/**
 * Calculates Max, Min, Sum, and Average in a single pass (O(n))
 */
stResults getStats(const stArray &arr, const stConfig& data) {
    stResults results;
    
    // Initializing results with the first element of the array
    results.maxNumber = arr.arr[0];
    results.minNumber = arr.arr[0];
    results.sumNumbers = arr.arr[0];

    // Iterating through the array to update statistics
    for (int i = 1; i < data.arrLength; i++) {
        
        if (arr.arr[i] > results.maxNumber) {
            results.maxNumber = arr.arr[i];
        }

        if (arr.arr[i] < results.minNumber) {
            results.minNumber = arr.arr[i];
        }

        results.sumNumbers += arr.arr[i];    
    }

    // Calculating average (Integer division here)
    results.average = (float)results.sumNumbers / data.arrLength;
    return results;
}

/**
 * Prints the array elements and the calculated results summary
 */
void printResults(const stArray &arr, const stConfig& data, const stResults& results) 
{
    std::cout << "\nArray Elements: ";
    for (int i = 0; i < data.arrLength; i++) {
        std::cout << arr.arr[i] << " ";
    }
    
    std::cout << "\n" << std::string(30, '-');
    std::cout << "\nMax Number is : " << results.maxNumber;
    std::cout << "\nMin Number is : " << results.minNumber;
    std::cout << "\nSum Of all Number is : " << results.sumNumbers;
    std::cout << "\nAverage Of all Number is : " << results.average;
    std::cout << "\n" << std::string(30, '-') << "\n";
}

/**
 * Handles the repeat logic to allow multiple runs
 */
bool askToRepeat() {
    std::cout << "\nGenerate another random array? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Orchestrates the overall program logic flow
 */
void runProgram() {
    srand((unsigned)time(NULL)); // Seeding the random generator
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
