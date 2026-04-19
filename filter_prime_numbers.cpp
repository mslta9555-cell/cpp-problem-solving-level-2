// Problem_37: Filtering Prime Numbers (Clean Version)
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

// --- constants to replace Magic Numbers ---
constexpr int MAX_ARRAY_SIZE = 100;
constexpr int INPUT_LIMIT_MAX = 100;
constexpr int INPUT_LIMIT_MIN = 1;
constexpr int NOT_FOUND = -1;

struct stArrayData { 
    int arr[MAX_ARRAY_SIZE]; 
};

struct stFilteredArray { 
    int arr[MAX_ARRAY_SIZE]; 
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

/**
 * Logic: Prime Check using 6k +/- 1 optimization.
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

/**
 * Input: Validates numbers using defined LIMIT constants
 */
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
            std::cout << "❌ Error: Min cannot be greater than Max!\n";
    } while (data.minRange > data.maxRange);
    return data;
}

void fillArrayWithRandom(stArrayData &source, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        source.arr[i] = randomNumber(data.minRange, data.maxRange);
    }
}

/**
 * Logic: Adds element safely using MAX_ARRAY_SIZE constant
 */
void addArrayElement(int number, stFilteredArray &dest)
{
    if (dest.length >= MAX_ARRAY_SIZE) {
        std::cout << "\n⚠️ Warning: Array capacity reached!";
        return;
    }
    dest.arr[dest.length++] = number;
}

void filterPrimes(const stArrayData &source, int sourceLength, stFilteredArray &dest)
{
    for (int i = 0; i < sourceLength; i++)
    {
        if (isPrime(source.arr[i]))
        {
            addArrayElement(source.arr[i], dest);
        }
    }
}

void PrintArray(const stArrayData &source, int length) {
    for (int i = 0; i < length; i++)
        std::cout << "[" << source.arr[i] << "] ";    
}

void PrintArray(const stFilteredArray &dest) {
    for (int i = 0; i < dest.length; i++)
        std::cout << "[" << dest.arr[i] << "] ";    
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
        stArrayData sourceArr;
        stFilteredArray primeArr; 
        stConfig data = readData();

        fillArrayWithRandom(sourceArr, data);
        filterPrimes(sourceArr, data.arrLength, primeArr);

        std::cout << "\nSource Array (Random): ";
        PrintArray(sourceArr, data.arrLength);

        std::cout << "\nFiltered Array (Primes Only): ";
        PrintArray(primeArr); 

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
