#include "StringCalculator.h"
#include <string>
#include <sstream>

int StringCalculator::Add(const std::string& numbers) {
    if (numbers.empty()) return 0;

    std::stringstream ss(numbers);
    std::string token;
    int sum = 0;

    while (std::getline(ss, token, ',')) {
        if (!token.empty()) {
            sum += std::stoi(token);
        }
    }

    return sum;
}
