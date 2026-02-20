// Problem_6: Calculate Sum of Digits
#include <iostream>
#include <limits>
#include <cctype>
#include <string>

// --- Utility Functions ---
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

long long readInteger(const std::string& prompt) {
    long long value{};
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= 0) {
            clearInputBuffer();
            return value;
        }
        std::cout << "❌ Invalid input! Please enter a non-negative number.\n";
        std::cin.clear();
        clearInputBuffer();
    }
}

// --- Logic Layer (Pure Calculation) ---
// Senior Note: This function only calculates, making it reusable.
long long calculateSumOfDigits(long long number) {
    long long sum = 0;
    while (number > 0) {
        sum += (number % 10);
        number /= 10;
    }
    return sum;
}

// --- UI Layer (Presentation) ---
void displayResults(long long originalNumber, long long sum) {
    std::cout << "\n--- Result Analysis ---" << std::endl;
    std::cout << "Original Number : " << originalNumber << std::endl;
    std::cout << "Sum of Digits   : " << sum << std::endl;
    std::cout << "-----------------------" << std::endl;
}

bool askToRepeat()
{
    while (true)
    {
        std::cout << "\nTry another number? (y/n): ";
        char input{};
        std::cin >> input;
        clearInputBuffer();

        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));
        if (input == 'y') return true;
        if (input == 'n') return false;

        std::cout << "❌ Please enter 'y' or 'n'.\n";
    }
}
// --- Application Flow ---
void runProgram() {
    do { 
        long long number = readInteger("Enter a positive number: ");
        long long sum = calculateSumOfDigits(number);
        displayResults(number, sum);

    } while (askToRepeat());
}

int main() {
    runProgram();
    std::cout << "\n🙏 See you next time!\n";
    return 0;
}
