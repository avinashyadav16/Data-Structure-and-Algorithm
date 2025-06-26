/**
*  @file: 37_Sudoku_Solver.cpp
*  @author: Avinash Yadav
*  @date: 10-06-2025
*  @link:
*  @brief: Write a program to solve a Sudoku puzzle by filling the empty cells.
            A sudoku solution must satisfy all of the following rules:
                Each of the digits 1-9 must occur exactly once in each row.
                Each of the digits 1-9 must occur exactly once in each column.
                Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

            The '.' character indicates empty cells.
            Input:
                board =
                        [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
            Output:
                        [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
*/

#include <bits/stdc++.h>
using namespace std;

// Solution class to solve the Sudoku puzzle using backtracking
class Solution
{
public:
    // Function to check if placing 'ch' at board[row][col] is valid
    bool isValid(vector<vector<char>> &board, int row, int col, char ch)
    {
        for (int i = 0; i < 9; i++)
        {
            // Check if 'ch' is already present in the current row
            if (board[row][i] == ch)
            {
                return false;
            }

            // Check if 'ch' is already present in the current column
            if (board[i][col] == ch)
            {
                return false;
            }

            // Check if 'ch' is already present in the current 3x3 sub-box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            {
                return false;
            }
        }

        // If 'ch' is not present in row, column, or sub-box, it's valid
        return true;
    }

    // Recursive function to solve the board using backtracking
    bool solvedBoard(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // If the current cell is empty
                if (board[i][j] == '.')
                {
                    // Try all possible digits from '1' to '9'
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        // If placing 'ch' is valid
                        if (isValid(board, i, j, ch))
                        {
                            // Place 'ch'
                            board[i][j] = ch; 

                            // Recursively try to solve the rest of the board
                            if (solvedBoard(board) == true)
                            {
                                // If solved, return true
                                return true;
                            }
                            else
                            {
                                // Backtrack if not solved
                                board[i][j] = '.';
                            }
                        }
                    }

                    // If no valid digit found, return false to trigger backtracking
                    return false;
                }
            }
        }

        // If all cells are filled correctly, return true
        return true;
    }

    // Main function to be called to solve the Sudoku
    void solveSudoku(vector<vector<char>> &board)
    {
        solvedBoard(board);
    }
};

///////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
// FOR TAKING INPUTS

void readBoardInput(vector<vector<char>> &board)
{
    string input;
    getline(cin, input);

    vector<vector<char>> tempBoard;
    vector<char> row;
    bool inQuotes = false;

    for (char c : input)
    {
        if (c == '"')
        {
            inQuotes = !inQuotes;
        }
        else if (inQuotes)
        {
            row.push_back(c);
        }
        else if (c == ']')
        {
            if (!row.empty())
            {
                tempBoard.push_back(row);
                row.clear();
            }
        }
    }

    board = tempBoard;
}

int main()
{
    vector<vector<char>> board;
    readBoardInput(board);

    Solution sol;

    sol.solveSudoku(board);

    for (auto &row : board)
    {
        for (char c : row)
        {
            cout << c << ' ';
        }
        cout << endl;
    }

    return 0;
}
