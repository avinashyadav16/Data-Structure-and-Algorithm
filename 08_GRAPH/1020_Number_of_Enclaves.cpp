/**
*  @file: 1020_Number_of_Enclaves.cpp
*  @author: Avinash Yadav
*  @date: 19-06-2025
*  @link: https://leetcode.com/problems/number-of-enclaves/description/
*  @brief: You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
            A move consists of walking from one land cell to another adjacent (4-directionally) land cell or
            walking off the boundary of the grid.

            Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

            Example 1:
                Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
                Output: 3
                Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

            Example 2:
                Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
                Output: 0
                Explanation: All 1s are either on the boundary or can reach the boundary.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Visited matrix to keep track of visited land cells
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        queue<pair<int, int>> qp;

        // Add all boundary land cells to the queue and
        // mark them as visited
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Check if cell is on the boundary and is land
                if ((i == 0 || i == m - 1 ||
                     j == 0 || j == n - 1) &&
                    grid[i][j] == 1)
                {
                    qp.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        // Directions for moving up, right, down, left
        vector<int> dr = {-1, 0, +1, 0};
        vector<int> dc = {0, +1, 0, -1};

        // BFS to mark all land cells connected to the boundary
        while (!qp.empty())
        {
            int row = qp.front().first;
            int col = qp.front().second;
            qp.pop();

            for (int i = 0; i < 4; i++)
            {
                int newR = row + dr[i];
                int newC = col + dc[i];

                // Check if the new cell is within bounds,
                // is land, and not visited
                if (newR >= 0 && newR < m &&
                    newC >= 0 && newC < n &&
                    !vis[newR][newC] &&
                    grid[newR][newC] == 1)
                {
                    qp.push({newR, newC});
                    vis[newR][newC] = true;
                }
            }
        }

        int cnt = 0;

        // Count all unvisited land cells (enclaves)
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
