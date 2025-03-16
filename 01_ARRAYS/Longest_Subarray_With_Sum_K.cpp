/**
 *  @file: Longest_Subarray_With_Sum_K.cpp
 *  @brief: This file contains the implementation of the solution to find the longest subarray with sum equal to k.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution1
{
public:
    /**
     * @brief Finds the length of the longest subarray with sum equal to k.
     *
     * @param arr The input array.
     * @param k The target sum.
     * @return The length of the longest subarray with sum equal to k.
     */
    int longestSubarray(vector<int> &arr, int k)
    {
        // Size of the input array.
        int n = arr.size();

        // Map to store the prefix sum and its corresponding index.
        map<int, int> prefixSumMap;

        // Store the current prefix sum.
        int currentSum = 0;

        // Store the maximum length of subarray with sum k.
        int maxLength = 0;

        for (int i = 0; i < n; i++)
        {
            // Update the current prefix sum.
            currentSum += arr[i];

            // If the current prefix sum is equal to k, update maxLength.
            if (currentSum == k)
            {
                maxLength = max(maxLength, i + 1);
            }

            // Calculate the required prefix sum to get the subarray with sum k.
            int requiredSum = currentSum - k;

            // Check if the required prefix sum exists in the map.
            if (prefixSumMap.find(requiredSum) != prefixSumMap.end())
            {
                // Update maxLength if a valid subarray is found.
                maxLength = max(maxLength, i - prefixSumMap[requiredSum]);
            }

            // Store the current prefix sum and its index in the map if it doesn't already exist.
            if (prefixSumMap.find(currentSum) == prefixSumMap.end())
            {
                prefixSumMap[currentSum] = i;
            }
        }

        // Return the maximum length of subarray with sum k.
        return maxLength;
    }
};

class Solution2
{
public:
    // WHEN THE ARRAY HAS ONLY POSITIVE INTEGERS AND ZEROES:
    int getLongestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Left pointer and Right pointer for the sliding window.
        int left = 0, right = 0;

        // Maximum length of subarray with sum k.
        int maxLen = 0;

        // Initialize the current sum with the first element.
        int currentSum = nums[0];

        while (right < n)
        {
            // If the current sum exceeds k,
            // move the left pointer to the right to reduce the sum.
            while (left <= right && currentSum > k)
            {
                currentSum -= nums[left];
                left++;
            }

            // If the current sum is equal to k,
            // update the maximum length.
            if (currentSum == k)
            {
                maxLen = max(maxLen, right - left + 1);
            }

            // Move the right pointer to the right to expand the window.
            right++;

            // Update the current sum with the new element added to the window.
            if (right < n)
            {
                currentSum += nums[right];
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution1 sol;

    vector<int> arr = {1, -1, 5, -2, 3};
    int k = 3;

    int result = sol.longestSubarray(arr, k);

    cout << "Length of the longest subarray with sum " << k << ": " << result << endl;

    return 0;
}