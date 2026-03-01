/**
 * @file: 493_Reverse_Pairs.cpp
 * @author: Avinash Yadav
 * @date: 29-08-2025
 * @link: https://leetcode.com/problems/reverse-pairs/description/
 * @brief: Given an integer array nums, return the number of reverse pairs in the array.
            A reverse pair is a pair (i, j) where:
                0 <= i < j < nums.length and
                nums[i] > 2 * nums[j].

            Example 1:
                Input: nums = [1,3,2,3,1]
                Output: 2
                Explanation: The reverse pairs are:
                (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
                (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

            Example 2:
                Input: nums = [2,4,3,5,1]
                Output: 3
                Explanation: The reverse pairs are:
                (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
                (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
                (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
    }
};