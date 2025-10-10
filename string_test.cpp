#include "StringCalculator.h"
#include <cassert>
#include <iostream>

int main() 
{
    StringCalculator calc;
    assert(calc.Add("") == 0);
    std::cout << "TC01 passed: Empty string returns 0\n";
    return 0;
}
