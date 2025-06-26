/**
 *  @file: N_Queen.cpp
 *  @author: Avinash Yadav
 *  @brief: Place N queens on an N×N chessboard so that no two queens attack each other.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(vector<vector<int>> &board, int row, int col, int N)
{
    // Check the same column upwards for any existing queen
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            // Queen already exists in column
            return false;
        }
    }

    // Check the upper-left diagonal (\ direction)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            // Queen already exists diagonally
            return false;
        }
    }

    // Check the upper-right diagonal (/ direction)
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
        {
            // Queen already exists diagonally
            return false;
        }
    }

    // If no conflict, it's safe to place the queen
    return true;
}

// Recursive function to solve N-Queens problem using backtracking
bool solveNQueens(vector<vector<int>> &board, int row, int N)
{
    // Base case: If all N queens are placed successfully, return true
    if (row == N)
        return true;

    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; col++)
    {
        // Check if the queen can be placed safely
        if (isSafe(board, row, col, N))
        {
            // Place the queen at (row, col)
            board[row][col] = 1;

            // Recursively try to place queens in the next row
            if (solveNQueens(board, row + 1, N))
                return true;

            // Backtrack (remove queen) if placement fails
            board[row][col] = 0;
        }
    }

    // If no placement is possible in this row, return false
    return false;
}

int main()
{
    int N;
    cin >> N;

    // Create an N x N chessboard initialized with zeros (empty cells)
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Solving the N-Queens problem
    if (solveNQueens(board, 0, N))
    {
        // Solution exists, print the board
        cout << "YES\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // Print 1 for queen, 0 for empty cell
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        // If no valid placement exists
        cout << "NO\n";
    }

    return 0;
}
