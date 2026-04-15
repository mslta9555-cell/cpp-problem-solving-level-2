// Problem_28: Optimized Prime Copying
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// Struct for the source array
struct stArray_1 {
    int arr_1[100];
};

// Struct for the destination array with its own tracker
struct stArray_2 {
    int arr_2[100];
    int length{0}; // Encapsulated length tracker
};

struct stConfig {
    int arrLength{0};
    int minRange{0}; 
    int maxRange{0};
};

/**
 * Utility: Input handling
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int randomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

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
 * Logic: Prime number verification (6k +/- 1 optimization)
 */
bool isPrime(int num)
{
    if (num <= 1) return false;      
    if (num <= 3) return true;       
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

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

void fillArrayWithRandomNumbers(stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr_1[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/**
 * UI: Prints Array 1 with square brackets
 */
void PrintArray(const stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        std::cout << "[" << arr.arr_1[i] << "] ";    
    }
}

/**
 * UI: Prints Array 2 using its internal length property
 */
void PrintArray(const stArray_2 &arr_2) {
    for (int i = 0; i < arr_2.length; i++) {
        std::cout << "[" << arr_2.arr_2[i] << "] ";
    }
}

/**
 * Core Logic: Compactly copies primes.
 * Uses post-increment (length++) to store and update in one step.
 */
void CopyPrimes(stArray_2 &arr_2, const stArray_1 &arr, const stConfig &data)
{
    for (int i = 0; i < data.arrLength; i++)
    {
        if (isPrime(arr.arr_1[i]))
        {
            // The length property acts as both current index and element count
            arr_2.arr_2[arr_2.length++] = arr.arr_1[i]; 
        }   
    }
}

bool askToRepeat() {
    std::cout << "\nGenerate another random array? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Coordinator: Main flow control
 */
void runProgram() {
    srand((unsigned)time(NULL)); 
    do {
        stArray_1 arr;
        stConfig data;
        stArray_2 arr_2; // length starts at 0

        data = readData();
        fillArrayWithRandomNumbers(arr, data);
        
        // Populate the second array with primes
        CopyPrimes(arr_2, arr, data);

        std::cout << "\nArray 1 Elements : ";
        PrintArray(arr, data);

        std::cout << "\nPrime Numbers in Array 2 : ";
        if (arr_2.length == 0)
            std::cout << "(No Primes Found)";
        else
            PrintArray(arr_2);
        
        std::cout << "\n";

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
