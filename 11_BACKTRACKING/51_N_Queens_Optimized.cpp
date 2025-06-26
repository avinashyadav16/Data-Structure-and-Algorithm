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

// Class to solve the N-Queens problem using optimized backtracking
class Solution
{
public:
    /**
     * @brief Recursive helper function to place queens column by column.
     *
     * @param col Current column to place the queen.
     * @param n Size of the board (number of queens).
     * @param res Reference to the result vector to store all valid board configurations.
     * @param board Current state of the chessboard.
     * @param leftRow Array to mark if a queen is placed in a particular row.
     * @param upperDiagonal Array to mark if a queen is placed in the upper diagonal (row + col).
     * @param lowerDiagonal Array to mark if a queen is placed in the lower diagonal (n - 1 + col - row).
     */
    void placeQueen(
        int col,
        int &n,
        vector<vector<string>> &res,
        vector<string> &board,
        vector<int> &leftRow,
        vector<int> &upperDiagonal,
        vector<int> &lowerDiagonal)
    {
        // Base case: All queens are placed successfully
        if (col == n)
        {
            // Store the current valid board configuration
            res.push_back(board);
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++)
        {
            // Check if the current position is safe:
            // - No queen in the same row (leftRow)
            // - No queen in the same upper diagonal (upperDiagonal)
            // - No queen in the same lower diagonal (lowerDiagonal)
            if (leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n - 1 + col - row] == 0)
            {
                // Place the queen at (row, col)
                board[row][col] = 'Q';

                // Mark the row and diagonals as occupied
                leftRow[row] = 1;
                upperDiagonal[row + col] = 1;
                lowerDiagonal[n - 1 + col - row] = 1;

                // Recurse to place the next queen in the next column
                placeQueen(col + 1, n, res, board, leftRow, upperDiagonal, lowerDiagonal);

                // Backtrack: Remove the queen and unmark the row and diagonals
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[row + col] = 0;
                lowerDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    /**
     * @brief Main function to solve the N-Queens problem.
     *
     * @param n Size of the board (number of queens).
     * @return vector<vector<string>> All possible valid board configurations.
     */
    vector<vector<string>> solveNQueens(int n)
    {
        // To store all valid solutions
        vector<vector<string>> res;

        // Initialize the chessboard with empty cells ('.')
        vector<string> board(n, string(n, '.'));

        // Arrays to keep track of occupied rows and diagonals
        vector<int> leftRow(n, 0);               // Row occupancy
        vector<int> upperDiagonal(2 * n - 1, 0); // Upper diagonal occupancy
        vector<int> lowerDiagonal(2 * n - 1, 0); // Lower diagonal occupancy

        // Start placing queens from the first column (col = 0)
        placeQueen(0, n, res, board, leftRow, upperDiagonal, lowerDiagonal);

        // Return all valid solutions
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
