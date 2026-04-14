// Problem_23: Find Max Number in Random Array
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

struct stArray {
    int arr[100];
};

struct stConfig {
    int arrLength{0};
    int min{0};
    int max{0};
    int maxNumber{0};
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
        std::cout << "❌ Invalid! Enter a number between 1 and 100.\n";
        clearInputBuffer();
    }
}

stConfig readdata() {
    stConfig data;
    data.arrLength = readPositiveNumber("\nEnter number of elements (1-100): ");
    do {
        data.min = readPositiveNumber("Enter min value: ");
        data.max = readPositiveNumber("Enter max value: ");
        if (data.min > data.max)
            std::cout << "❌ Min cannot be greater than Max. Try again.\n";
    } while (data.min > data.max);
    return data;
}

void fillArrayWithRandomNumbers(stArray &arr, stConfig& data) {
    for (int i = 0; i < data.arrLength; i++) {
        arr.arr[i] = randomNumber(data.min, data.max);
    }
}

/**
 * Logic: Finding the maximum value by iterating through the array.
 * We start by assuming the first element is the maximum.
 */
void updateMaxNumber(const stArray &arr, stConfig& data) {
    // Initializing max with the first element of the array
    data.maxNumber = arr.arr[0];

    for (int i = 1; i < data.arrLength; i++) {
        if (arr.arr[i] > data.maxNumber) {
            data.maxNumber = arr.arr[i];
        }
    }
}

void printArray(const stArray &arr, const stConfig& data) {
    std::cout << "\nArray Elements: ";
    for (int i = 0; i < data.arrLength; i++) {
        std::cout << arr.arr[i] << " ";
    }
    std::cout << "\n----------------------------";
    std::cout << "\nMax Number is : " << data.maxNumber;
    std::cout << "\n----------------------------\n";
}

bool askToRepeat() {
    std::cout << "\nGenerate another random array? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

void runProgram() {
    srand((unsigned)time(NULL));
    do {
        stConfig data;
        stArray arr;

        data = readdata();
        fillArrayWithRandomNumbers(arr, data);
        
        // Find and store the max number before printing
        updateMaxNumber(arr, data);
        
        printArray(arr, data);

    } while (askToRepeat());
}

int main() { 
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
