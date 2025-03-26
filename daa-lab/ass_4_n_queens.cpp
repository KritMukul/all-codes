#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& board, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(n, row + 1, board, solutions);
            board[row] = -1; 
        }
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> solutions;
    vector<int> board(n, -1); 

    solveNQueens(n, 0, board, solutions);

    
    cout << "Number of solutions: " << solutions.size() << endl;
    for (auto& sol : solutions) {
        for (int col : sol) {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}
