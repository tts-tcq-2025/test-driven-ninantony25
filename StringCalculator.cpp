#include "StringCalculator.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int StringCalculator::Add(const std::string& numbers) {
    if (numbers.empty()) return 0;

    std::string normalized = numbers;
    std::replace(normalized.begin(), normalized.end(), '\n', ','); // treat newline as comma

    std::stringstream ss(normalized);
    std::string token;
    int sum = 0;

    while (std::getline(ss, token, ',')) {
        if (!token.empty()) {
            sum += std::stoi(token);
        }
    }

    return sum;
}
