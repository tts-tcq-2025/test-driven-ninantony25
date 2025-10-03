# TDD Driven StringCalculator

Build a StringCalculator functionality that can take up to two numbers, separated by commas, and will return their sum. 
for example “” or “1” or “1,2” as inputs.

> DO NOT jump into implementation! Read the example and the starting task below.

- For an empty string it will return 0
- Allow the Add method to handle an unknown amount of numbers
- Allow the Add method to handle new lines between numbers (instead of commas).
  - the following input is ok: “1\n2,3” (will equal 6)
  - the following input is NOT ok: “1,\n” (not need to prove it - just clarifying)
- Support different delimiters : to change a delimiter, the beginning of the string will contain a separate line that looks like this: “//[delimiter]\n[numbers…]” for example “//;\n1;2” should return three where the default delimiter is ‘;’ .
the first line is optional. all existing scenarios should still be supported
- Calling Method with a negative number will throw an exception “negatives not allowed” - and the negative that was passed. if there are multiple negatives, show all of them in the exception message.
- Numbers bigger than 1000 should be ignored, so adding 2 + 1001 = 2
- Delimiters can be of any length with the following format: “//[delimiter]\n” for example: “//[***]\n1***2***3” should return 6

| Test ID | Test Name | Input | Expected Output | Notes |
|--------|-----------|-------|------------------|-------|
| TC01 | Empty String Returns Zero | `""` | `0` | Validates base case |
| TC02 | Single Number Input | `"1"` | `1` | Validates single number parsing |
| TC03 | Multiple Comma-Separated Numbers | `"1,2,3"` | `6` | Validates summing multiple numbers |
| TC04 | Newline as Valid Delimiter | `"1\n2,3"` | `6` | Supports newline delimiter |
| TC05 | Custom Single-Character Delimiter | `"//;\n1;2"` | `3` | Validates custom delimiter usage |
| TC06 | Custom Multi-Character Delimiter | `"//[***]\n1***2***3"` | `6` | Validates multi-character delimiter |
| TC07 | Negative Number Throws Exception | `"1,-2"` | Exception: `negatives not allowed: -2` | Validates negative number handling |
| TC08 | Multiple Negatives in Input | `"1,-2,-3"` | Exception: `negatives not allowed: -2,-3` | Validates multiple negatives reporting |
| TC09 | Numbers Greater Than 1000 Are Ignored | `"2,1001"` | `2` | Validates exclusion of large numbers |
| TC10 | Custom Delimiter with Newline Mixed | `"//;\n1;2\n3"` | `6` | Validates mixed delimiters with newline |
| TC11 | Custom Delimiter with Special Characters | `"//[***]\n12***3"` | `15` | Validates parsing with special characters |
| TC12 | Only Large Numbers Present | `"1001,1002"` | `0` | Validates all numbers ignored due to size |

Establish quality parameters:

- Ensure  maximum complexity (CCN) per function == 3

- Ensure 100% line and branch coverage at every step

  

Start Test-driven approach

1. Write the smallest possible failing test: give input `"" assert output to be 0 ` .
2. Write the minimum amount of code that'll make it pass.
3. Refactor any assumptions, continue to pass this test. Do not add any code without a corresponding test.
