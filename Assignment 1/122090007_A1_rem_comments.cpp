//
// Created by Quan on 2024/1/30.
//
#include <iostream>
#include <vector>
using namespace std;

void remove_line(vector<string>& source) {
    for (size_t i = 0; i < source.size(); i++) {
        size_t pos = source[i].find("//");
        if (pos != string::npos) {
            source[i].erase(pos, source[i].length() - pos);
        }
    }
}

void remove_block(vector<string>& source) {
    bool state = false;
    for (size_t i = 0; i < source.size(); i++) {
        size_t pos_1 = source[i].find("/*");
        size_t pos_2 = source[i].find("*/");
        if (pos_1 != string::npos and pos_2 != string::npos) {
            source[i].erase(pos_1, pos_2 - pos_1 + 2);
        }
        if (pos_1 == string::npos and pos_2 != string::npos) {
            source[i].erase(0, pos_2 + 2);
            state = false;
        }
        if (state) {
            source[i] = "";
        }
        if (pos_1 != string::npos and pos_2 == string::npos) {
            source[i].erase(pos_1, source[i].length() - pos_1);
            state = true;
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

    remove_block(source_v);
    remove_line(source_v);

    for (size_t i = 0; i < source_v.size(); i++) {
        if (source_v[i] != "") {
            cout << source_v[i] << endl;
        }
    }
    
    return 0;
}