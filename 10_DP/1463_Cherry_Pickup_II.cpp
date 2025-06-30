/**
*  @file: 1463_Cherry_Pickup_II.cpp
*  @author: Avinash Yadav
*  @date: 17-06-2025
*  @link: https://leetcode.com/problems/cherry-pickup-ii/description/
*  @link: https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885
*  @brief: You are given a rows x cols matrix grid representing a field of cherries
             where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

             You have two robots that can collect cherries for you:
                Robot #1 is located at the top-left corner (0, 0), and
                Robot #2 is located at the top-right corner (0, cols - 1).

            Return the maximum number of cherries collection using both robots by following the rules below:
                - From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
                - When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
                - When both robots stay in the same cell, only one takes the cherries.
                - Both robots cannot move outside of the grid at any moment.
                - Both robots should reach the bottom row in grid.

*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH (without memoization):
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    // Function to calculate the maximum cherries collected
    // r: current row
    // col1: current column of robot 1
    // col2: current column of robot 2
    int maxPickSum(int r, int col1, int col2, vector<vector<int>> &grid)
    {
        // If either robot moves out of bounds,
        // return a very small number (invalid path)
        if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
        {
            // Using smaller value for not going out of bound
            return -1e8;
        }

        // If we've reached the last row
        if (r == grid.size() - 1)
        {
            // If both robots are on the same cell, only count cherries once
            if (col1 == col2)
            {
                return grid[r][col1];
            }
            else
            {
                // Otherwise, sum cherries from both cells
                return grid[r][col1] + grid[r][col2];
            }
        }

        int maxi = INT_MIN;

        // Try all possible moves for both robots:
        // -1 (left), 0 (stay), +1 (right)
        for (int dj1 = -1; dj1 <= +1; dj1++)
        {
            for (int dj2 = -1; dj2 <= +1; dj2++)
            {
                int nextCol1 = col1 + dj1;
                int nextCol2 = col2 + dj2;

                // If both robots are on the same cell,
                // only count cherries once
                if (col1 == col2)
                {
                    int curr = grid[r][col1];
                    int next = maxPickSum(r + 1, nextCol1, nextCol2, grid);

                    maxi = max(maxi, curr + next);
                }
                else
                {
                    int curr = grid[r][col1] + grid[r][col2];
                    int next = maxPickSum(r + 1, nextCol1, nextCol2, grid);

                    maxi = max(maxi, curr + next);
                }
            }
        }

        return maxi;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Start from row 0, robot 1 at column 0, robot 2 at last column
        return maxPickSum(0, 0, n - 1, grid);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH FOR CHERRY PICKUP II
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    // Function to compute the maximum cherries collected
    // r: current row, col1: robot 1's column, col2: robot 2's column
    // grid: the input grid, dp: memoization table
    int maxPickSum(int r, int col1, int col2,
                   vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        // If either robot is out of bounds,
        // return a very negative value (invalid path)
        if (col1 < 0 || col1 >= grid[0].size() ||
            col2 < 0 || col2 >= grid[0].size())
        {
            return -1e8;
        }

        // If we've reached the last row
        if (r == grid.size() - 1)
        {
            // If both robots are on the same cell,
            // only count cherries once
            if (col1 == col2)
            {
                return grid[r][col1];
            }
            else
            {
                // Otherwise, sum cherries from both positions
                return grid[r][col1] + grid[r][col2];
            }
        }

        // If already computed, return cached result
        if (dp[r][col1][col2] != -1)
        {
            return dp[r][col1][col2];
        }

        int maxi = INT_MIN;

        // Try all moves for both robots: left (-1), stay (0), right (+1)
        for (int dj1 = -1; dj1 <= +1; dj1++)
        {
            for (int dj2 = -1; dj2 <= +1; dj2++)
            {
                int nextCol1 = col1 + dj1;
                int nextCol2 = col2 + dj2;

                // If robots land on the same cell, only count cherries once
                if (col1 == col2)
                {
                    int curr = grid[r][col1];
                    int next = maxPickSum(r + 1, nextCol1, nextCol2, grid, dp);
                    maxi = max(maxi, curr + next);
                }
                else
                {
                    int curr = grid[r][col1] + grid[r][col2];
                    int next = maxPickSum(r + 1, nextCol1, nextCol2, grid, dp);
                    maxi = max(maxi, curr + next);
                }
            }
        }

        // Memoize and return the result
        return dp[r][col1][col2] = maxi;
    }

    // Function to start the DP from the top row,
    // with robots at (0,0) and (0,n-1)
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // 3D DP table: rows x columns x columns, initialized to -1
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        // Start from row 0, columns 0 and n-1
        return maxPickSum(0, 0, n - 1, grid, dp);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        // Number of rows
        int m = grid.size();

        // Number of columns
        int n = grid[0].size();

        // 3D DP array:
        // dp[row][col1][col2] = max cherries from (row, col1) and (row, col2) to the bottom
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        // Base case: Fill the last row (bottom of the grid)
        for (int col1 = 0; col1 < n; col1++)
        {
            for (int col2 = 0; col2 < n; col2++)
            {
                // If both robots are on the same cell, only count cherries once
                if (col1 == col2)
                {
                    dp[m - 1][col1][col2] = grid[m - 1][col1];
                }
                else
                {
                    // Otherwise, sum cherries from both positions
                    dp[m - 1][col1][col2] = grid[m - 1][col1] + grid[m - 1][col2];
                }
            }
        }

        // Fill the DP table from bottom to top
        for (int r = m - 2; r >= 0; r--)
        {
            for (int col1 = 0; col1 < n; col1++)
            {
                for (int col2 = 0; col2 < n; col2++)
                {
                    int maxi = INT_MIN; // Track the best result for this state

                    // Try all 9 combinations of moves for both robots: -1, 0, +1
                    for (int dj1 = -1; dj1 <= +1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= +1; dj2++)
                        {
                            int currVal = 0;

                            // Collect cherries at current positions
                            if (col1 == col2)
                            {
                                currVal = grid[r][col1];
                            }
                            else
                            {
                                currVal = grid[r][col1] + grid[r][col2];
                            }

                            int nextCol1 = col1 + dj1;
                            int nextCol2 = col2 + dj2;

                            // Check if next positions are within grid bounds
                            if (nextCol1 >= 0 && nextCol1 < n && nextCol2 >= 0 && nextCol2 < n)
                            {
                                currVal += dp[r + 1][nextCol1][nextCol2];
                            }
                            else
                            {
                                // If out of bounds,
                                // use a large negative value to invalidate this path
                                currVal += (-1e8);
                            }

                            // Update the maximum cherries for this state
                            maxi = max(maxi, currVal);
                        }
                    }

                    dp[r][col1][col2] = maxi;
                }
            }
        }

        // Start from the top row, with robots at (0,0) and (0,n-1)
        return dp[0][0][n - 1];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
/*
    This approach reduces the space complexity of the DP solution.
    Instead of maintaining a full 3D DP table (rows x cols x cols),
    we only keep two 2D arrays for the current and previous rows.

    At each step, we compute the DP values for the current row based on the
    values from the next row (which is stored in prevDP). After processing
    a row, we swap currDP and prevDP for the next iteration.

    Time Complexity: O(m * n^2 * 9) = O(m * n^2)
    Space Complexity: O(n^2)
*/
class Solution4
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        // Number of rows
        int m = grid.size();

        // Number of columns
        int n = grid[0].size();

        // prevDP: DP values for the next row (initialized for the last row)
        vector<vector<int>> prevDP(n, vector<int>(n, 0));

        // currDP: DP values for the current row being processed
        vector<vector<int>> currDP(n, vector<int>(n, 0));

        // Base case: Fill DP for the last row (bottom of the grid)
        for (int col1 = 0; col1 < n; col1++)
        {
            for (int col2 = 0; col2 < n; col2++)
            {
                // If both robots are on the same cell, only count cherries once
                if (col1 == col2)
                {
                    prevDP[col1][col2] = grid[m - 1][col1];
                }
                else
                {
                    // Otherwise, sum cherries from both positions
                    prevDP[col1][col2] = grid[m - 1][col1] + grid[m - 1][col2];
                }
            }
        }

        // Process rows from bottom to top (excluding the last row)
        for (int r = m - 2; r >= 0; r--)
        {
            for (int col1 = 0; col1 < n; col1++)
            {
                for (int col2 = 0; col2 < n; col2++)
                {
                    // Track the best result for this state
                    int maxi = INT_MIN;

                    // Try all 9 combinations of moves for both robots: -1, 0, +1
                    for (int dj1 = -1; dj1 <= +1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= +1; dj2++)
                        {
                            int currVal = 0;

                            // Collect cherries at current positions
                            if (col1 == col2)
                            {
                                currVal = grid[r][col1];
                            }
                            else
                            {
                                currVal = grid[r][col1] + grid[r][col2];
                            }

                            int nextCol1 = col1 + dj1;
                            int nextCol2 = col2 + dj2;

                            // Check if next positions are within grid bounds
                            if (nextCol1 >= 0 && nextCol1 < n &&
                                nextCol2 >= 0 && nextCol2 < n)
                            {
                                currVal += prevDP[nextCol1][nextCol2];
                            }
                            else
                            {
                                // If out of bounds,
                                // use a large negative value to invalidate this path
                                currVal += (-1e8);
                            }

                            // Update the maximum cherries for this state
                            maxi = max(maxi, currVal);
                        }
                    }

                    // Store the best result for (r, col1, col2)
                    currDP[col1][col2] = maxi;
                }
            }

            // Move current DP to previous for the next iteration
            prevDP = currDP;
        }

        // The answer is
        // the max cherries collected starting from (0,0) and (0,n-1)
        return prevDP[0][n - 1];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<vector<int>> grid1 = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    // OUTPUT: 24

    vector<vector<int>> grid2 = {{1, 0, 0, 0, 0, 0, 1}, {2, 0, 0, 0, 0, 3, 0}, {2, 0, 9, 0, 0, 0, 0}, {0, 3, 0, 5, 4, 0, 0}, {1, 0, 2, 3, 0, 0, 6}};
    // OUTPUT: 28

    vector<vector<int>> grid3 = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    // OUTPUT: 21

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.cherryPickup(grid1) << endl;
    cout << sol1.cherryPickup(grid2) << endl;
    cout << sol1.cherryPickup(grid3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.cherryPickup(grid1) << endl;
    cout << sol2.cherryPickup(grid2) << endl;
    cout << sol2.cherryPickup(grid3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.cherryPickup(grid1) << endl;
    cout << sol3.cherryPickup(grid2) << endl;
    cout << sol3.cherryPickup(grid3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.cherryPickup(grid1) << endl;
    cout << sol4.cherryPickup(grid2) << endl;
    cout << sol4.cherryPickup(grid3) << endl;

    return 0;
}