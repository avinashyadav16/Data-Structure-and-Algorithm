/**
*  @file: 63_Unique_Path_II.cpp
*  @author: Avinash Yadav
*  @date: 15-06-2025
*  @link: https://www.naukri.com/code360/problems/maze-obstacles_977241
*  @link: https://leetcode.com/problems/unique-paths-ii/description/
*  @brief: Problem statement
            Given a ‘N’ * ’M’ maze with obstacles,
            count and return the number of unique paths to reach the right-bottom cell from the top-left cell.
            A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0.
            From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only.
            Since the answer can be large, print it modulo 10^9 + 7.

            For Example :
                Consider the maze below :
                0 0 0
                0 -1 0
                0 0 0

                There are two ways to reach the bottom left corner -

                (1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
                (1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

                Hence the answer for the above test case is 2.
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    // Recursive function to count unique paths to cell (i, j)
    int totalUniquePaths(int i, int j, vector<vector<int>> &mat)
    {
        // If the cell is an obstacle, return 0 (no path through this cell)
        if (i >= 0 && j >= 0 && mat[i][j] == -1)
        {
            return 0;
        }

        // If reached the starting cell, count as 1 path
        if (i == 0 && j == 0)
        {
            return 1;
        }

        // If out of bounds, return 0
        if (i < 0 || j < 0)
        {
            return 0;
        }

        // Recursively count paths from the cell above and the cell to the left
        int up = totalUniquePaths(i - 1, j, mat);
        int left = totalUniquePaths(i, j - 1, mat);

        // Return total paths modulo MOD
        return (up + left) % MOD;
    }

    // Main function to be called
    int mazeObstacles(int n, int m, vector<vector<int>> &mat)
    {
        return totalUniquePaths(n - 1, m - 1, mat);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    // Recursive function with memoization (DP table)
    int totalUniquePaths(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        // If the cell is an obstacle, return 0
        if (i >= 0 && j >= 0 && mat[i][j] == -1)
        {
            return 0;
        }

        // If reached the starting cell, count as 1 path
        if (i == 0 && j == 0)
        {
            return 1;
        }

        // If out of bounds, return 0
        if (i < 0 || j < 0)
        {
            return 0;
        }

        // If already computed, return cached value
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Recursively count paths from above and left
        int up = totalUniquePaths(i - 1, j, mat, dp);
        int left = totalUniquePaths(i, j - 1, mat, dp);

        // Store result in DP table and return (modulo MOD)
        return dp[i][j] = (up + left) % MOD;
    }

    int mazeObstacles(int n, int m, vector<vector<int>> &mat)
    {
        // Initialize DP table with -1 (uncomputed)
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return totalUniquePaths(n - 1, m - 1, mat, dp);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    int mazeObstacles(int n, int m, vector<vector<int>> &mat)
    {
        // DP table: dp[i][j] = number of unique paths to cell (i, j)
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If cell is an obstacle, no path to this cell
                if (mat[i][j] == -1)
                {
                    dp[i][j] = 0;
                }
                else if (i == 0 && j == 0) // Starting cell
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int up = 0, left = 0;

                    // If not first row, add paths from above
                    if (i > 0)
                    {
                        up = dp[i - 1][j];
                    }

                    // If not first column, add paths from left
                    if (j > 0)
                    {
                        left = dp[i][j - 1];
                    }

                    // Total paths to this cell (modulo MOD)
                    dp[i][j] = (up + left) % MOD;
                }
            }
        }

        // Return number of paths to bottom-right cell
        return dp[n - 1][m - 1];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution4
{
public:
    int mazeObstacles(int n, int m, vector<vector<int>> &mat)
    {
        // Only keep previous row to save space
        vector<int> prevDP(m, 0);

        for (int i = 0; i < n; i++)
        {
            vector<int> tempDP(m, 0);

            for (int j = 0; j < m; j++)
            {
                // If cell is an obstacle, no path to this cell
                if (mat[i][j] == -1)
                {
                    tempDP[j] = 0;
                }
                // Starting cell
                else if (i == 0 && j == 0)
                {
                    tempDP[j] = 1;
                }
                else
                {
                    int up = 0, left = 0;

                    // If not first row, add paths from above
                    if (i > 0)
                    {
                        up = prevDP[j];
                    }

                    // If not first column, add paths from left
                    if (j > 0)
                    {
                        left = tempDP[j - 1];
                    }

                    // Total paths to this cell (modulo MOD)
                    tempDP[j] = (up + left) % MOD;
                }
            }

            // Move to next row
            prevDP = tempDP;
        }

        // Return number of paths to bottom-right cell
        return prevDP[m - 1];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    int n1 = 2;
    int m1 = 2;
    vector<vector<int>> mat1 = {{0, 0}, {0, 0}}; // OUTPUT: 2

    int n2 = 2;
    int m2 = 2;
    vector<vector<int>> mat2 = {{0, -1}, {-1, 0}}; // OUTPUT: 0

    int n3 = 3;
    int m3 = 3;
    vector<vector<int>> mat3 = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}}; // OUTPUT: 2

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.mazeObstacles(n1, m1, mat1) << endl;
    cout << sol1.mazeObstacles(n2, m2, mat2) << endl;
    cout << sol1.mazeObstacles(n3, m3, mat3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.mazeObstacles(n1, m1, mat1) << endl;
    cout << sol2.mazeObstacles(n2, m2, mat2) << endl;
    cout << sol2.mazeObstacles(n3, m3, mat3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.mazeObstacles(n1, m1, mat1) << endl;
    cout << sol3.mazeObstacles(n2, m2, mat2) << endl;
    cout << sol3.mazeObstacles(n3, m3, mat3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.mazeObstacles(n1, m1, mat1) << endl;
    cout << sol4.mazeObstacles(n2, m2, mat2) << endl;
    cout << sol4.mazeObstacles(n3, m3, mat3) << endl;

    return 0;
}

/*
    Sample Input 1 :
    2 2
    0 0
    0 0


    Sample Output 1 :
        2
    Explanation :
    For this case, there are two possible paths to reach (2, 2) from (1, 1) :
    (1, 1) -> (1, 2) -> (2, 2)
    (1, 1) -> (2, 1) -> (2, 2)



    Sample Input 2 :
        2 2
        0 -1
        -1  0
    Sample Output 2 :
    0


    Sample Input 3 :
        3 3
        0 0 0
        0 -1 0
        0 0 0
    Sample Output 3 :
        2
    Explanation For Sample Output 1 :
            For this case, there are two ways to reach the bottom left corner -
                (1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
                (1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

*/