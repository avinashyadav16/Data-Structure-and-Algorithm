/**
*  @file: 494_Target_Sum.cpp
*  @author: Avinash Yadav
*  @date: 29-06-2025
*  @link: https://leetcode.com/problems/target-sum/description/
*  @brief: You are given an integer array nums and an integer target.
            You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and
            then concatenate all the integers.

            For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and
            concatenate them to build the expression "+2-1".
            Return the number of different expressions that you can build, which evaluates to target.

            Example 1:
                Input: nums = [1,1,1,1,1], target = 3
                Output: 5
                Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
                -1 + 1 + 1 + 1 + 1 = 3
                +1 - 1 + 1 + 1 + 1 = 3
                +1 + 1 - 1 + 1 + 1 = 3
                +1 + 1 + 1 - 1 + 1 = 3
                +1 + 1 + 1 + 1 - 1 = 3

            Example 2:
                Input: nums = [1], target = 1
                Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {
        int n = arr.size();

        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if ((totalSum - d) < 0 || (totalSum - d) & 1)
        {
            return 0;
        }

        int target = (totalSum - d) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        if (arr[0] == 0)
        {
            dp[0][0] = 2;
        }
        else
        {
            dp[0][0] = 1;
        }

        if (arr[0] != 0 && arr[0] <= target)
        {
            dp[0][arr[0]] = 1;
        }

        for (int idx = 1; idx < n; idx++)
        {
            for (int currSum = 0; currSum <= target; currSum++)
            {
                int notTake = dp[idx - 1][currSum];

                int take = 0;
                if (arr[idx] <= currSum)
                {
                    take = dp[idx - 1][currSum - arr[idx]];
                }

                dp[idx][currSum] = take + notTake;
            }
        }

        return dp[n - 1][target];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return countPartitions(nums, target);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3; // OUTPUT: 5

    vector<int> nums2 = {1};
    int target2 = 1; // OUTPUT: 1

    Solution sol;
    cout << sol.findTargetSumWays(nums1, target1) << endl;
    cout << sol.findTargetSumWays(nums2, target2) << endl;

    return 0;
}