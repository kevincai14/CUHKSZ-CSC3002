//
// Created by 蔡宇泉 on 2024/4/15.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class TextEditor {
public:
    string current_text = "";
    int cursor_position = 0;
    string addText(string text) {
        current_text.insert(cursor_position, text);
        cursor_position += text.length();
        return current_text;
    }

    string deleteText(int k) {
        int delete_num = min(k, cursor_position);
        current_text.erase(cursor_position - delete_num, delete_num);
        cursor_position -= delete_num;
        return current_text;
    }

    string cursorLeft(int k) {
        cursor_position = max(0, cursor_position - k);
        return current_text;
    }

    string cursorRight(int k) {
        cursor_position = min(static_cast<int>(current_text.length()), cursor_position + k);
        return current_text;
    }
};

vector<string> get_command() {
    vector<string> source_v;
    string line;
    while (cin) {
        getline(cin, line);
        source_v.push_back(line);
    }

    istringstream split(source_v[0]);
    vector<string> command;
    string word;
    while (split >> word) {
        command.push_back(word);
    }

    return command;
}

int main() {
    vector<string> command = get_command();
    TextEditor current_string;

    for (int i = 0; i < command.size(); i += 2) {
        if (command[i] == "addText") {
            current_string.addText(command[i + 1]);
        } else if (command[i] == "deleteText") {
            current_string.deleteText(stoi(command[i + 1]));
        } else if (command[i] == "cursorLeft") {
            current_string.cursorLeft(stoi(command[i + 1]));
        } else if (command[i] == "cursorRight") {
            current_string.cursorRight(stoi(command[i + 1]));
        }

        if (current_string.current_text == "") {
            cout << "Empty" << " ";
        } else {
            cout << current_string.current_text << " ";
        }
    }
    return 0;
}