// Problem_39: Count Odd & Even Numbers
#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <random>

constexpr int MAX_ARRAY_SIZE = 100;
constexpr int INPUT_LIMIT_MAX = 100;
constexpr int INPUT_LIMIT_MIN = 1;

struct stArrayData { int arr[MAX_ARRAY_SIZE]; };

struct stConfig {
    int arrLength{0};
    int minRange{0}; 
    int maxRange{0};
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

bool isOddNumber(int number) { return (number % 2 != 0); }
bool isEvenNumber(int number) { return (number % 2 == 0); } 

// Logic: Corrected to use isOddNumber
size_t countOddNumbers(const stArrayData &source, size_t length) {
    size_t counter = 0;
    for (size_t i = 0; i < length; i++) 
        if (isOddNumber(source.arr[i])) counter++;
    return counter;
}

// Logic: Corrected to use isEvenNumber
size_t countEvenNumbers(const stArrayData &source, size_t length) {
    size_t counter = 0;
    for (size_t i = 0; i < length; i++) 
        if (isEvenNumber(source.arr[i])) counter++;
    return counter;
}

int readPositiveNumber(const std::string& prompt) {
    int number{0};
    while (true) {
        std::cout << prompt;
        if (std::cin >> number && number >= INPUT_LIMIT_MIN && number <= INPUT_LIMIT_MAX) {
            clearInputBuffer();
            return number;
        }
        std::cout << "❌ Invalid! Range (" << INPUT_LIMIT_MIN << "-" << INPUT_LIMIT_MAX << ").\n";
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
            std::cout << "❌ Error: Min > Max!\n";
    } while (data.minRange > data.maxRange);
    return data;
}

void fillArrayWithRandom(stArrayData &source, const stConfig &data) {
    for (int i = 0; i < (size_t)data.arrLength; i++) {
        source.arr[i] = randomNumber(data.minRange, data.maxRange);
    }
}

void printArray(const stArrayData &source, size_t length) {
    for (size_t i = 0; i < length; i++) {
        std::cout << "[" << source.arr[i] << "] ";    
    }
    std::cout << "\n";
}

void printResult(const stArrayData &source, size_t length) {
    std::cout << "\n--- Statistics ---" << "\n";
    std::cout << "🔢 Odd Numbers Count  is: " << countOddNumbers(source, length) << "\n";
    std::cout << "🔢 Even Numbers Count is: " << countEvenNumbers(source, length) << "\n";
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
        stConfig data = readData();

        fillArrayWithRandom(sourceArr, data);

        std::cout << "\nSource Array Elements: ";
        printArray(sourceArr, data.arrLength);

        printResult(sourceArr, data.arrLength);

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
