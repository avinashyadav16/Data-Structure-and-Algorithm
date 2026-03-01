/**
*  @file: Largest_subarray_with_0_sum.cpp
*  @author: Avinash Yadav
*  @date: 17-08-2025
*  @link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*  @brief: Given an array arr[] containing both positive and negative integers,
            the task is to find the length of the longest subarray with a sum equals to 0.
            Note: A subarray is a contiguous part of an array,
            formed by selecting one or more consecutive elements while maintaining their original order.

            Examples:
                Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
                Output: 5
                Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].

                Input: arr[] = [2, 10, 4]
                Output: 0
                Explanation: There is no subarray with a sum of 0.

                Input: arr[] = [1, 0, -4, 3, 1, 0]
                Output: 5
                Explanation: The longest subarray with sum equals to 0 is [0, -4, 3, 1, 0]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        int n = arr.size();

        // Hash map to store
        // first occurrence index of each prefix sum
        unordered_map<int, int> mpp;

        // Store the prefix sum
        int sum = 0;

        // Store the maximum length found
        int maxLen = 0;

        // Traverse the array
        for (int i = 0; i < n; i++)
        {
            // Update the prefix sum
            sum += arr[i];

            // If the prefix sum is zero,
            // the subarray from index 0 to i has sum 0
            if (sum == 0)
            {
                maxLen = i + 1;
            }
            else
            {
                // If this prefix sum has been seen before,
                // then the subarray between
                // previous index+1 and current index has sum 0
                if (mpp.find(sum) != mpp.end())
                {
                    // Update maxLen if we found a longer subarray
                    maxLen = max(maxLen, i - mpp[sum]);
                }
                else
                {
                    // Store the first occurrence of this prefix sum
                    mpp[sum] = i;
                }
            }
        }

        return maxLen;
    }
};
