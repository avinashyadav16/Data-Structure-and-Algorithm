/**
*  @file: 994_Rotting_Oranges.cpp
*  @author: Avinash Yadav
*  @date: 18-06-2025
*  @link: https://leetcode.com/problems/rotting-oranges/description/
*  @brief: You are given an m x n grid where each cell can have one of three values:
                0 representing an empty cell,
                1 representing a fresh orange, or
                2 representing a rotten orange.
                Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
                Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

                Example 1:
                Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
                Output: 4

                Example 2:
                Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
                Output: -1
                Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

                Example 3:
                Input: grid = [[0,2]]
                Output: 0
                Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Visited matrix to track rotten oranges (2 means rotten)
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Queue for BFS: stores ((row, col), time)
        queue<pair<pair<int, int>, int>> qp;

        // Count of fresh oranges
        int totalFresh = 0;

        // Initialize the queue with all initially rotten oranges
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    // Push rotten orange position and time 0
                    qp.push({{i, j}, 0});
                    vis[i][j] = 2; // Mark as visited/rotten
                }
                else if (grid[i][j] == 1)
                {
                    // Count fresh oranges
                    totalFresh++;
                }
            }
        }

        // If there are no fresh oranges, nothing to do
        if (totalFresh == 0)
        {
            return 0;
        }

        // Track the maximum time taken to rot all oranges
        int maxTime = 0;

        // Count of fresh oranges that have become rotten
        int currCnt = 0;

        // Directions for 4-adjacency (up, right, down, left)
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        // BFS traversal
        while (!qp.empty())
        {
            int row = qp.front().first.first;
            int col = qp.front().first.second;
            int currTime = qp.front().second;

            // Update max time
            maxTime = max(maxTime, currTime);

            qp.pop();

            // Check all 4 directions
            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                // If the adjacent cell is within bounds,
                // is a fresh orange, and not yet rotten
                if (newRow >= 0 && newRow < m &&
                    newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 1 &&
                    vis[newRow][newCol] != 2)
                {
                    // Rot the fresh orange and
                    // add to queue with incremented time
                    qp.push({{newRow, newCol}, currTime + 1});

                    // Mark as rotten
                    vis[newRow][newCol] = 2;

                    // Increment count of rotten fresh oranges
                    currCnt++;
                }
            }
        }

        // If all fresh oranges have become rotten,
        // return the time taken; else, return -1
        return (totalFresh == currCnt) ? maxTime : -1;
    }
};

int main()
{

    vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}; // Output: 4
    vector<vector<int>> grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}; // Output: -1
    vector<vector<int>> grid3 = {{0, 2}};                          // Output: 0

    Solution sol1;

    cout << sol1.orangesRotting(grid1) << endl;
    cout << sol1.orangesRotting(grid2) << endl;
    cout << sol1.orangesRotting(grid3) << endl;

    return 0;
}