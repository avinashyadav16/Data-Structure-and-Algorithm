/**
*  @file: 3355_Zero_Array_Transformation_I.cpp
*  @author: Avinash Yadav
*  @date: 03-06-2025
*  @link: https://leetcode.com/problems/zero-array-transformation-i/description
*  @brief: You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].
            For each queries[i]:
                Select a subset of indices within the range [li, ri] in nums.
                Decrement the values at the selected indices by 1.

            A Zero Array is an array where all elements are equal to 0.
            Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially,
            otherwise return false.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();

        // one extra space for difference array
        vector<int> diff(n + 1, 0);

        // Applying queries using the difference array
        for (const auto &q : queries)
        {
            int L = q[0], R = q[1];

            diff[L] += 1;

            if (R + 1 < n)
            {
                diff[R + 1] -= 1;
            }
        }

        int totalDec = 0;
        for (int i = 0; i < n; i++)
        {
            totalDec += diff[i];

            if (totalDec < nums[i])
                return false;
        }

        return true;
    }
};
