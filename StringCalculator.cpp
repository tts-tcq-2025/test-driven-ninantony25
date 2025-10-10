#include "StringCalculator.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int StringCalculator::Add(const std::string& numbers) {
    if (numbers.empty()) return 0;

    std::string delimiter = ",";
    std::string input = numbers;

    // Check for custom delimiter
    if (numbers.rfind("//", 0) == 0) {
        size_t newlinePos = numbers.find('\n');
        if (newlinePos != std::string::npos) {
            delimiter = numbers.substr(2, newlinePos - 2);
            input = numbers.substr(newlinePos + 1);
        }
    }

    // Normalize delimiters
    std::replace(input.begin(), input.end(), '\n', ',');
    size_t pos = 0;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        input.replace(pos, delimiter.length(), ",");
    }

    std::stringstream ss(input);
    std::string token;
    int sum = 0;

    while (std::getline(ss, token, ',')) {
        if (!token.empty()) {
            sum += std::stoi(token);
        }
    }

    return sum;
}
