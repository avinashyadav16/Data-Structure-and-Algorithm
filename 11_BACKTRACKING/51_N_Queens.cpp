/**
*  @file: 51_N_Queens.cpp
*  @author: Avinash Yadav
*  @date: 10-06-2025
*  @link: https://leetcode.com/problems/n-queens/description/
*  @brief: The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
            Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
            Each solution contains a distinct board configuration of the n-queens' placement,
            where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if it's safe to place a queen at board[row][col]
    bool isSafePosition(int row, int col, int &n, vector<string> &board)
    {
        int dupRow = row;
        int dupCol = col;

        // Check upper-left diagonal
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                // Another queen found on upper-left diagonal
                return false;
            }
            row--;
            col--;
        }

        row = dupRow;
        col = dupCol;
        // Check left side of the current row
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                // Another queen found in the same row to the left
                return false;
            }
            col--;
        }

        row = dupRow;
        col = dupCol;
        // Check lower-left diagonal
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                // Another queen found on lower-left diagonal
                return false;
            }
            row++;
            col--;
        }

        // Safe to place queen
        return true;
    }

    // Recursive function to place queens column by column
    void placeQueen(int col, int &n, vector<vector<string>> &res, vector<string> &board)
    {
        // Base case: All queens are placed
        if (col == n)
        {
            // Store the current board configuration
            res.push_back(board);

            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++)
        {
            if (isSafePosition(row, col, n, board))
            {
                // Place queen
                board[row][col] = 'Q';

                // Recurse for next column
                placeQueen(col + 1, n, res, board);

                // Backtrack: Remove queen
                board[row][col] = '_';
            }
        }
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n)
    {
        // To store all solutions
        vector<vector<string>> res;

        // Current board configuration
        vector<string> board(n);

        // Initialize each row with '_'
        string s(n, '_');

        for (int i = 0; i < n; i++)
        {
            // Fill the board with empty rows
            board[i] = s;
        }

        // Start placing queens from column 0
        placeQueen(0, n, res, board);

        // Return all possible solutions
        return res;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;

    vector<vector<string>> result = sol.solveNQueens(n);

    cout << "[\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "\t[";

        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
            {
                cout << ", ";
            }
        }

        cout << "]";

        if (i < result.size() - 1)
        {
            cout << ",\n";
        }
    }
    cout << "\n]";

    return 0;
}
