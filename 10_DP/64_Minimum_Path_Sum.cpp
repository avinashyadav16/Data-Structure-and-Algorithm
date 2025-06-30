/**
*  @file: 64_Minimum_Path_Sum.cpp
*  @author: Avinash Yadav
*  @date: 15-06-2025
*  @link: https://www.naukri.com/code360/problems/minimum-path-sum_985349
*  @link: https://leetcode.com/problems/minimum-path-sum/
*  @brief: Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns.
            Each point in the grid has some cost associated with it.
            Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1)
            which minimizes the sum of the cost of all the numbers along the path.
            You need to tell the minimum sum of that path.

            Note:
            You can only move down or right at any point in time.

            Sample Input 1:
                2 3
                5 9 6
                11 5 2
            Sample Output 1:
                21
            Explanation For Sample Output 1:
                In test case 1, Consider a grid of 2*3:
                For this the grid the path with minimum value is (0,0) -> (0,1) -> (1,1) -> (1,2).
                And the sum along this path is 5 + 9 +5 + 2 = 21. So the ans is 21.


            Sample Input 2:
                3 3
                1 2 3
                4 5 4
                7 5 9

            Sample Output 2:
                19
            Explanation For Sample Output 2:
                For this the grid the path with minimum value is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2).
                The sum along this path is 1 + 2 + 3 + 4 + 9 = 19.


*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    // Recursive function to find the minimum path sum to cell (i, j)
    int finalMinPathValue(int i, int j, vector<vector<int>> &grid)
    {
        // Base case:
        // If we are at the starting cell (0, 0), return its value
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }

        // If out of bounds, return a large value (acts as infinity)
        if (i < 0 || j < 0)
        {
            return 9999;
        }

        // Recursive call: move from the cell above (i-1, j)
        int up = grid[i][j] + finalMinPathValue(i - 1, j, grid);

        // Recursive call: move from the cell to the left (i, j-1)
        int left = grid[i][j] + finalMinPathValue(i, j - 1, grid);

        // Return the minimum of the two possible moves
        return min(up, left);
    }

    // Main function to be called with the grid
    int minPathSum(vector<vector<int>> &grid)
    {
        // Number of rows
        int m = grid.size();

        // Number of columns
        int n = grid[0].size();

        // Start recursion from the bottom-right cell
        return finalMinPathValue(m - 1, n - 1, grid);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    // Recursive function to find the minimum path sum to cell (i, j)
    // Uses memoization to avoid recomputation
    int finalMinPathValue(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        // Base case: if at the starting cell, return its value
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }

        // If out of bounds, return a large number (acts as infinity)
        if (i < 0 || j < 0)
        {
            return 9999;
        }

        // If already computed, return the stored result
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Calculate the minimum path sum from the top and left neighbors
        int up = grid[i][j] + finalMinPathValue(i - 1, j, grid, dp);
        int left = grid[i][j] + finalMinPathValue(i, j - 1, grid, dp);

        // Store and return the minimum of the two possible paths
        return dp[i][j] = min(up, left);
    }

    // Main function to be called with the grid
    int minPathSum(vector<vector<int>> &grid)
    {
        // Number of rows
        int m = grid.size();

        // Number of columns
        int n = grid[0].size();

        // Initialize dp array with -1 (means not computed yet)
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Start recursion from the bottom-right cell
        return finalMinPathValue(m - 1, n - 1, grid, dp);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // Number of rows in the grid
        int m = grid.size();

        // Number of columns in the grid
        int n = grid[0].size();

        // Create a 2D dp array
        // to store the minimum path sum to each cell
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Iterate over each cell in the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Base case: starting cell (0, 0)
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                }
                else
                {
                    // Initialize as infinity
                    int up = INT_MAX;

                    // Initialize as infinity
                    int left = INT_MAX;

                    // If not in the first row,
                    // we can come from the cell above
                    if (i > 0)
                    {
                        up = grid[i][j] + dp[i - 1][j];
                    }

                    // If not in the first column,
                    // we can come from the cell to the left
                    if (j > 0)
                    {
                        left = grid[i][j] + dp[i][j - 1];
                    }

                    // The minimum path sum to (i, j)
                    // is the minimum of coming from above or left
                    dp[i][j] = min(up, left);
                }
            }
        }

        // The answer is the
        // minimum path sum to the bottom-right cell
        return dp[m - 1][n - 1];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution4
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // prevDP will store the minimum path sum for the previous row
        vector<int> prevDP(n, INT_MAX);

        for (int i = 0; i < m; i++)
        {
            // tempDP will store the minimum path sum for the current row
            vector<int> tempDP(n, INT_MAX);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    // Base case: starting cell (0,0)
                    tempDP[j] = grid[i][j];
                }
                else
                {
                    int up = INT_MAX;
                    int left = INT_MAX;

                    // If not in the first row, we can come from above
                    if (i > 0)
                    {
                        up = prevDP[j] + grid[i][j];
                    }

                    // If not in the first column, we can come from the left
                    if (j > 0)
                    {
                        left = tempDP[j - 1] + grid[i][j];
                    }

                    // Take the minimum of coming from above or left
                    tempDP[j] = min(up, left);
                }
            }
            // Move to the next row: current row becomes previous row
            prevDP = tempDP;
        }

        // The answer is the minimum path sum to the bottom-right cell
        return prevDP[n - 1];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<vector<int>> grid1 = {{5, 9, 6}, {11, 5, 2}};           // OUTPUT: 21
    vector<vector<int>> grid2 = {{1, 2, 3}, {4, 5, 4}, {7, 5, 9}}; // OUTPUT: 19
    vector<vector<int>> grid3 = {{1, 2, 3}, {4, 5, 6}};            // OUTPUT: 12

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.minPathSum(grid1) << endl;
    cout << sol1.minPathSum(grid2) << endl;
    cout << sol1.minPathSum(grid3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.minPathSum(grid1) << endl;
    cout << sol2.minPathSum(grid2) << endl;
    cout << sol2.minPathSum(grid3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.minPathSum(grid1) << endl;
    cout << sol3.minPathSum(grid2) << endl;
    cout << sol3.minPathSum(grid3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.minPathSum(grid1) << endl;
    cout << sol4.minPathSum(grid2) << endl;
    cout << sol4.minPathSum(grid3) << endl;

    return 0;
}