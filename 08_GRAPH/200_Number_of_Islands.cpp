/**
*  @file: 200_Number_of_Islands.cpp
*  @author: Avinash Yadav
*  @date: 18-06-2025
*  @link: https://leetcode.com/problems/number-of-islands/description/
*  @link: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
*  @brief: Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
            An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
            You may assume all four edges of the grid are all surrounded by water.

            Example 1:
                Input: grid = [
                ["1","1","1","1","0"],
                ["1","1","0","1","0"],
                ["1","1","0","0","0"],
                ["0","0","0","0","0"]
                ]
                Output: 1

            Example 2:
                Input: grid = [
                ["1","1","0","0","0"],
                ["1","1","0","0","0"],
                ["0","0","1","0","0"],
                ["0","0","0","1","1"]
                ]
                Output: 3

*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// BFS
//////////////////////////////////////////////////////////////////////////////////

class Solution
{
public:
    // Function to perform BFS traversal from cell (r, c)
    void bfsTraversal(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Mark the starting cell as visited
        vis[r][c] = true;

        // Queue for BFS
        queue<pair<int, int>> q;

        // Push the starting cell
        q.push(make_pair(r, c));

        // BFS loop
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Directions: up, right, down, left
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            // Explore all 4 directions
            for (int dir = 0; dir < 4; dir++)
            {
                int newR = row + dr[dir];
                int newC = col + dc[dir];

                // Check if the new cell is within bounds,
                // is land ('1'), and not visited
                if (newR >= 0 && newR < m &&
                    newC >= 0 && newC < n &&
                    grid[newR][newC] == '1' &&
                    !vis[newR][newC])
                {
                    // Mark as visited
                    vis[newR][newC] = true;

                    // Add to queue for further exploration
                    q.push(make_pair(newR, newC));
                }
            }

            /*
            // If movement horizontally, vertically or diagonally allowed.
                for(int r = -1; r<=1; r++)
                {
                    for(int c = -1; c<=1; c++)
                    {
                        int newR = row + r;
                        int newC = col + c;

                        if (newR >= 0 && newR < m &&
                            newC >= 0 && newC < n &&
                            grid[newR][newC] == 1 &&
                            !vis[newR][newC])
                        {
                            vis[newR][newC] = true;

                            q.push(make_pair(newR, newC));
                        }
                    }
                }
            */
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        // Number of rows
        int m = grid.size();

        // Number of columns
        int n = grid[0].size();

        // Visited matrix to keep track of visited cells
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int cnt = 0; // Island count

        // Traverse each cell in the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If cell is land and not visited, it's a new island
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    // Increment island count
                    cnt++;

                    // Mark all connected land cells
                    bfsTraversal(i, j, grid, vis);
                }
            }
        }

        // Return total number of islands
        return cnt;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                  {'1', '1', '0', '1', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '0', '0', '0'}}; // Output: 1

    vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '1', '0', '0'},
                                  {'0', '0', '0', '1', '1'}}; // Output: 3

    vector<vector<char>> grid3 = {{'1', '1', '0', '0', '0'},
                                  {'0', '1', '0', '0', '1'},
                                  {'1', '0', '0', '1', '1'},
                                  {'0', '0', '0', '0', '0'},
                                  {'1', '0', '1', '1', '0'}}; // Output: 5

    cout << "OUTPUT IS: " << endl;
    Solution sol1;
    cout << sol1.numIslands(grid1) << endl;
    cout << sol1.numIslands(grid2) << endl;
    cout << sol1.numIslands(grid3) << endl;

    return 0;
}