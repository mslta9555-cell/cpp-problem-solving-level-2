// Problem_22: Random Array Generator with Configuration Struct
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// Holds the array data only
struct stArray {
    int arr[100];
};

// Holds the configuration settings for the array
struct stConfig
{
    int arrLength{0};
    int min{0};
    int max{0};
};

/**
 * Clears the input stream to prevent infinite loops on invalid input
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Returns a random number between From and To inclusive
 */
int randomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

/**
 * Validates that the input is a positive number within array limits
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
 * Reads all necessary configuration data from the user
 */
stConfig readdata()
{
    stConfig data;

    data.arrLength = readPositiveNumber("\nEnter number of elements (1-100): ");

    do
    {
        data.min = readPositiveNumber("Enter min value: ");
        data.max = readPositiveNumber("Enter max value: ");

        // Logic check: ensure range is valid
        if (data.min > data.max)
            std::cout << "❌ Min cannot be greater than Max. Try again.\n";
        
    } while (data.min > data.max);

    return data;
}

/**
 * Fills the array struct based on the configuration struct settings
 */
void fillArrayWithRandomNumbers(stArray &arr, stConfig& data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr[i] = randomNumber(data.min, data.max);
    }
}

/**
 * Displays the array elements to the console
 */
void printArray(const stArray &arr, const stConfig& data) {
    std::cout << "\nArray Elements: ";
    for (int i = 0; i < data.arrLength; i++) {
        std::cout << arr.arr[i] << " ";
    }
    std::cout << "\n";
}

/**
 * Handles the repeat logic
 */
bool askToRepeat() {
    std::cout << "\nGenerate another random array? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Main application loop
 */
void runProgram() {
    // Seed the random generator once using current time
    srand((unsigned)time(NULL));

    do {
        stConfig data;
        stArray arr;

        data = readdata();
        fillArrayWithRandomNumbers(arr, data);
        printArray(arr, data);

    } while (askToRepeat());
}

int main() { 
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
