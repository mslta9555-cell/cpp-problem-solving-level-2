// Problem_35: Copy Array using AddElement Function
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
    int length = 0; 
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

// Fills Source Array with Random Numbers
void fillArraysWithRandomNumbers(stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr_1[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/** * Logic: Smart Addition
 * Adds a number and updates the length index
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
 * Logic: Copying by Calling addArrayElement
 */
void CopyArrayUsingAddArrayElement(stArray_1 &arr, const stConfig &data, stArray_2 &arr_2)
{
    for (int i = 0; i < data.arrLength; i++)
    {
        addArrayElement(arr.arr_1[i], arr_2);
    }
}

void PrintArray(const stArray_1 &arr, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++)
        std::cout << "[" << arr.arr_1[i] << "] ";    
}

// Prints based on the actual length of arr2
void PrintArray(const stArray_2 &arr_2) {
    for (int i = 0; i < arr_2.length; i++)
        std::cout << "[" << arr_2.arr_2[i] << "] ";    
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
        stConfig data = readData();

        fillArraysWithRandomNumbers(arr1, data);
        
        // Copy using the smart function
        CopyArrayUsingAddArrayElement(arr1, data, arr2);

        std::cout << "\nArray 1 Elements (Random): ";
        PrintArray(arr1, data);

        std::cout << "\nArray 2 Elements (Copied): ";
        PrintArray(arr2); 

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
