/**
*  @file: 216_Combination_Sum_III.cpp
*  @author: Avinash Yadav
*  @date: 09-06-2025
*  @link: https://leetcode.com/problems/combination-sum-iii/description/
*  @brief: Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
            Only numbers 1 through 9 are used.
            Each number is used at most once.
            Return a list of all possible valid combinations.
            The list must not contain the same combination twice, and the combinations may be returned in any order.

            Example 1:

            Input: k = 3, n = 7
            Output: [[1,2,4]]
            Explanation:
                1 + 2 + 4 = 7
                There are no other valid combinations.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findComboSum(int idx, int sum, int k, int n, vector<vector<int>> &res, vector<int> &ds)
    {
        if (ds.size() == k)
        {
            if (sum == n)
            {
                res.push_back(ds);
            }

            return;
        }
        if (sum > n || idx > 9)
        {
            return;
        }

        // pick the current number
        ds.push_back(idx);
        findComboSum(idx + 1, sum + idx, k, n, res, ds);
        ds.pop_back();

        // do not pick the current number
        findComboSum(idx + 1, sum, k, n, res, ds);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> ds;

        findComboSum(1, 0, k, n, res, ds);

        return res;
    }
};

int main()
{
    int k;
    cin >> k;

    int n;
    cin >> n;

    Solution sol;

    vector<vector<int>> result = sol.combinationSum3(k, n);

    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";

        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
            {
                cout << ",";
            }
        }

        cout << "]";

        if (i < result.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";

    return 0;
}