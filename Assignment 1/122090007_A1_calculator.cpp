//
// Created by Quan on 2024/1/29.
//
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    string expression;
    cin >> expression;

    float result = 0;
    float current_number = 0;
    char current_operator = '+';

    for (size_t i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            float number = expression[i] - '0';
            while (isdigit(expression[i + 1])) {
                number = number * 10 + (expression[i + 1] - '0');
                i++;
            }
            if (current_operator == '+') {
                result += current_number;
                current_number = number;
            }
            else if (current_operator == '-') {
                result += current_number;
                current_number = -number;
            }
            else if (current_operator == '*') {
                current_number *= number;
            }
            else if (current_operator == '/') {
                current_number /= number;
            }
        }
        else {
            current_operator = expression[i];
        }
        }

    result += current_number;
    result = round(result);
    cout << result;
    return 0;
}