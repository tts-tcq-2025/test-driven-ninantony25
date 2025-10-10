#include "StringCalculator.h"
#include <cassert>
#include <iostream>

int main() {
    StringCalculator calc;

    // TC01: Empty string
    assert(calc.Add("") == 0);
    std::cout << "TC01 passed: Empty string returns 0\n";

    // TC02: Single number
    assert(calc.Add("1") == 1);
    std::cout << "TC02 passed: Single number returns 1\n";

    // TC03: Multiple comma-separated numbers
    assert(calc.Add("1,2,3") == 6);
    std::cout << "TC03 passed: Multiple numbers return correct sum\n";

    return 0;
}
