/**
 * @file: 118_Pascals_Triangle.cpp
 * @author: Avinash Yadav
 * @date: 21-01-2026
 * @link: https://leetcode.com/problems/pascals-triangle/description/
 * @brief: Given an integer numRows, return the first numRows of Pascal's triangle.
 *          In Pascal's triangle, each number is the sum of the two numbers directly above it.
 *          Example 1:
                Input: numRows = 5
                Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++)
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

        return res;
    }
};

int main()
{
    int numRows = 5;

    Solution sol;
    vector<vector<int>> res = sol.generate(numRows);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];

            if (j < res[i].size() - 1)
            {
                cout << ",";
            }
        }

        if (i < res.size() - 1)
        {
            cout << "],";
        }
        else
        {
            cout << "]";
        }
    }
    cout << "]";

    return 0;
}