/**
*  @file: 128_Longest_Consecutive_Sequence.cpp
*  @author: Avinash Yadav
*  @date: 16-08-2025
*  @link: https://leetcode.com/problems/longest-consecutive-sequence/description
*  @brief: Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
            You must write an algorithm that runs in O(n) time.

            Example 1:
                Input: nums = [100,4,200,1,3,2]
                Output: 4
                Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

            Example 2:
                Input: nums = [0,3,7,2,5,8,4,6,0,1]
                Output: 9

            Example 3:
                Input: nums = [1,0,1,2]
                Output: 3

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();

        // Use a set to store unique elements
        // for O(1) lookup and to remove duplicates
        set<int> hashSet;

        // Insert all elements from input array into set
        for (auto &num : nums)
        {
            hashSet.insert(num);
        }

        // Keep track of the longest sequence found
        int longestStreak = 0;

        // Iterate through each unique number in the set
        for (int num : hashSet)
        {
            // Check if 'num' is the start of a sequence
            // (i.e., num-1 is not present)
            if (!hashSet.count(num - 1))
            {
                // Start of the current sequence
                int currentElement = num;

                // Length of the current sequence
                int currentStreak = 1;

                // Continue to check for consecutive numbers
                // (num+1, num+2, ...)
                while (hashSet.count(currentElement + 1))
                {
                    currentElement += 1;
                    currentStreak++;
                }

                // Update longest streak if current one is longer
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        // Return the length of the longest consecutive sequence
        return longestStreak;
    }
};