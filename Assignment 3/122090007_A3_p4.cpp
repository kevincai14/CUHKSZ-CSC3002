//
// Created by 蔡宇泉 on 2024/4/15.
//
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    string data;
    double priority;
    Node* next;
    Node(string value, double priority_num);
};

Node::Node(string value, double priority_num) {
    data = value;
    priority = priority_num;
}


class PriorityQueue {
public:
    Node* front = nullptr;
    Node* tail = nullptr;

    void enqueue(string value, double priority);
    void dequeue();
};

void PriorityQueue::enqueue(string value, double priority) {
    Node* new_node = new Node(value, priority);

    if (front == nullptr or priority < (front -> priority)) {
        (new_node -> next) = front;
        front = new_node;
        if (tail == nullptr) {
            tail = new_node;
        }
    } else {
        Node* current = front;
        while ((current -> next) != nullptr and ((current -> next) -> priority) <= priority) {
            current = (current -> next);
        }
        (new_node -> next) = (current -> next);
        (current -> next) = new_node;
        if (current == tail) {
            tail = new_node;
        }
    }
}

void PriorityQueue::dequeue() {
    front = (front -> next);
    if (front == nullptr) {
        tail = nullptr;
    }
}

vector< vector<string> > get_data_command() {
    vector<string> source_v;
    string line;
    while (cin) {
        getline(cin, line);
        source_v.push_back(line);
    }

    vector< vector<string> > data_command;
    for (string s : source_v) {
        istringstream split(s);
        vector<string> text;
        string word;
        while (split >> word) {
            text.push_back(word);
        }
        data_command.push_back(text);
    }

    return data_command;
}

int main() {
    PriorityQueue text;
    vector< vector<string> > data_command = get_data_command();

    for (int i = 0; i < data_command[0].size(); i += 2) {
        text.enqueue(data_command[0][i], stoi(data_command[0][i + 1]));
    }


    for (int i = 0; i < data_command[1].size(); i++) {
        if (data_command[1][i] == "enqueue") {
            text.enqueue(data_command[1][i + 1], stoi(data_command[1][i + 2]));
            i += 2;
        } else {
            text.dequeue();
        }
    }

    Node* current = text.front;
    while (current != nullptr) {
        cout << (current -> data) << " ";
        current = (current -> next);
    }

}