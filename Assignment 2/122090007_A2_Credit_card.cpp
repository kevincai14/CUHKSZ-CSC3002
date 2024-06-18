//
// Created by Quan on 2024/3/18.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getDigit(int num) {
    if (num >= 10) {
        return 1 + num % 10;
    }
    return num;
}

vector<int> get_number(string card_number) {
    vector<int> number;
    for (char c : card_number) {
        number.push_back(c - '0');
    }
    reverse(number.begin(), number.end());
    return number;
}

int sum_Double_EvenPlace(string card_number) {
    vector<int> number = get_number(card_number);
    vector<int> even_num;
    for (int num = 1; num < number.size(); num += 2) {
        even_num.push_back(number[num]);
    }

    int result = 0;
    for (int num : even_num) {
        num *= 2;
        result += getDigit(num);
    }
    return result;
}

int sum_OddPlace(string card_number) {
    vector<int> number = get_number(card_number);
    vector<int> odd_num;
    for (int num = 0; num < number.size(); num += 2) {
        odd_num.push_back(number[num]);
    }

    int result = 0;
    for (int num : odd_num) {
        result += num;
    }
    return result;
}

void isValid(string number) {
    int a = sum_Double_EvenPlace(number);
    int b = sum_OddPlace(number);
    int result = a + b;
    if (result % 10 == 0) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
}

int main() {
    string number;
    cin >> number;
    isValid(number);
}