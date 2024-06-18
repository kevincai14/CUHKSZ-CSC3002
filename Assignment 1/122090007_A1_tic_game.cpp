//
// Created by Quan on 2024/1/30.
//
#include <iostream>
using namespace std;

bool check_empty(string gameboard) {
    if (gameboard.find('E') == string::npos) {
        return true;
    } else {
        return false;
    }
}
bool row_check(string gameboard) {
    for (size_t i = 0; i < 9; i += 3) {
        if (gameboard[i] == gameboard[i + 1] and gameboard[i + 1] == gameboard[i + 2]) {
            if (gameboard[i] == 'X' or gameboard[i] == 'O') {
                return true;
            }
        }
    }
    return false;
}
bool column_check(string gameboard) {
    for (size_t i = 0; i < 3; i++) {
        if (gameboard[i] == gameboard[i + 3] and gameboard[i + 3] == gameboard[i + 6]) {
            if (gameboard[i] == 'X' or gameboard[i] == 'O') {
                return true;
            }
        }
    }
    return false;
}
bool diagonal_check(string gameboard) {
    for (size_t i = 2; i < 5; i += 2) {
        if (gameboard[4 - i] == gameboard[4] and gameboard[4] == gameboard[4 + i]) {
            if (gameboard[4] == 'X' or gameboard[4] == 'O') {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string line1, line2, line3;
    cin >> line1 >> line2 >> line3;
    string gameboard = line1 + line2 + line3;

    if (check_empty(gameboard)) {
        cout << "True";
    } else {
        if (row_check(gameboard) or column_check(gameboard) or diagonal_check(gameboard)) {
            cout << "True";
        } else {
            cout << "False";
        }
    }
    return 0;
}