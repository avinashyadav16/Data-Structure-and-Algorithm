/**
 *  @file: Subarrays_with_K_Different_Integers.cpp
 *  @author: Avinash Yadav
 *  @brief: This program finds the number of subarrays containing exactly K distinct integers using the sliding window technique.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Finds the number of subarrays with at most 'k' distinct integers.
     *
     * @param nums Input array of integers.
     * @param k Maximum number of distinct integers allowed in a subarray.
     * @return The count of subarrays with at most 'k' distinct elements.
     */
    int subarraysWithAtMostKDistinct(vector<int> &nums, int k)
    {
        // Size of the input array
        int n = nums.size();

        // Left pointer of the sliding window
        int left = 0;

        // Right pointer of the sliding window
        int right = 0;

        // Stores the count of valid subarrays
        int cnt = 0;

        // Hash map to store the frequency of elements in the current window
        unordered_map<int, int> freqMap;

        // Expand the window by moving the right pointer
        while (right < n)
        {
            // Increase the count of the current number
            freqMap[nums[right]]++; 

            // If the window contains more than 'k' distinct integers, shrink it from the left
            while (freqMap.size() > k)
            {
                // Reduce the frequency of the leftmost element
                freqMap[nums[left]]--; 

                if (freqMap[nums[left]] == 0)
                {
                    // Remove the element if its frequency becomes zero
                    freqMap.erase(nums[left]); 
                }

                // Move the left pointer to shrink the window
                left++; 
            }

            // Add the number of valid subarrays ending at 'right'
            cnt += (right - left + 1);

            // Expand the window
            right++; 
        }

        return cnt;
    }

    /**
     * @brief Finds the number of subarrays that contain exactly 'k' distinct integers.
     *
     * @param nums Input array of integers.
     * @param k Exact number of distinct integers required in the subarray.
     * @return The count of subarrays with exactly 'k' distinct elements.
     */
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // The number of subarrays with exactly 'k' distinct elements
        // is found by subtracting subarrays with at most (k - 1) distinct elements
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    cout << "Number of subarrays with exactly " << k << " distinct integers: " << solution.subarraysWithKDistinct(nums, k) << endl;

    return 0;
}
