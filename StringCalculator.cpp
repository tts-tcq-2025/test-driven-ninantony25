#include "StringCalculator.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

namespace {
    std::string extractDelimiter(std::string& input) {
        if (input.rfind("//", 0) == 0) {
            size_t newlinePos = input.find('\n');
            if (newlinePos != std::string::npos) {
                std::string delimiter = input.substr(2, newlinePos - 2);
                input = input.substr(newlinePos + 1);
                return delimiter;
            }
        }
        return ",";
    }

    std::string normalizeDelimiters(const std::string& input, const std::string& delimiter) {
        std::string result = input;
        std::replace(result.begin(), result.end(), '\n', ',');
        size_t pos = 0;
        while ((pos = result.find(delimiter)) != std::string::npos) {
            result.replace(pos, delimiter.length(), ",");
        }
        return result;
    }

    int sumTokens(const std::string& input) {
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
}

int StringCalculator::Add(const std::string& numbers) {
    if (numbers.empty()) return 0;

    std::string input = numbers;
    std::string delimiter = extractDelimiter(input);
    std::string normalized = normalizeDelimiters(input, delimiter);
    return sumTokens(normalized);
}
