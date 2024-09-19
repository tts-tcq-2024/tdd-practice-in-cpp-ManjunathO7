#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H
#include <string>
class StringCalculator {
public:
    int add(const std::string& input);
 
private:
bool isZeroOrEmpty(const std::string& input);
int SumOfNumbersLessThan1000(const std::string& input);
void negativeNumbersCheck(const std::string& input);
std::string normalizeDelimiters(const std::string& input);
std::string handleCustomDelimiter(const std::string& input);
};
#endif // STRINGCALCULATOR_H
