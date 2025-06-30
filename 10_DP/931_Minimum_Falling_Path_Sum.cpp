/**
*  @file: 931_Minimum_Falling_Path_Sum.cpp
*  @author: Avinash Yadav
*  @date: 16-06-2025
*  @link: https://leetcode.com/problems/minimum-falling-path-sum/description/
*  @link:
*  @brief: Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

            A falling path starts at any element in the first row and
            chooses the element in the next row that is either directly below or diagonally left/right.
            Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

            Example 1:
                Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
                Output: 13

            Example 2:
                Input: matrix = [[-19,57],[-40,-5]]
                Output: -59.
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    // Recursive function to compute the minimum falling path sum ending at (i, j)
    int minPathVal(int i, int j, int n, vector<vector<int>> &matrix)
    {
        // If column index is out of bounds,
        // return a large value (acts as infinity)
        if (j < 0 || j >= n)
        {
            return 1e9;
        }

        // Base case:
        // If we're at the first row, just return the value at (0, j)
        if (i == 0)
        {
            return matrix[0][j];
        }

        // Recursively compute the minimum path sum
        // from the three possible previous positions

        // directly above
        int up = matrix[i][j] + minPathVal(i - 1, j, n, matrix);

        // diagonally left above
        int leftDia = matrix[i][j] + minPathVal(i - 1, j - 1, n, matrix);

        // diagonally right above
        int rightDia = matrix[i][j] + minPathVal(i - 1, j + 1, n, matrix);

        // Return the minimum of the three possible paths
        return min(up, min(leftDia, rightDia));
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        // number of rows
        int m = matrix.size();

        // number of columns
        int n = matrix[0].size();

        int mini = INT_MAX;

        // Try starting from every cell in the last row and take the minimum
        for (int col = 0; col < n; col++)
        {
            mini = min(mini, minPathVal(m - 1, col, n, matrix));
        }

        return mini;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    // Function to compute the minimum path sum to cell (i, j)
    // i: current row, j: current column, n: number of columns
    // matrix: input grid, dp: memoization table
    int minPathVal(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        // If column index is out of bounds,
        // return a large value (invalid path)
        if (j < 0 || j >= n)
        {
            return 1e9;
        }

        // Base case:
        // first row, just return the value at (0, j)
        if (i == 0)
        {
            return matrix[0][j];
        }

        // If already computed,
        // return the stored result
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Recursive calls for the three possible moves:
        // 1. Move straight up
        int up = matrix[i][j] + minPathVal(i - 1, j, n, matrix, dp);

        // 2. Move diagonally up-left
        int leftDia = matrix[i][j] + minPathVal(i - 1, j - 1, n, matrix, dp);

        // 3. Move diagonally up-right
        int rightDia = matrix[i][j] + minPathVal(i - 1, j + 1, n, matrix, dp);

        // Store and return the minimum of the three possible moves
        return dp[i][j] = min(up, min(leftDia, rightDia));
    }

    // Main function to find the minimum falling path sum
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        // Number of rows
        int m = matrix.size();

        // Number of columns
        int n = matrix[0].size();

        // Initialize memoization table with -1 (uncomputed)
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // To keep track of the minimum path sum
        int mini = INT_MAX;

        // Try starting from each cell in the last row and take the minimum
        for (int col = 0; col < n; col++)
        {
            mini = min(mini, minPathVal(m - 1, col, n, matrix, dp));
        }

        return mini;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        // Number of rows
        int m = matrix.size();

        // Number of columns
        int n = matrix[0].size();

        // dp[i][j] will store the minimum falling path sum to cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the first row of dp with the first row of matrix,
        // since the falling path can start from any cell in the first row
        for (int col = 0; col < n; col++)
        {
            dp[0][col] = matrix[0][col];
        }

        // Fill the dp table row by row
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Move straight down from the cell above
                int up = matrix[i][j] + dp[i - 1][j];

                // Move diagonally left from the cell above-left,
                // if within bounds
                int leftDia = INT_MAX;
                if (j - 1 >= 0)
                {
                    leftDia = matrix[i][j] + dp[i - 1][j - 1];
                }

                // Move diagonally right from the cell above-right,
                // if within bounds
                int rightDia = INT_MAX;
                if (j + 1 < n)
                {
                    rightDia = matrix[i][j] + dp[i - 1][j + 1];
                }

                // Take the minimum of the three possible moves
                dp[i][j] = min(up, min(leftDia, rightDia));
            }
        }

        // The answer is the minimum value in the last row of dp,
        // as the falling path can end at any cell in the last row
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution4
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        // Number of rows in the matrix
        int m = matrix.size();

        // Number of columns in the matrix
        int n = matrix[0].size();

        // prevDP stores the minimum path sums for the previous row
        vector<int> prevDP(n);

        // currDP will store the minimum path sums for the current row
        vector<int> currDP(n);

        // Initialize prevDP with the first row of the matrix
        for (int col = 0; col < n; col++)
        {
            prevDP[col] = matrix[0][col];
        }

        // Iterate over each row starting from the second row
        for (int i = 1; i < m; i++)
        {
            // For each cell in the current row
            for (int j = 0; j < n; j++)
            {
                // Calculate the minimum path sum for cell (i, j)
                // Option 1: Coming straight down from the cell above
                int up = matrix[i][j] + prevDP[j];

                // Option 2: Coming from the left diagonal
                // (if within bounds)
                int leftDia = INT_MAX;
                if (j - 1 >= 0)
                {
                    leftDia = matrix[i][j] + prevDP[j - 1];
                }

                // Option 3: Coming from the right diagonal
                // (if within bounds)
                int rightDia = INT_MAX;
                if (j + 1 < n)
                {
                    rightDia = matrix[i][j] + prevDP[j + 1];
                }

                // Take the minimum of the three options
                currDP[j] = min(up, min(leftDia, rightDia));
            }

            // Move to the next row:
            // currDP becomes prevDP for the next iteration
            prevDP = currDP;
        }

        // The answer is the minimum value in the last processed row
        return *min_element(prevDP.begin(), prevDP.end());
    }
};

int main()
{
    vector<vector<int>> matrix1 = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};                            // OUTPUT: 13
    vector<vector<int>> matrix2 = {{-19, 57}, {-40, -5}};                                       // OUTPUT: -59
    vector<vector<int>> matrix3 = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}}; // OUTPUT: 6

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.minFallingPathSum(matrix1) << endl;
    cout << sol1.minFallingPathSum(matrix2) << endl;
    cout << sol1.minFallingPathSum(matrix3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.minFallingPathSum(matrix1) << endl;
    cout << sol2.minFallingPathSum(matrix2) << endl;
    cout << sol2.minFallingPathSum(matrix3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.minFallingPathSum(matrix1) << endl;
    cout << sol3.minFallingPathSum(matrix2) << endl;
    cout << sol3.minFallingPathSum(matrix3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.minFallingPathSum(matrix1) << endl;
    cout << sol4.minFallingPathSum(matrix2) << endl;
    cout << sol4.minFallingPathSum(matrix3) << endl;

    return 0;
}
