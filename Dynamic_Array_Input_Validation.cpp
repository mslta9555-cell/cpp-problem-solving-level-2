// Problem_34: Dynamic Array Filling with Input Validation
#include <iostream>
#include <limits>
#include <string>
#include <cctype>

// Stores numbers and tracks the actual count (length)
struct stArray_1 {
    int arr_1[100];
    int length = 0; 
};

// Configuration for user choices
struct stConfig {
    int number{0};
    int addMore{0};
};

/**
 * Utility: Standard buffer clear to avoid infinite loops on char input
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Input: Reads and validates a number within 1-100 range
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
 * Logic: Actually assigns the number to the array and increments the counter
 */
void addArrayElement(int number, stArray_1 &arr)
{
    if (arr.length >= 100) {
        std::cout << "⚠️ Array is full!\n";
        return;
    }

    arr.arr_1[arr.length++] = number;
}

/**
 * Logic: Main input loop
 */
void InputUserNumbersInArray(stConfig &data, stArray_1 &arr) {
    do {
        // Step 1: Read the number from user
        data.number = readPositiveNumber("Please enter a number: ");
        
        // Step 2: Push it into the array using our helper function
        addArrayElement(data.number, arr);

        // Step 3: Validation loop for (0/1)
        while (true) {
            std::cout << "Do you want to add more numbers? [0]:No, [1]:Yes : ";
            if (std::cin >> data.addMore) {
                if (data.addMore == 1 || data.addMore == 0) {
                    clearInputBuffer();
                    break; 
                }
            }
            std::cout << "❌ Invalid! Please enter 0 or 1.\n";
            clearInputBuffer();
        }

    } while (data.addMore && arr.length < 100);
}
/**
 * UI: Displays total elements and their values
 */
void printresult(const stArray_1& arr) {
    std::cout << "\n--- Array Summary ---";
    std::cout << "\nArray Length  : " << arr.length;
    std::cout << "\nArray Elements: ";
    for (int i = 0; i < arr.length; i++) {
        std::cout << "[" << arr.arr_1[i] << "] ";
    }
    std::cout << "\n---------------------\n";
}

/**
 * Control: Main repeat loop for the whole program
 */
bool askToRepeat() {
    std::cout << "\nTry another set? (y/n): ";
    char input{};
    std::cin >> input;
    clearInputBuffer();
    return (tolower(input) == 'y');
}

/**
 * Orchestrator: Connects all parts
 */
void runProgram() {
    do {
        stArray_1 arr_1; 
        stConfig data;

        InputUserNumbersInArray(data, arr_1);
        printresult(arr_1);

    } while (askToRepeat());
}

int main() { 
    runProgram();
    return 0;
}
