/**
*  @file: 78_Subsets.cpp
*  @author: Avinash Yadav
*  @date: 09-06-2025
*  @link: https://leetcode.com/problems/subsets/description/
*  @brief: Given an integer array nums of unique elements, return all possible subsets (the power set).
            The solution set must not contain duplicate subsets. Return the solution in any order.

            Example 1:
                Input: nums = [1,2,3]
                Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

            Example 2:
                Input: nums = [0]
                Output: [[],[0]]
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