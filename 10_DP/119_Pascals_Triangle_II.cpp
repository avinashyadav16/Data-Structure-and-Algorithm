/**
 * @file: 119_Pascals_Triangle_II.cpp
 * @author: Avinash Yadav
 * @date: 21-01-2026
 * @link: https://leetcode.com/problems/pascals-triangle-ii/description
 * @brief: Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
 *          In Pascal's triangle, each number is the sum of the two numbers directly above it.
            Example 1:
                Input: rowIndex = 3
                Output: [1,3,3,1]
 */

#include <bits/stdc++.h>
using namespace std;

// METHOD - 01
// Time: O(rowIndex²)
// Space: O(rowIndex²)

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> res;

        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> temp;
            temp.push_back(1);

            for (int j = 1; j < i; j++)
            {
                int num = res[i - 1][j - 1] + res[i - 1][j];
                temp.push_back(num);
            }

            if (i > 0)
            {
                temp.push_back(1);
            }

            res.push_back(temp);
        }

        return res[rowIndex];
    }
};

// METHOD - 02
// O(rowIndex)
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;

        for (int i = 1; i <= rowIndex; i++)
        {
            for (int j = i; j > 0; j--)
            {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};
