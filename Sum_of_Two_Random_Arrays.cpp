// Problem_29: Sum of Two Random Arrays
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

struct stArray_1 {
    int arr_1[100];
};

struct stArray_2 {
    int arr_2[100];
};

// Renamed for better spelling: Result
struct stResult {
   long long arrSum[100];
};

struct stConfig {
    int arrLength{0};
    int minRange{0}; 
    int maxRange{0};
};

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
        std::cout << "❌ Invalid! Range (1-100).\n";
        clearInputBuffer();
    }
}

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

// Logic: Fills two arrays simultaneously
void fillArraysWithRandomNumbers(stArray_1 &arr, stArray_2 &arr_2, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr_1[i] = randomNumber(data.minRange, data.maxRange);
        arr_2.arr_2[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/** * UI: Print Functions (Overloading)
 */
void PrintArray(const stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++)
        std::cout << "[" << arr.arr_1[i] << "] ";    
}

void PrintArray(const stArray_2 &arr_2, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++)
        std::cout << "[" << arr_2.arr_2[i] << "] ";    
}

void PrintArray(const stResult &result, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++)
        std::cout << "[" << result.arrSum[i] << "] ";    
}

/**
 * Logic: Summing elements from both arrays into a third one
 */
void SumArrays(stResult &result, const stArray_1 &arr, const stArray_2 &arr_2, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        result.arrSum[i] = arr.arr_1[i] + arr_2.arr_2[i];
    }
}

bool askToRepeat() {
    std::cout << "\n\nTry another set? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

void runProgram() {
    srand((unsigned)time(NULL)); 
    do {
        stArray_1 arr1;
        stArray_2 arr2;
        stResult result;
        stConfig data = readData();

        fillArraysWithRandomNumbers(arr1, arr2, data);
        SumArrays(result, arr1, arr2, data);

        std::cout << "\nArray 1 Elements : ";
        PrintArray(arr1, data);

        std::cout << "\nArray 2 Elements : ";
        PrintArray(arr2, data);

        std::cout << "\nSum of elements  : ";
        PrintArray(result, data);

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
