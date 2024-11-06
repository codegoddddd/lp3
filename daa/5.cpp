// Design n-Queens matrix having first Queen placed. Use backtracking to place remaining 
// Queens to generate the final n-queen‘s matrix.

// TC - O(n!)
// SC - O(n^2)
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check this row on left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return false;
    }
    
    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    if (col >= n)  // All queens placed
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;  // Place queen at (i, col)

            if (solveNQueens(board, col + 1, n)) // Recurse to place next queen
                return true;

            board[i][col] = 0;  // Backtrack: remove queen from (i, col)
        }
    }

    return false;  // No place found in this column
}

void printBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (n): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    // Place the first queen manually
    int firstRow, firstCol;
    cout << "Enter the position of the first queen (row and column): ";
    cin >> firstRow >> firstCol;

    // Adjust for 0-based indexing
    if (firstRow < 0 || firstRow >= n || firstCol < 0 || firstCol >= n) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    board[firstRow][firstCol] = 1;  // Place the first queen

    // Start placing remaining queens from the next column
    if (solveNQueens(board, 1, n)) {
        cout << "Solution for the " << n << "-Queens problem:" << endl;
        printBoard(board, n);
    } else {
        cout << "No solution exists for the given initial position." << endl;
    }

    return 0;
}
