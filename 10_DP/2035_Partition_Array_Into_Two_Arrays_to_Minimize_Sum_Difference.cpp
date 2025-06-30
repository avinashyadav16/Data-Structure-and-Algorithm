// TODO

/**
*  @file: 2035_Partition_Array_Into_Two_Arrays_to_Minimize_Sum_Difference.cpp
*  @author: Avinash Yadav
*  @date: 26-06-2025
*  @link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/
*  @brief: You are given an integer array nums of 2 * n integers.
            You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays.
            To partition nums, put each element of nums into one of the two arrays.

            Return the minimum possible absolute difference.

            Example 1:
                Input: nums = [3,9,7,3]
                Output: 2
                Explanation: One optimal partition is: [3,9] and [7,3].
                The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.

            Example 2:
                Input: nums = [-36,36]
                Output: 72
                Explanation: One optimal partition is: [-36] and [36].
                The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72

            Example 3:
                Input: nums = [2,-1,0,4,-2,-9]
                Output: 0
                Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
                The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

        for (int idx = 0; idx < n; idx++)
        {
            dp[idx][0] = true;
        }

        if (nums[0] >= 0 && nums[0] <= totalSum)
        {
            dp[0][nums[0]] = true;
        }

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= totalSum; target++)
            {
                bool notTake = dp[idx - 1][target];

                bool take = false;
                if (nums[idx] >= 0 && nums[idx] <= target)
                {
                    take = dp[idx - 1][target - nums[idx]];
                }

                dp[idx][target] = notTake || take;
            }
        }

        int minDiff = INT_MAX;

        for (int i = 0; i <= totalSum / 2; i++)
        {
            if (dp[n - 1][i] == true)
            {
                int sum1 = i;
                int sum2 = totalSum - i;

                minDiff = min(minDiff, abs(sum2 - sum1));
            }
        }

        return minDiff;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<int> nums1 = {3, 9, 7, 3}; // OUTPUT: 2

    vector<int> nums2 = {2, -1, 0, 4, -2, -9}; // OUTPUT: 0

    Solution1 sol1;
    cout << sol1.minimumDifference(nums1) << endl;
    cout << sol1.minimumDifference(nums2) << endl;

    return 0;
}