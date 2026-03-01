/**
 * @file: 73_Set_Matrix_Zeroes.cpp
 * @author: Avinash Yadav
 * @date: 21-01-2026
 * @link: https://leetcode.com/problems/set-matrix-zeroes/description/
 * @brief: Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
            You must do it in place.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // space used = O(m + n)
    void setZeroes_1(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, -1);
        vector<int> col(n, -1);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] == 0 || col[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void setZeroes_2(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        // check first column
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                firstCol = true;
                break;
            }
        }

        // check first row
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                firstRow = true;
                break;
            }
        }

        // use first row & column as markers
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // set zeroes using markers
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // handle first row
        if (firstRow)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // handle first column
        if (firstCol)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    cout << "Before Setting Zeroes: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    sol.setZeroes_1(matrix);

    cout << "\nAfter Setting Zeroes: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}