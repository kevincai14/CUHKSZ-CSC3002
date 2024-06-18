//
// Created by Quan on 2024/3/18.
//
#include <iostream>
#include <vector>
using namespace std;

void process_print(const vector<vector<int>>& rods) {
    for (vector<int> line : rods) {
        if (line.empty()) {
            cout << "E" << endl;
        } else {
            for (int disk : line) {
                if (disk == line.back()) {
                    cout << disk;
                } else {
                    cout << disk << " ";
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}

void hanoi(int n, int a, int c, int b, vector<vector<int>>& rods) {
    if (n == 1) {
        rods[c].push_back(rods[a].back());
        rods[a].pop_back();
//        process_print(rods);
        return;
    }
    hanoi(n - 1, a, b, c, rods);
    rods[c].push_back(rods[a].back());
    rods[a].pop_back();
//    process_print(rods);
    hanoi(n - 1, b, c, a, rods);
}

int main() {
    vector<string> source_v;
    string line;

    while (cin) {
        getline(cin, line);
        source_v.push_back(line);
    }

    vector<vector<int>> rods(3);

    int n = source_v[0][0] - '0';
    n += 1;
    for (int i = n - 1; i >= 0; i--) {
        rods[0].push_back(i);
    }

    hanoi(n, 0, 2, 1, rods);
    process_print(rods);
}