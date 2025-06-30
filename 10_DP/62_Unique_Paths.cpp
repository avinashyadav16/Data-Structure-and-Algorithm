/**
*  @file: 62_Unique_Paths.cpp
*  @author: Avinash Yadav
*  @date: 15-06-2025
*  @link: https://leetcode.com/problems/unique-paths/description/
*  @brief: There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
            The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
            The robot can only move either down or right at any point in time.
            Given the two integers m and n,
            return the number of possible unique paths that the robot can take to reach the bottom-right corner.

            The test cases are generated so that the answer will be less than or equal to 2 * 109.

            Example 1:
                Input: m = 3, n = 7
                Output: 28

            Example 2:
                Input: m = 3, n = 2
                Output: 3
                Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
                    1. Right -> Down -> Down
                    2. Down -> Down -> Right
                    3. Down -> Right -> Down
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    // Recursive helper function to count unique paths to cell (i, j)
    int totalUniquePaths(int i, int j)
    {
        // Base case: reached the starting cell (0, 0)
        if (i == 0 && j == 0)
        {
            // Only one way to be at the start
            return 1;
        }

        // Out of bounds:
        // if indices go negative, not a valid path
        if (i < 0 || j < 0)
        {
            return 0;
        }

        // Recursive calls:
        // Move up (decrease row index) and move left (decrease column index)

        // Move from the cell above
        int up = totalUniquePaths(i - 1, j);

        // Move from the cell to the left
        int left = totalUniquePaths(i, j - 1);

        // Total paths to (i, j) is the sum of paths from above and left
        return up + left;
    }

    // Main function to be called with grid size m x n
    int uniquePaths(int m, int n)
    {
        // Start from the bottom-right cell (m-1, n-1)
        return totalUniquePaths(m - 1, n - 1);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    // Recursive helper function to count unique paths to cell (i, j)
    // dp[i][j] stores the number of unique paths to reach (i, j)
    int totalUniquePaths(int i, int j, vector<vector<int>> &dp)
    {
        // Base case: reached the starting cell (0, 0)
        if (i == 0 && j == 0)
        {
            return 1;
        }

        // Out of bounds: not a valid cell
        if (i < 0 || j < 0)
        {
            return 0;
        }

        // If already computed, return the stored result (memoization)
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Move from the cell above (up) and from the cell to the left (left)

        // Move down from above
        int up = totalUniquePaths(i - 1, j, dp);

        // Move right from left
        int left = totalUniquePaths(i, j - 1, dp);

        // Store the result in dp table and return
        return dp[i][j] = (up + left);
    }

    // Main function to be called with grid size m x n
    int uniquePaths(int m, int n)
    {
        // Initialize dp table with -1 (uncomputed)
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Start recursion from the bottom-right cell (m-1, n-1)
        return totalUniquePaths(m - 1, n - 1, dp);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    int uniquePaths(int m, int n)
    {
        // Create a 2D DP table with m rows and n columns, initialized to 0
        // dp[i][j] will store the number of unique paths to reach cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Iterate over each cell in the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Base case:
                // The starting cell (0, 0) has exactly one way to be reached
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    // Number of ways from the cell above
                    int up = 0;

                    // Number of ways from the cell to the left
                    int left = 0;

                    // If not in the first row,
                    // add the number of ways from the cell above
                    if (i > 0)
                    {
                        up = dp[i - 1][j];
                    }

                    // If not in the first column,
                    // add the number of ways from the cell to the left
                    if (j > 0)
                    {
                        left = dp[i][j - 1];
                    }

                    // Total ways to reach (i, j) is
                    // sum of ways from above and left
                    dp[i][j] = up + left;
                }
            }
        }

        // The answer is the
        // number of ways to reach the bottom-right cell (m-1, n-1)
        return dp[m - 1][n - 1];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution4
{
public:
    int uniquePaths(int m, int n)
    {
        // prevDP[j] will store the number of unique paths to reach cell (i-1, j)
        // We only need to keep track of the previous row to save space.
        vector<int> prevDP(n, 0);

        // Iterate over each row of the grid
        for (int i = 0; i < m; i++)
        {
            // tempDP[j] will store the number of unique paths to reach cell (i, j)
            vector<int> tempDP(n, 0);

            // Iterate over each column of the current row
            for (int j = 0; j < n; j++)
            {
                // Base case:
                // The starting cell (0, 0) has exactly one way to be reached
                if (i == 0 && j == 0)
                {
                    tempDP[j] = 1;
                }
                else
                {
                    int up = 0;   // Number of ways from the cell above
                    int left = 0; // Number of ways from the cell to the left

                    // If not in the first row,
                    // add the number of ways from the cell above
                    if (i > 0)
                    {
                        up = prevDP[j];
                    }

                    // If not in the first column,
                    // add the number of ways from the cell to the left
                    if (j > 0)
                    {
                        left = tempDP[j - 1];
                    }

                    // Total ways to reach (i, j) is sum of ways from above and left
                    tempDP[j] = up + left;
                }
            }

            // After processing the current row, update prevDP to be the current row
            prevDP = tempDP;
        }

        // The answer is the number of ways to reach the bottom-right cell (m-1, n-1)
        return prevDP[n - 1];
    }
};

int main()
{

    int m1 = 3;
    int n1 = 7;
    // OUTPUT: 28

    int m2 = 3;
    int n2 = 2;
    // OUTPUT: 3

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.uniquePaths(m1, n1) << endl;
    cout << sol1.uniquePaths(m2, n2) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.uniquePaths(m1, n1) << endl;
    cout << sol2.uniquePaths(m2, n2) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.uniquePaths(m1, n1) << endl;
    cout << sol3.uniquePaths(m2, n2) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.uniquePaths(m1, n1) << endl;
    cout << sol4.uniquePaths(m2, n2) << endl;

    return 0;
}