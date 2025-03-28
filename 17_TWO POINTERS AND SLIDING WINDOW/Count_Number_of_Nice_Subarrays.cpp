/**
 *  @file: Count_Number_of_Nice_Subarrays.cpp
 *  @author: Avinash Yadav
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    // Helper function: Counts subarrays with at most 'k' odd numbers
    int countSubarraysWithAtMostKOdds(vector<int> &nums, int k)
    {
        // Sliding window pointers
        int left = 0, right = 0;

        // Tracks number of odd elements in the window
        int oddCount = 0;

        // Stores count of valid subarrays
        int totalSubarrays = 0;

        while (right < nums.size())
        {
            // Add current element to sum (check if it's odd)
            oddCount += (nums[right] % 2);

            // Shrink window if there are more than 'k' odd numbers
            while (oddCount > k)
            {
                // Remove leftmost element
                oddCount -= (nums[left] % 2);

                left++;
            }

            // Count valid subarrays ending at 'right'
            totalSubarrays += (right - left + 1);

            right++;
        }
        return totalSubarrays;
    }

    // Function to Counts subarrays with exactly 'k' odd numbers
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return countSubarraysWithAtMostKOdds(nums, k) -
               countSubarraysWithAtMostKOdds(nums, k - 1);
    }
};
