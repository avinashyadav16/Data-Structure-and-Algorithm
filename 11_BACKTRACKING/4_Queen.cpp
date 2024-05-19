/**
 *  @file: 4_Queen.cpp
 *  @author: Avinash Yadav
 *  @brief: The 4-queens problem is a classic example of the N-queens puzzle,
            where the goal is to place 4 queens on a 4x4 chessboard such that no two queens threaten each other. '
            This means no two queens can be in the same row, column, or diagonal.
 *  @date: 19-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// A utility function to print the solution
void printSolution(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

// A utility function to check if a queen can
// be placed on board[row][col]. Note that this
// function is called when "col" queens are
// already placed in columns from 0 to col -1.
// So we need to check only left side for
// attacking queens
bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int i, j;
    int N = board.size();

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// A recursive utility function to solve N
// Queens problem
bool solveNQUtil(vector<vector<int>> &board, int col)
{
    int N = board.size();

    // If all queens are placed, return true
    if (col >= N)
        return true;

    // Consider this column and try placing
    // this queen in all rows one by one
    for (int i = 0; i < N; i++)
    {
        // Check if the queen can be placed on
        // board[i][col]
        if (isSafe(board, i, col))
        {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col]
            // doesn't lead to a solution, then
            // remove queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in
    // this column col, then return false
    return false;
}

// This function solves the N Queens problem using
// Backtracking. It mainly uses solveNQUtil() to
// solve the problem. It returns false if queens
// cannot be placed, otherwise, it returns true and
// prints the placement of queens in the form of 1s.
// Please note that there may be more than one
// solutions, this function prints one of the
// feasible solutions.
bool solveNQ(int N)
{
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQUtil(board, 0))
    {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printSolution(board);
    return true;
}

int main()
{
    // Set N here for N-Queens problem
    int N = 4;

    solveNQ(N);

    return 0;
}