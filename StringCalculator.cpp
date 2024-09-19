#include "StringCalculator.h"

#include <sstream>
#include <algorithm>

int StringCalculator::add(const std::string& input) {
    if (isZeroOrEmpty(input))
    {
      return 0;
    }
    std::string validatedInput = handleCustomDelimiter(input);
    validatedInput = normalizeDelimiters(validatedInput);
    negativeNumbersCheck(validatedInput);
    return numbersSum(validatedInput);
}
 
bool StringCalculator::isZeroOrEmpty(const std::string& input) {
    return input.empty() || input == "0";
}

int StringCalculator::numbersSum(const std::string& input) {
    std::istringstream stream(input);
    std::string number;
    int sum = 0;
    while (std::getline(stream, number, ',')) {
        int num = std::stoi(number);
        if (num <=1000) {
         sum += num;
        }
    }
    return sum;
}
 
void StringCalculator::negativeNumbersCheck(const std::string& input) {
    std::istringstream stream(input);
    std::string number;
    while (std::getline(stream, number, ','))
    {
        if (std::stoi(number) < 0)
        {
            throw std::runtime_error("Negative numbers not allowed");
        }
    }
}
 
std::string StringCalculator::normalizeDelimiters(const std::string& input) {
    std::string result = input;
    std::replace(result.begin(), result.end(), '\n', ',');
    return result;
}

std::string StringCalculator::handleCustomDelimiter(const std::string& input) {
    if (input.substr(0, 2) == "//") {
        std::string delimiter = input.substr(2, input.find('\n') - 2);
        std::string rest = input.substr(input.find('\n') + 1);
        std::replace(rest.begin(), rest.end(), delimiter[0], ',');
        return rest;
    }
    return input;
}
