#include "StringCalculator.h"
#include <gtest/gtest.h>

TEST(StringCalculatorTests, TC01_EmptyStringReturnsZero) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add(""), 0);
}

TEST(StringCalculatorTests, TC02_SingleNumberInput) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("1"), 1);
}

TEST(StringCalculatorTests, TC03_MultipleCommaSeparatedNumbers) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("1,2,3"), 6);
}

TEST(StringCalculatorTests, TC04_NewlineAsValidDelimiter) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("1\n2,3"), 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

