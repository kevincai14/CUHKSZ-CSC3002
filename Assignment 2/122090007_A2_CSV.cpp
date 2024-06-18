//
// Created by 蔡宇泉 on 2024/3/19.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

vector< vector<string> > get_text(vector<string> source_v) {
    int lines;
    for (int i = 0; i < source_v.size(); i++) {
        if (source_v[i] == "create") {
            lines = i - 1;
            break;
        }
    }

    vector< vector<string> > text;
    for (int i = 0; i <= lines; i++) {
        vector<string> vector;
        string line;
        stringstream stream(source_v[i]);
        string element;
        while (getline(stream, element, ',')) {
            vector.push_back(element);
        }
        text.push_back(vector);
    }
    return text;
}

void create(vector<vector<string> >& text, const string& filename) {
    ofstream file(filename);
    for (vector<string> line : text) {
        for (size_t i = 0; i < line.size(); ++i) {
            file << line[i];
            if (i != line.size() - 1) {
                file << ",";
            }
        }
        file << endl;
    }
    file.close();
}

void update(vector<vector<string> >& text, string command_line) {
    vector<string> line;
    stringstream stream(command_line);
    string element;
    while (getline(stream, element, ' ')) {
        line.push_back(element);
    }
    int row = stoi(line[1]);
    int column = stoi(line[2]);
    text[row][column] = line[3];

}

void remove(vector<vector<string> >& text, string command_line) {
    vector<string> line;
    stringstream stream(command_line);
    string element;
    while (getline(stream, element, ' ')) {
        line.push_back(element);
    }
    int row = stoi(line[1]);
    text.erase(text.begin() + row);
}


int main() {
    vector<string> source_v;
    string line;

    while (cin) {
        getline(cin, line);
        source_v.push_back(line);
    }

    vector< vector<string> > text = get_text(source_v);

    for (string a : source_v) {
        string command = a.substr(0, 6);
        if (command == "update") {
            update(text, a);
        }
        if (command == "remove") {
            remove(text, a);
        }
    }

    for (vector<string> a : text) {
        for (string b : a) {
            if (b == a.back()) {
                cout << b << endl;
            } else {
                cout << b << ",";
            }
        }
    }
//    create(text, "output.csv");
}