/**
 *  @file: Number_of_Distinct_Islands.cpp
 *  @author: Avinash Yadav
 *  @date: 19-06-2025
 *  @link: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
 *  @brief: Given a boolean 2D matrix grid of size n * m.
 *          You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island.
 *          Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

            Example 1:
                Input:
                grid[][] = {{1, 1, 0, 0, 0},
                            {1, 1, 0, 0, 0},
                            {0, 0, 0, 1, 1},
                            {0, 0, 0, 1, 1}}

                Output:
                1

                Explanation:
                grid[][] = {{1, 1, 0, 0, 0},
                            {1, 1, 0, 0, 0},
                            {0, 0, 0, 1, 1},
                            {0, 0, 0, 1, 1}}
                Same colored islands are equal.
                We have 2 equal islands, so we
                have only 1 distinct island.


            Example 2:
                Input:
                grid[][] = {{1, 1, 0, 1, 1},
                            {1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1},
                            {1, 1, 0, 1, 1}}

                Output:
                3

                Explanation:
                grid[][] = {{1, 1, 0, 1, 1},
                            {1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1},
                            {1, 1, 0, 1, 1}}
                Same colored islands are equal.
                We have 4 islands, but 2 of them
                are equal, So we have 3 distinct islands.

 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Directions for moving up, right, down, left
    vector<int> dr = {-1, 0, +1, 0};
    vector<int> dc = {0, +1, 0, -1};

    // DFS traversal to explore an island and
    // record its shape relative to the starting cell
    void dfsTraversal(int row, int col,
                      int baseR, int baseC,
                      vector<vector<int>> &grid,
                      vector<pair<int, int>> &vp,
                      vector<vector<bool>> &vis)
    {
        // Mark current cell as visited
        vis[row][col] = true;

        // Store the relative position of the cell
        // with respect to the starting cell
        vp.push_back({row - baseR, col - baseC});

        int m = grid.size();
        int n = grid[0].size();

        // Explore all 4 directions
        for (int i = 0; i < 4; i++)
        {
            int newR = row + dr[i];
            int newC = col + dc[i];

            // Check if the new cell is within bounds,
            // not visited, and is land (1)
            if (newR >= 0 && newR < m &&
                newC >= 0 && newC < n &&
                !vis[newR][newC] &&
                grid[newR][newC])
            {
                dfsTraversal(newR, newC, baseR, baseC, grid, vp, vis);
            }
        }
    }

    // Main function to count distinct islands
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Visited matrix to keep track of visited cells
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Set to store unique island shapes
        // (as vectors of relative positions)
        set<vector<pair<int, int>>> stVP;

        // Traverse the entire grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If cell is unvisited and is land,
                // start a new DFS
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    // To store the shape of the current island
                    vector<pair<int, int>> vp;

                    // Perform DFS to record the shape
                    dfsTraversal(i, j, i, j, grid, vp, vis);

                    // Insert the shape into the set
                    // (only unique shapes will be stored)
                    stVP.insert(vp);
                }
            }
        }

        // The number of distinct islands is the size of the set
        return stVP.size();
    }
};
