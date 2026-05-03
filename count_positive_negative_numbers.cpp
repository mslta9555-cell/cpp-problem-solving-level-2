// Problem_40: Positive and Negative Numbers Count
#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <random>

constexpr int MAX_ARRAY_SIZE = 100;
constexpr int MIN_RANDOM = -100;
constexpr int MAX_RANDOM = 100;

struct stArrayData { 
    int arr[MAX_ARRAY_SIZE];  
    size_t arrLength{0}; // Length is now part of the data structure
};

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int randomNumber(int from, int to) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(from, to);
    return dist(gen);
}

int readPositiveNumber(const std::string& prompt) {
    int number{0};
    while (true) {
        std::cout << prompt;
        if (std::cin >> number && number > 0 && number <= MAX_ARRAY_SIZE) {
            clearInputBuffer();
            return number;
        }
        std::cout << "❌ Invalid input! Please enter a number between 1 and " << MAX_ARRAY_SIZE << ".\n";
        clearInputBuffer();
    }
}

// Fixed: Assign length directly to the array structure
void readData(stArrayData &source) {
    source.arrLength = readPositiveNumber("Enter number of elements: ");
}

void fillArrayWithRandom(stArrayData &source) {
    for (int i = 0; i < source.arrLength; i++) {
        // Range including negative numbers
        source.arr[i] = randomNumber(MIN_RANDOM, MAX_RANDOM);
    }
}

size_t countPositive(const stArrayData &source) {
    size_t counter = 0;
    for (size_t i = 0; i < source.arrLength; i++)
        counter += (source.arr[i] > 0); 
    return counter;
}

size_t countNegative(const stArrayData &source) {
    size_t counter = 0;
    for (size_t i = 0; i < source.arrLength; i++)
         counter += (source.arr[i] < 0);
    return counter;
}

size_t countZero(const stArrayData &source) {
    size_t counter = 0;
    for (size_t i = 0; i < source.arrLength; i++)
        counter += (source.arr[i] == 0);
    return counter;
}

void printArray(const stArrayData &source) {
    for (size_t i = 0; i < source.arrLength; i++) {
        std::cout << "[" << source.arr[i] << "] ";    
    }
    std::cout << "\n";
}

void printResult(const stArrayData &source) {
    std::cout << "\n--- Analysis ---\n";
    std::cout << "\n✅ Positive numbers count: " << countPositive(source);
    std::cout << "\n❌ Negative numbers count: " << countNegative(source) << "\n";
    std::cout << "Zero numbers count: "    <<   countZero(source) << "\n";

}

bool askToRepeat() {
    std::cout << "\nTry another set? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

void runProgram() {
    do {
        stArrayData sourceArr;
        
        // Pass sourceArr by reference to update its length inside
        readData(sourceArr); 

        fillArrayWithRandom(sourceArr);

        std::cout << "\nSource Array Elements:\n";
        printArray(sourceArr);

        printResult(sourceArr);

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
