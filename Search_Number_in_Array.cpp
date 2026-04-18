// Problem_33: Search for a Number in Array
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// Container for our array data
struct stArray_1 {
    int arr_1[100];
};

// Global configurations for the program
struct stConfig {
    int arrLength{0};
    int minRange{0}; 
    int maxRange{0};
    int checkNumber{0}; // The number user wants to find
};

/**
 * Utility: Fixes cin issues by clearing the buffer
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
 * Input: Reads and ensures the number is between 1-100
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
 * UI: Gets Array Length and Random Range from user
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
 * Logic: Fills the array with random numbers based on user range
 */
void fillArraysWithRandomNumbers(stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr_1[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/**
 * UI: Prints the current array elements
 */
void PrintArray(const stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++)
        std::cout << "[" << arr.arr_1[i] << "] ";    
}

/**
 * CORE LOGIC: Linear Search
 * Loops through the array and returns the index if found, else returns -1
 */
int FindNumberPositionInArray(const stArray_1 &arr, stConfig &data)
{
    for (int i = 0; i < data.arrLength; i++)
    {
        if (data.checkNumber == arr.arr_1[i])
        {
            return i; // Found it! Return the position (Index)
        }   
    }
    return -1; // Not found in the whole array
}

/**
 * Input: Gets the target number to search for
 */
void readSearchNumber(stConfig &data)
{
    data.checkNumber = readPositiveNumber("\nPlease enter a number to search for : ");
}

/**
 * UI: Displays the final search result
 */
void printresult(stArray_1 &arr, stConfig &data)
{
    int index = FindNumberPositionInArray(arr, data);
    
    std::cout << "\nNumber you are looking for is: " << data.checkNumber;
    
    if (index != -1)
    {
        std::cout << "\n✅ The number was found at index: " << index;
        std::cout << "\n✅ The number's order in array is: " << index + 1;
    }
    else
    {
        std::cout << "\n❌ The number is not found :-(";
    }
}

/**
 * Control: Asks if the user wants to try again
 */
bool askToRepeat() {
    std::cout << "\n\nTry another set? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Orchestrator: Runs the program steps in order
 */
void runProgram() {
    srand((unsigned)time(NULL)); // Reset random seed
    do {
        stArray_1 arr_1;
        stConfig data = readData(); 

        fillArraysWithRandomNumbers(arr_1, data);

        std::cout << "\nArray Elements : ";
        PrintArray(arr_1, data);

        readSearchNumber(data); // Get target number
        printresult(arr_1, data); // Search and print

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
