/**
 *  @file: Word_Search.cpp
 *  @brief: This file contains the implementation of the solution to the Word Search problem.
 *          The problem is to determine if a given word exists in a 2D grid of characters.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    // Directions for moving in the grid (right, down, left, up).
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    /**
     * @brief Helper function to perform DFS and find the word in the grid.
     *
     * @param i Current row index.
     * @param j Current column index.
     * @param m Total number of rows in the grid.
     * @param n Total number of columns in the grid.
     * @param idx Current index in the word being searched.
     * @param board The 2D grid of characters.
     * @param word The word to be searched.
     * @return true if the word is found, false otherwise.
     */
    bool find(int i, int j, int m, int n, int idx, vector<vector<char>> &board, string &word)
    {
        // If the entire word is found, return true.
        if (idx == word.size())
        {
            return true;
        }

        // If out of bounds or character does not match, return false.
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '$' || board[i][j] != word[idx])
        {
            return false;
        }

        // Temporarily mark the current cell as visited.
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore all 4 possible directions.
        for (int dx = 0; dx < 4; dx++)
        {
            int newI = i + dir[dx][0];
            int newJ = j + dir[dx][1];

            // Recursively search in the new direction.
            if (find(newI, newJ, m, n, idx + 1, board, word))
            {
                return true;
            }
        }

        // Restore the original value of the cell.
        board[i][j] = temp;

        return false;
    }

    /**
     * @brief Determines if the word exists in the grid.
     *
     * @param board The 2D grid of characters.
     * @param word The word to be searched.
     * @return true if the word exists in the grid, false otherwise.
     */
    bool exist(vector<vector<char>> &board, string word)
    {
        // Total number of rows in the grid.
        int m = board.size();

        // Total number of columns in the grid.
        int n = board[0].size();

        // Iterate through each cell in the grid.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If the first character matches, start the search.
                if (board[i][j] == word[0] && find(i, j, m, n, 0, board, word))
                {
                    return true;
                }
            }
        }

        // Return false if the word is not found.
        return false;
    }
};

int main()
{
    Solution sol;

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";

    bool result = sol.exist(board, word);

    cout << (result ? "Word found in the board." : "Word not found in the board.") << endl;

    return 0;
}