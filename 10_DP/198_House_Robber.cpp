/**
*  @file: 198_House_Robber.cpp
*  @author: Avinash Yadav
*  @date: 13-06-2025
*  @link: https://leetcode.com/problems/house-robber/description/
*  @brief: You are a professional robber planning to rob houses along a street.
            Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that
            adjacent houses have security systems connected and
            it will automatically contact the police if two adjacent houses were broken into on the same night.
            Given an integer array nums representing the amount of money of each house,
            return the maximum amount of money you can rob tonight without alerting the police.

            Example 1:
                Input: nums = [1,2,3,1]
                Output: 4
                Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
                Total amount you can rob = 1 + 3 = 4.

            Example 2:
                Input: nums = [2,7,9,3,1]
                Output: 12
                Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
                Total amount you can rob = 2 + 9 + 1 = 12.
*/

#include <bits/stdc++.h>
using namespace std;

// RECURSION APPROACH:
class Solution1
{
public:
    // idx: current house index
    int totalProfit(int idx, vector<int> &nums)
    {
        // Base case:
        // If idx is 0, only one house to rob
        if (idx == 0)
        {
            return nums[0];
        }

        // Base case:
        // If idx is negative, no houses left to rob
        if (idx < 0)
        {
            return 0;
        }

        // Option 1: Rob the current house and skip the previous one
        int pick = nums[idx] + totalProfit(idx - 2, nums);

        // Option 2: Skip the current house
        int notPick = 0 + totalProfit(idx - 1, nums);

        // Return the maximum of both options
        return max(pick, notPick);
    }

    // Main function to be called with the input vector
    int rob(vector<int> &nums)
    {
        // Start recursion from the last house
        return totalProfit(nums.size() - 1, nums);
    }
};

// MEMOIZATION APPROACH:
class Solution2
{
public:
    // Compute the maximum profit up to index 'idx'
    // Uses memoization to store results in 'dp'
    int totalProfit(int idx, vector<int> &nums, vector<int> &dp)
    {
        // Base case: Only one house to rob
        if (idx == 0)
        {
            return dp[idx] = nums[0];
        }

        // Base case: No houses left to rob
        if (idx < 0)
        {
            return 0;
        }

        // If already computed, return the stored result
        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        // Option 1: Rob current house and skip the previous one
        int pick = nums[idx] + totalProfit(idx - 2, nums, dp);

        // Option 2: Skip current house
        int notPick = totalProfit(idx - 1, nums, dp);

        // Store and return the maximum of both options
        return dp[idx] = max(pick, notPick);
    }

    // Main function to start the computation
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // Initialize dp array with -1 to indicate
        // uncomputed subproblems
        vector<int> dp(n, -1);

        // Compute the result for the last house
        return totalProfit(n - 1, nums, dp);
    }
};

// TABULATION APPRAOCH:
class Solution3
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        // dp[i] will store the maximum profit up to house i
        vector<int> dp(n, -1);

        // Base case: Only one house to rob
        dp[0] = nums[0];

        // Iterate through each house starting from the second one
        for (int i = 1; i < n; i++)
        {
            // Option 1:
            // Rob the current house and add profit from i-2 (if exists)
            int take = nums[i];
            if (i > 1)
            {
                take += dp[i - 2];
            }

            // Option 2: Skip the current house, take profit up to i-1
            int notTake = 0 + dp[i - 1];

            // Store the maximum of both options in dp[i]
            dp[i] = max(take, notTake);
        }

        // The answer is the maximum profit up to the last house
        return dp[n - 1];
    }
};

// SPACE OPTIMIZED APPRAOCH:
class Solution4
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        // prev1: max profit up to previous house (i-1)
        int prev1 = nums[0];

        // prev2: max profit up to house before previous (i-2)
        int prev2 = 0;

        // Iterate through each house starting from the second one
        for (int i = 1; i < n; i++)
        {
            // Option 1:
            // Rob current house and add profit from i-2 (if exists)
            int take = nums[i];
            if (i > 1)
            {
                take += prev2;
            }

            // Option 2:
            // Skip current house, take profit up to i-1
            int notTake = prev1;

            // Current max profit is the best of both options
            int curri = max(take, notTake);

            // Update prev2 and prev1 for next iteration
            prev2 = prev1;
            prev1 = curri;
        }

        // prev1 holds the answer:
        // max profit up to last house
        return prev1;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 1};    // 4
    vector<int> nums2 = {2, 7, 9, 3, 1}; // 12

    Solution1 sol1;
    cout << "RECURSION APPROACH:" << endl;
    cout << boolalpha << sol1.rob(nums1) << endl;
    cout << boolalpha << sol1.rob(nums2) << endl;

    Solution2 sol2;
    cout << "MEMOIZATION APPROACH:" << endl;
    cout << boolalpha << sol2.rob(nums1) << endl;
    cout << boolalpha << sol2.rob(nums2) << endl;

    Solution3 sol3;
    cout << "TABULATION APPROACH:" << endl;
    cout << boolalpha << sol3.rob(nums1) << endl;
    cout << boolalpha << sol3.rob(nums2) << endl;

    Solution4 sol4;
    cout << "SPACE OPTIMIZED APPRAOCH:" << endl;
    cout << boolalpha << sol4.rob(nums1) << endl;
    cout << boolalpha << sol4.rob(nums2) << endl;

    return 0;
}