//
// Created by 蔡宇泉 on 2024/4/11.
//
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void display_board(vector < vector<int> > board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << " " << setw(2) << board[i][j];
        }
        cout << endl;
    }
}

bool step_valid(int x, int y, vector < vector<int> > & board) {
    return (x >= 0 and y >= 0 and x < board.size() and y < board[0].size() and board[x][y] == 0);
}

bool find_solution(int x, int y, int step, vector < vector<int> > & board) {
    if (step == board.size() * board[0].size() + 1) {
        return true;
    }

    int step_x[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int step_y[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; i++) {
        int next_x = x + step_x[i];
        int next_y = y + step_y[i];
        if (step_valid(next_x, next_y, board)) {
            board[next_x][next_y] = step;
            if (find_solution(next_x, next_y, step + 1, board))
                return true;
            else
                board[next_x][next_y] = 0;
        }
    }
    return false;
}

int main() {
    int m, n;
    string input;
    cin >> m >> n;

    vector < vector<int> > board(m, vector<int> (n, 0));
    board[m - 1][0] = 1;

    if (find_solution(m - 1, 0, 2, board)) {
        display_board(board);
    } else {
        board[m - 1][0] = 0;
        display_board(board);
        cout << "No tour exists for this board." << endl;
    }
    return 0;
}