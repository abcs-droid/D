#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 1)
            return false;
    }

    
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return false;
    }

    
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueen(vector<vector<int>>& board, int row, int n) {
    
    if(row == n) {
        return true;
    }

  
    for(int col = 0; col < n; col++) {
        if(isSafe(board, row, col, n)) {
            board[row][col] = 1;   

            if(solveNQueen(board, row + 1, n)) 
                return true;

            board[row][col] = 0;   
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if(solveNQueen(board, 0, n)) {
        cout << "Solution:\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } 
    else {
        cout << "No solution exists for " << n << " queens.";
    }

    return 0;
}
