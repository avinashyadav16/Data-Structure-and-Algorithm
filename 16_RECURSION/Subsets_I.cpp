/**
 *  @file: Subsets_I.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/subsets/description/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findSubsets(int idx, int n, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (idx >= n)
        {
            ans.push_back(ds);

            return;
        }

        ds.push_back(nums[idx]);
        findSubsets(idx + 1, n, nums, ans, ds);
        ds.pop_back();

        findSubsets(idx + 1, n, nums, ans, ds);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> ds;

        findSubsets(0, n, nums, ans, ds);

        return ans;
    }
};
