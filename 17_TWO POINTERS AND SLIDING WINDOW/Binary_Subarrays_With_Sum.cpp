/**
 *  @file: Binary_Subarrays_With_Sum.cpp
 *  @author: Avinash Yadav
 *  @brief: Implementation to count binary subarrays with a given sum.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    // Function to count subarrays with sum <= targetSum
    int numSubarraysWithSumLessThanEquals(vector<int> &nums, int targetSum)
    {
        // If the target sum is negative, no valid subarray exists
        if (targetSum < 0)
        {
            return 0;
        }

        // Left pointer of the sliding window
        int left = 0;

        // Right pointer of the sliding window
        int right = 0;

        // Stores the sum of the current subarray
        int currentSum = 0;

        // Stores the total number of valid subarrays
        int count = 0;

        // Expand the right pointer to explore all subarrays
        while (right < nums.size())
        {
            // Include the rightmost element into the sum
            currentSum += nums[right];

            // If currentSum exceeds targetSum, shrink the window from the left
            while (currentSum > targetSum)
            {
                // Remove the leftmost element from sum
                currentSum -= nums[left];

                // Move the left pointer forward
                left += 1;
            }

            // The number of subarrays ending at 'right' and having sum ≤ targetSum
            // is given by the window size: (right - left + 1)
            count += (right - left + 1);

            // Move the right pointer to extend the window
            right += 1;
        }

        // Return the total count of subarrays
        return count;
    }

    // Function to count the number of subarrays with sum exactly equal to 'goal'
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        // The number of subarrays with sum exactly 'goal' is:
        // count of subarrays with sum ≤ goal  - count of subarrays with sum ≤ goal-1
        return (numSubarraysWithSumLessThanEquals(nums, goal) -
                numSubarraysWithSumLessThanEquals(nums, goal - 1));
    }
};