#include "StringCalculator.h"

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

namespace {

std::string ExtractDelimiter(std::string& input) {
  if (input.rfind("//", 0) != 0) return ",";

  size_t newline_pos = input.find('\n');
  if (newline_pos == std::string::npos) return ",";

  std::string delimiter_spec = input.substr(2, newline_pos - 2);
  input = input.substr(newline_pos + 1);

  // Handle multi-character delimiter in [ ]
  if (delimiter_spec.front() == '[' && delimiter_spec.back() == ']') {
    return delimiter_spec.substr(1, delimiter_spec.size() - 2);
  }

  return delimiter_spec;
}

std::string NormalizeDelimiters(const std::string& input,
                                const std::string& delimiter) {
  std::string result = input;
  std::replace(result.begin(), result.end(), '\n', ',');
  size_t pos = 0;
  while ((pos = result.find(delimiter)) != std::string::npos) {
    result.replace(pos, delimiter.length(), ",");
  }
  return result;
}

int SumTokens(const std::string& input) {
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

}  // namespace
int StringCalculator::Add(const std::string& numbers) {
  if (numbers.empty()) return 0;

  std::string input = numbers;
  std::string delimiter = ExtractDelimiter(input);
  std::string normalized = NormalizeDelimiters(input, delimiter);
  return SumTokens(normalized);
}
