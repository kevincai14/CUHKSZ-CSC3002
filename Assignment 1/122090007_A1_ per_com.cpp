//
// Created by Quan on 2024/1/31.
//
#include <iostream>
#include <string>
using namespace std;

long long factorial(int n) {
    if (n == 0 or n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

long long combination(int n, int r) {
    return factorial(n) / (factorial(n - r) * factorial(r));
}

int main() {
    int n, r;
    string input;
    getline(cin, input);

    size_t pos = input.find(' ');
    n = stoi(input.substr(0, pos));
    r = stoi(input.substr(pos + 1, input.length() - pos - 1));

    cout << "Permutation: " << permutation(n, r) << endl;
    cout << "Combination: " << combination(n, r) << endl;

    return 0;
}