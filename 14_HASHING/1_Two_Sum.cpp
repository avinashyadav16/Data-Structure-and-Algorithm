/**
*  @file: 1_Two_Sum.cpp
*  @author: Avinash Yadav
*  @date: 16-08-2025
*  @link: https://leetcode.com/problems/two-sum/description/
*  @brief: Given an array of integers nums and an integer target,
            return indices of the two numbers such that they add up to target.
            You may assume that each input would have exactly one solution,
             and you may not use the same element twice.
            You can return the answer in any order.

            Example 1:
                Input: nums = [2,7,11,15], target = 9
                Output: [0,1]
                Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

            Example 2:
                Input: nums = [3,2,4], target = 6
                Output: [1,2]

            Example 3:
                Input: nums = [3,3], target = 6
                Output: [0,1]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        // Hash map to store value -> index mapping
        unordered_map<int, int> mpp;

        // Iterate through the array
        for (int i = 0; i < n; i++)
        {
            // Check if the complement (target - nums[i]) exists in the map
            // If it exists, we found the pair whose sum is equal to target
            if (mpp.find(target - nums[i]) != mpp.end())
            {
                // Return the indices of the two numbers
                return {mpp[target - nums[i]], i};
            }

            // Store the current number and its index in the map
            // This will help to find its complement in future iterations
            mpp[nums[i]] = i;
        }

        // If no such pair is found, return an empty vector
        return {};
    }
};
