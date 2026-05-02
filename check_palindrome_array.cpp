// Problem_38: Check if Array is Palindrome
#include <iostream>
#include <limits>
#include <ctime>
#include <string>
#include <cctype>
#include <random>

// --- constants to replace Magic Numbers ---
constexpr int MAX_ARRAY_SIZE = 100;
constexpr int INPUT_LIMIT_MAX = 100;
constexpr int INPUT_LIMIT_MIN = 1;

struct stArrayData { 
    int arr[MAX_ARRAY_SIZE]; 
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

int randomNumber(int from, int to) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(from, to);
    return dist(gen);
}
/**
 * Logic: Checks if array is Palindrome.
 * It compares the first half with the second half mirrored.
 */

bool isPalindromeArray(const stArrayData &source, int length)
{
    int left = 0;
    int right = length - 1;

    while (left < right)
    {
        if (source.arr[left] != source.arr[right])
            return false;

        left++;
        right--;
    }

    return true;
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
            std::cout << "❌ Error: Min cannot be greater than Max!\n";
    } while (data.minRange > data.maxRange);
    return data;
}

void fillArrayWithRandom(stArrayData &source, const stConfig &data) {
    for (int i = 0; i < data.arrLength; i++) {
        source.arr[i] = randomNumber(data.minRange, data.maxRange);
    }
}

void printArray(const stArrayData &source, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << "[" << source.arr[i] << "] ";    
    }
    std::cout << "\n";
}

bool askToRepeat() {
    std::cout << "\nTry another set? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

void runProgram() {
    srand((unsigned)time(NULL)); 
    do {
        stArrayData sourceArr;
        stConfig data = readData();

        fillArrayWithRandom(sourceArr, data);

        std::cout << "\nSource Array: ";
        printArray(sourceArr, data.arrLength);

        // Final Verdict
        if (isPalindromeArray(sourceArr, data.arrLength)) {
            std::cout << "✅ Result: Yes, Array is Palindrome.\n";
        } else {
            std::cout << "❌ Result: No, Array is NOT Palindrome.\n";
        }

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
