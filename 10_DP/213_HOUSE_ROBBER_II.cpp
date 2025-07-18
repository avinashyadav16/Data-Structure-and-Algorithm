/**
*  @file: 213_HOUSE_ROBBER_II.cpp
*  @author: Avinash Yadav
*  @date: 13-06-2025
*  @link: https://leetcode.com/problems/house-robber-ii/description/
*  @brief: You are a professional robber planning to rob houses along a street.
            Each house has a certain amount of money stashed.
            All houses at this place are arranged in a circle.
            That means the first house is the neighbor of the last one.
            Meanwhile, adjacent houses have a security system connected,
            and it will automatically contact the police if two adjacent houses were broken into on the same night.
            Given an integer array nums representing the amount of money of each house,
            return the maximum amount of money you can rob tonight without alerting the police.

            Example 1:
                Input: nums = [2,3,2]
                Output: 3
                Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

            Example 2:
                Input: nums = [1,2,3,1]
                Output: 4
                Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
                Total amount you can rob = 1 + 3 = 4.

            Example 3:
                Input: nums = [1,2,3]
                Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

// SPACE OPTIMIZED APPRAOCH:
class Solution4
{
public:
    // Function to compute max profit for linear houses (not circular)
    int maxNonAdjProfit(vector<int> &nums)
    {
        int n = nums.size();

        // prev1: max profit till previous house
        // prev2: max profit till house before previous
        int prev1 = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            // Rob current house
            int take = nums[i];
            if (i > 1)
            {
                // Add profit from non-adjacent house
                take += prev2;
            }

            // Skip current house
            int notTake = prev1;

            // Choose max of robbing or skipping
            int curri = max(take, notTake);

            // Update for next iteration
            prev2 = prev1;
            prev1 = curri;
        }

        // Maximum profit for linear houses
        return prev1;
    }

    // Main function to handle circular arrangement
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        // If only one house, rob it
        if (n == 1)
        {
            return nums[0];
        }

        // Case 1:
        // Exclude first house, consider houses [1...n-1]
        vector<int> vec1;
        for (int i = 1; i < n; i++)
        {
            vec1.push_back(nums[i]);
        }

        // Case 2:
        // Exclude last house, consider houses [0...n-2]
        vector<int> vec2;
        for (int i = 0; i < n - 1; i++)
        {
            vec2.push_back(nums[i]);
        }

        // Return the maximum profit from the two cases
        return max(maxNonAdjProfit(vec1), maxNonAdjProfit(vec2));
    }
};

int main()
{
    vector<int> nums1 = {2, 3, 2};    // 3
    vector<int> nums2 = {1, 2, 3, 1}; // 4
    vector<int> nums3 = {1, 2, 3};    // 3

    Solution4 sol4;
    cout << "SPACE OPTIMIZED APPRAOCH:" << endl;
    cout << sol4.rob(nums1) << endl;
    cout << sol4.rob(nums2) << endl;
    cout << sol4.rob(nums3) << endl;

    return 0;
}