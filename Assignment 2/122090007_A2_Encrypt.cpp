//
// Created by 蔡宇泉 on 2024/3/18.
//
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class encdec {
public:
    void encrypt(vector<string>& text, int key);
    void decrypt(vector<string>& text, int key);
};

int key_convert(int key) {
    key %= 26;
    if (key < 0) {
        key = 26 + key;
    }
    return key;
}

void encdec:: encrypt(vector<string>& text, int key) {
    for (string &str : text) {
        for (char &c : str) {
            if (isalpha(c)) {
                char a_A = isupper(c) ? 'A' : 'a';
                c = a_A + key_convert(key_convert(key) + c - a_A);
            }
        }
    }
}

void encdec:: decrypt(vector<string>& text, int key) {
    key *= -1;
    for (string& str : text) {
        for (char& c : str) {
            if (isalpha(c)) {
                char a_A = isupper(c) ? 'A' : 'a';
                c = a_A + key_convert(key_convert(key) + c - a_A);
            }
        }
    }
}


int main() {
    vector<string> source_v;
    string line;

    while (cin) {
        getline(cin, line);
        source_v.push_back(line);
    }

    int key = stoi(source_v[0]);
    string type = source_v[1];

    encdec text;
    source_v.erase(source_v.begin(), source_v.begin() + 2);

    if (type == "encrypt") {
        text.encrypt(source_v, key);
    } else if (type == "decrypt") {
        text.decrypt(source_v, key);
    }

    for (const string& s : source_v) {
        cout << s << endl;
    }
}