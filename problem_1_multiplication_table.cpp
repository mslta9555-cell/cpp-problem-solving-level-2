//Problem_1
#include <iostream>
#include <limits>
#include <cctype>

// Global configuration for the table range
namespace config
{
    constexpr int from = 1;
    constexpr int to = 10;
}

// Clears the input buffer to prevent infinite loops on invalid input
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Prints the top header, including the range and column numbers
void PrintTableHeader()
{
    std::cout << "\n\n\n\t\tMULTIPLICATION TABLE FROM " << config::from << " TO " << config::to <<'\n';
    std::cout << "\n-----------------------------------------------------------------------------------";
    std::cout << "\n\t";
    
    for (int i = config::from; i <= config::to; i++)
    {
        std::cout << i << '\t';
    }
    std::cout << "\n-----------------------------------------------------------------------------------\n";
}

// Handles the visual alignment of the vertical separator based on number length
std::string ColumnSeparator(int i)
{
    return (i < 10) ? "   |" : "  |"; // Simplified using ternary operator
}

// Nested loops to calculate and print the table body
void PrintMultiplicationTable()
{
    for (int i = config::from; i <= config::to; i++)
    {
        std::cout << i << ColumnSeparator(i) << '\t';

        for (int y = config::from; y <= config::to; y++)
        {
            std::cout << i * y << '\t';
        }
        std::cout << '\n';
    }
    std::cout << "-----------------------------------------------------------------------------------\n";   
}

// Manages user interaction for repeating the program with input validation
bool askUserToRepeat()
{
    while (true)
    {
        std::cout << "\nRepeat program? (y/n): ";
        char input{};
        std::cin >> input;

        if (std::cin.fail())
        {
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        input = static_cast<char>(std::tolower(static_cast<unsigned char>(input)));

        if (input == 'y') return true;
        if (input == 'n') return false;

        std::cout << "❌ Invalid choice. Please enter 'y' or 'n'.\n";
    }
}

// Main program flow controller
void runProgram()
{
    do
    {
       PrintTableHeader();
       PrintMultiplicationTable();
    } while (askUserToRepeat());
}

int main()
{
    runProgram();
    std::cout << "\n🙏 Thanks for using this program.\n";
    return 0;
}
