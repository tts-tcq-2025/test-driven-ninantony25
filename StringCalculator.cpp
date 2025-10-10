#include "StringCalculator.h"
#include <string>
#include <sstream>

int StringCalculator::Add(const std::string& numbers) 
{
    if (numbers.empty()) return 0;

    std::stringstream ss(numbers);
    int result = 0;
    ss >> result;
    return result;
}

