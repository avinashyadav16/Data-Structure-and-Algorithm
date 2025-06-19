/**
*  @file: 130_Surrounded_Regions.cpp
*  @author: Avinash Yadav
*  @date: 19-06-2025
*  @link: https://leetcode.com/problems/surrounded-regions/description/
*  @brief: You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
            Connect: A cell is connected to adjacent cells horizontally or vertically.
            Region: To form a region connect every 'O' cell.
            Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and
                        none of the region cells are on the edge of the board.

            To capture a surrounded region, replace all 'O's with 'X's in-place within the original board.
            You do not need to return anything.

            Example 1:
                Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
                Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

            Example 2:
                Input: board = [["X"]]
                Output: [["X"]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Direction vectors for moving up, right, down, and left
    vector<int> dr = {-1, 0, +1, 0};
    vector<int> dc = {0, +1, 0, -1};

    // DFS traversal to mark all 'O's connected to the current cell
    void dfsTraversal(int row, int col, vector<vector<char>> &board,
                      vector<vector<bool>> &vis)
    {
        // Mark current cell as visited
        vis[row][col] = true;

        int m = board.size();
        int n = board[0].size();

        // Explore all four directions
        for (int i = 0; i < 4; i++)
        {
            int newR = row + dr[i];
            int newC = col + dc[i];

            // Check if the new cell is within bounds,
            // not visited, and is 'O'
            if (newR >= 0 && newR < m &&
                newC >= 0 && newC < n &&
                !vis[newR][newC] &&
                board[newR][newC] == 'O')
            {
                // Recursively visit the cell
                dfsTraversal(newR, newC, board, vis);
            }
        }
    }

    // Main function to solve the surrounded regions problem
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        // Matrix to keep track of 'O's connected to the border
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Traverse the first and last row to find border 'O's
        for (int i = 0; i < n; i++)
        {
            if (!vis[0][i] && board[0][i] == 'O')
            {
                // Mark all 'O's connected to top border
                dfsTraversal(0, i, board, vis);
            }

            if (!vis[m - 1][i] && board[m - 1][i] == 'O')
            {
                // Mark all 'O's connected to bottom border
                dfsTraversal(m - 1, i, board, vis);
            }
        }

        // Traverse the first and last column to find border 'O's
        for (int i = 0; i < m; i++)
        {
            if (!vis[i][0] && board[i][0] == 'O')
            {
                // Mark all 'O's connected to left border
                dfsTraversal(i, 0, board, vis);
            }

            if (!vis[i][n - 1] && board[i][n - 1] == 'O')
            {
                // Mark all 'O's connected to right border
                dfsTraversal(i, n - 1, board, vis);
            }
        }

        // Replace all unvisited 'O's (surrounded regions) with 'X'
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If the cell is 'O' and not connected to border,
                // capture it
                if (!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
