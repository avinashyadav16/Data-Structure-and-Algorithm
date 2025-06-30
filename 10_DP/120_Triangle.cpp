/**
*  @file: 120_Triangle.cpp
*  @author: Avinash Yadav
*  @date: 16-06-2025
*  @link: https://leetcode.com/problems/triangle/description/
*  @link: https://www.naukri.com/code360/problems/triangle_1229398
*  @brief: Given a triangle array, return the minimum path sum from top to bottom.
            For each step, you may move to an adjacent number of the row below.
            More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
                Example 1:
                    Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
                    Output: 11
                    Explanation: The triangle looks like:
                    2
                    3 4
                    6 5 7
                    4 1 8 3
                    The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11.

                Example 2:
                    Input: triangle = [[-10]]
                    Output: -10
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    // Recursive function to find the minimum path sum from (i, j) to the bottom
    int minPathValue(int i, int j, int &m, vector<vector<int>> &triangle)
    {
        // Base case: if we are at the last row, return the value at (i, j)
        if (i == m - 1)
        {
            return triangle[i][j];
        }

        // Recursive case:
        // Move down to the next row, same column (i+1, j)
        int down = triangle[i][j] + minPathValue(i + 1, j, m, triangle);

        // Move down to the next row, next column (i+1, j+1)
        int rightD = triangle[i][j] + minPathValue(i + 1, j + 1, m, triangle);

        // Return the minimum of the two possible paths
        return min(down, rightD);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        // Number of rows in the triangle
        int m = triangle.size();

        // Start recursion from the top of the triangle (0, 0)
        return minPathValue(0, 0, m, triangle);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    // Function to compute the minimum path sum from (i, j) to the bottom using memoization
    int minPathValue(int i, int j, int &m, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        // Base case: if we are at the last row, return the value at (i, j)
        if (i == m - 1)
        {
            return triangle[i][j];
        }

        // If already computed, return the cached value
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Recursive case:
        // Move down to the next row, same column (i+1, j)
        int down = triangle[i][j] + minPathValue(i + 1, j, m, triangle, dp);

        // Move down to the next row, next column (i+1, j+1)
        int rightD = triangle[i][j] + minPathValue(i + 1, j + 1, m, triangle, dp);

        // Store and return the minimum of the two possible paths
        return dp[i][j] = min(down, rightD);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();

        // Initialize dp with the same structure as triangle,
        // filled with -1
        vector<vector<int>> dp;
        for (int i = 0; i < m; i++)
        {
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }
        // Start recursion from the top of the triangle (0, 0)
        return minPathValue(0, 0, m, triangle, dp);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        // Number of rows in the triangle
        int m = triangle.size();

        // Initialize DP table with the same shape as triangle, filled with -1
        vector<vector<int>> dp;
        for (int i = 0; i < m; i++)
        {
            // Each row in dp matches the size of the corresponding row in triangle
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }

        // Base case:
        // Fill the last row of dp with the values from the triangle's last row
        int lastRowSize = triangle[m - 1].size();
        for (int j = 0; j < lastRowSize; j++)
        {
            dp[m - 1][j] = triangle[m - 1][j];
        }

        // Build the DP table from the second-last row up to the top
        for (int i = m - 2; i >= 0; i--)
        {
            // For each element in the current row
            for (int j = i; j >= 0; j--)
            {
                // The minimum path sum at (i, j) is the value at triangle[i][j]
                // plus the minimum of the two adjacent numbers in the row below

                // Move straight down
                int down = triangle[i][j] + dp[i + 1][j];

                // Move diagonally right
                int rightDia = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, rightDia); // Store the minimum path sum at (i, j)
            }
        }

        // The answer is stored at the top of the triangle (0, 0)
        return dp[0][0];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution4
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();

        // prevDP will store the minimum path sums for the row below the current row
        // Initialize with the last row of the triangle
        vector<int> prevDP(triangle[m - 1]);

        // Start from the second last row and move upwards
        for (int i = m - 2; i >= 0; i--)
        {
            // currDP will store the minimum path sums for the current row
            // Each row i has i+1 elements
            vector<int> currDP(i + 1, 0);

            for (int j = 0; j <= i; j++)
            {
                // For each element,
                // choose the minimum path sum from the two adjacent numbers in the row below

                // Move straight down
                int down = triangle[i][j] + prevDP[j];

                // Move diagonally down-right
                int rightDia = triangle[i][j] + prevDP[j + 1];

                currDP[j] = min(down, rightDia);
            }

            // Update prevDP to be the current row's results for the next iteration
            prevDP = currDP;
        }

        // The answer is now at the top of the triangle
        return prevDP[0];
    }
};

int main()
{
    vector<vector<int>> triangle1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};  // OUTPUT: 11
    vector<vector<int>> triangle2 = {{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}}; // OUTPUT: 14
    vector<vector<int>> triangle3 = {{5}, {-1, 3}, {22, 1, -9}};             // OUTPUT: -1

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.minimumTotal(triangle1) << endl;
    cout << sol1.minimumTotal(triangle2) << endl;
    cout << sol1.minimumTotal(triangle3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.minimumTotal(triangle1) << endl;
    cout << sol2.minimumTotal(triangle2) << endl;
    cout << sol2.minimumTotal(triangle3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.minimumTotal(triangle1) << endl;
    cout << sol3.minimumTotal(triangle2) << endl;
    cout << sol3.minimumTotal(triangle3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.minimumTotal(triangle1) << endl;
    cout << sol4.minimumTotal(triangle2) << endl;
    cout << sol4.minimumTotal(triangle3) << endl;

    return 0;
}
