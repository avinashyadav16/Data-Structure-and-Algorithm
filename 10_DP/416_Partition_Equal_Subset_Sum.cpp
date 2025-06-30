/**
*  @file: 416_Partition_Equal_Subset_Sum.cpp
*  @author: Avinash Yadav
*  @date: 25-06-2025
*  @link: https://leetcode.com/problems/partition-equal-subset-sum/description/
*  @brief: Given an integer array nums,
            return true if you can partition the array into two subsets
            such that the sum of the elements in both subsets is equal or false otherwise.

            Example 1:
                Input: nums = [1,5,11,5]
                Output: true
                Explanation: The array can be partitioned as [1, 5, 5] and [11].

            Example 2:
                Input: nums = [1,2,3,5]
                Output: false
                Explanation: The array cannot be partitioned into equal sum subsets.
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    bool recursionIsSubsetSum(int idx, vector<int> &nums, int sum)
    {
        if (sum == 0)
        {
            return true;
        }

        if (idx == 0)
        {
            return nums[0] == sum;
        }

        bool notTake = recursionIsSubsetSum(idx - 1, nums, sum);

        bool take = false;
        if (nums[idx] <= sum)
        {
            take = recursionIsSubsetSum(idx - 1, nums, sum - nums[idx]);
        }

        return notTake || take;
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum & 1)
        {
            return false;
        }

        return recursionIsSubsetSum(n - 1, nums, totalSum / 2);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    bool memoIsSubsetSum(int idx, vector<vector<int>> &dp, vector<int> &nums, int sum)
    {
        if (sum == 0)
        {
            return true;
        }

        if (idx == 0)
        {
            return nums[0] == sum;
        }

        if (dp[idx][sum] != -1)
        {
            return dp[idx][sum];
        }

        bool notTake = memoIsSubsetSum(idx - 1, dp, nums, sum);

        bool take = false;
        if (nums[idx] <= sum)
        {
            take = memoIsSubsetSum(idx - 1, dp, nums, sum - nums[idx]);
        }

        return dp[idx][sum] = notTake || take;
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum & 1)
        {
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

        return memoIsSubsetSum(n - 1, dp, nums, totalSum / 2);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum & 1)
        {
            return false;
        }

        int sum = totalSum / 2;

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int idx = 0; idx < n; idx++)
        {
            dp[idx][0] = true;
        }

        if (nums[0] <= sum)
        {
            dp[0][nums[0]] = true;
        }

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool notTake = dp[idx - 1][target];
                bool take = false;

                if (nums[idx] <= target)
                {
                    take = dp[idx - 1][target - nums[idx]];
                }

                dp[idx][target] = notTake || take;
            }
        }
        return dp[n - 1][sum];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution4
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum & 1)
        {
            return false;
        }

        int sum = totalSum / 2;

        vector<bool> prevDP(sum + 1, false);
        vector<bool> tempDP(sum + 1, false);

        prevDP[0] = tempDP[0] = true;

        if (nums[0] <= sum)
        {
            prevDP[nums[0]] = true;
        }

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool notTake = prevDP[target];

                bool take = false;
                if (nums[idx] <= target)
                {
                    take = prevDP[target - nums[idx]];
                }

                tempDP[target] = notTake || take;
            }

            prevDP = tempDP;
        }

        return prevDP[sum];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<int> nums1 = {1, 5, 11, 5}; // OUTPUT: true

    vector<int> nums2 = {1, 2, 3, 5}; // OUTPUT: false

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << boolalpha << sol1.canPartition(nums1) << endl;
    cout << boolalpha << sol1.canPartition(nums2) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << boolalpha << sol2.canPartition(nums1) << endl;
    cout << boolalpha << sol2.canPartition(nums2) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << boolalpha << sol3.canPartition(nums1) << endl;
    cout << boolalpha << sol3.canPartition(nums2) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << boolalpha << sol4.canPartition(nums1) << endl;
    cout << boolalpha << sol4.canPartition(nums2) << endl;

    return 0;
}