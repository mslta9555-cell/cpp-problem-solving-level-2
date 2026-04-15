// Problem_27: Copying an Array using independent Structs
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// Independent struct for the first array
struct stArray_1 {
    int arr_1[100];
};

// Independent struct for the second array
struct stArray_2 {
    int copiedArr[100];
};

// Holds user settings for array length and random ranges
struct stConfig {
    int arrLength{0};
    int minRange{0}; 
    int maxRange{0};
};

/**
 * Utility: Resets the input stream buffer
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Logic: Returns a random integer between From and To
 */
int randomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

/**
 * Input: Reads and validates a positive integer (1-100)
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
 * UI: Gets data length and range from user
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
 * Logic: Populates the first array with random numbers
 */
void fillArrayWithRandomNumbers(stArray_1 &arr, stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr_1[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/**
 * UI: Prints the first struct array
 */
void PrintArray(const stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        std::cout << arr.arr_1[i] << " ";
    }
}

/**
 * UI: Overloaded Print function to handle the second struct array
 */
void PrintArray(const stArray_2 &arr_2, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        std::cout << arr_2.copiedArr[i] << " ";
    }
}

/**
 * Logic: Copies each element from Struct 1 to Struct 2
 */
void CopyArray(const stArray_1 &arr, stArray_2& arr_2, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr_2.copiedArr[i] = arr.arr_1[i];
    }
}

/**
 * Control: Asks if the user wants to rerun the process
 */
bool askToRepeat() {
    std::cout << "\nGenerate another random array? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Orchestrates the program execution flow
 */
void runProgram() {
    srand((unsigned)time(NULL)); 
    do {
        stArray_1 arr;
        stConfig data;
        stArray_2 arr_2;

        data = readData();

        fillArrayWithRandomNumbers(arr, data);
        
        // Always copy before you print the second array
        CopyArray(arr, arr_2, data); 

        std::cout << "\nArray 1 Elements : ";
        PrintArray(arr, data);

        std::cout << "\nArray 2 Elements after copy : ";
        PrintArray(arr_2, data); // Works because of Function Overloading
        
        std::cout << "\n";

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
