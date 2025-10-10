#include "StringCalculator.h"
#include <string>

int StringCalculator::Add(const std::string& numbers) 
{
    if (numbers.empty()) return 0;

    return std::stoi(numbers); // handles single number input
}
