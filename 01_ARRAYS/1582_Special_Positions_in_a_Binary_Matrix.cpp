/**
 * @file: 1582_Special_Positions_in_a_Binary_Matrix.cpp
 * @author: Avinash Yadav
 * @date: 04-03-2026
 * @link: https://leetcode.com/problems/special-positions-in-a-binary-matrix
 * @brief:  Given an m x n binary matrix mat, return the number of special positions in mat.
            A position (i, j) is called special if
                - mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

            Example 1:
                Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
                Output: 1
                Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.

            Example 2:
                Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
                Output: 3
                Explanation: (0, 0), (1, 1) and (2, 2) are special positions.

            Constraints:
                m == mat.length
                n == mat[i].length
                1 <= m, n <= 100
                mat[i][j] is either 0 or 1.
 */

#include <bits/stdc++.h>
using namespace std;

/*
class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1 &&
                    row[i] == 1 &&
                    col[j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
*/

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int numRows = mat.size();
        int numCols = mat[0].size();

        int specialCnt = 0;

        for (int rowIdx = 0; rowIdx < numRows; rowIdx++)
        {
            for (int colIdx = 0; colIdx < numCols; colIdx++)
            {
                if (mat[rowIdx][colIdx] == 0)
                {
                    continue;
                }

                bool isSpecialPosition = true;

                // Checking column
                for (int checkRow = 0; checkRow < numRows; checkRow++)
                {
                    if (checkRow != rowIdx && mat[checkRow][colIdx] == 1)
                    {
                        isSpecialPosition = false;
                        break;
                    }
                }

                // Checking row
                for (int checkCol = 0; checkCol < numCols; checkCol++)
                {
                    if (checkCol != colIdx && mat[rowIdx][checkCol] == 1)
                    {
                        isSpecialPosition = false;
                        break;
                    }
                }

                if (isSpecialPosition)
                {
                    specialCnt++;
                }
            }
        }

        return specialCnt;
    }
};

int main()
{

    vector<vector<int>> mat1 = {
        {1, 0, 0},
        {0, 0, 1},
        {1, 0, 0}};

    vector<vector<int>> mat2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};

    vector<vector<int>> mat3 = {
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0}};

    Solution sol;
    cout << sol.numSpecial(mat1) << endl; // OUTPUT: 1
    cout << sol.numSpecial(mat2) << endl; // OUTPUT: 3
    cout << sol.numSpecial(mat3) << endl; // OUTPUT: 2

    return 0;
}
