#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row, int col, vector<int> &board)
{
	for (int i = 0; i < row; ++i)
	{
		// Check column and diagonals
		if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
		{
			return false;
		}
	}
	return true;
}
bool solveNQueens(int row, vector<int> &board, int N)
{
	if (row == N)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cout << (board[i] == j ? "Q " : ". ");
			}
			cout << endl;
		}
		return true;
	}
	for (int col = 0; col < N; ++col)
	{
		if (isSafe(row, col, board))
		{
			board[row] = col;
			if (solveNQueens(row + 1, board, N))
				return true;
		}
	}
	return false;
}
int main()
{
	int N;
	cout << "Anurag Kanhed\n";
	cout << "307A028\n";
	cout << "72307409H\n";
	cout << "Enter the size of the chessboard (N): ";
	cin >> N;
	vector<int> board(N, -1); // Initialize the board with -1 (no queen placed)
	if (!solveNQueens(0, board, N))
	{
		cout << "No solution exists for " << N << " queens." << endl;
	}
	return 0;
}
