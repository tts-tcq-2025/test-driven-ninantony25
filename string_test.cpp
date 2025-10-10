#include "StringCalculator.h"
#include <cassert>
#include <iostream>

int main() 
{
    StringCalculator calc;

    // TC01: Empty string
    assert(calc.Add("") == 0);
    std::cout << "TC01 passed: Empty string returns 0\n";

    // TC02: Single number
    assert(calc.Add("1") == 1);
    std::cout << "TC02 passed: Single number returns 1\n";

    return 0;
}
