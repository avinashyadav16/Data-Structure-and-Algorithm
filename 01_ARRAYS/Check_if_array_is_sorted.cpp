/**
 *  @file: Check_if_array_is_sorted.cpp
 *  @author: Avinash Yadav
 *  @brief: Given an array nums, return true if the array was originally sorted in non-decreasing order,
 *           then rotated some number of positions (including zero).
 *           Otherwise, return false.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();

        int start = 0, end = n - 1;

        // Traverse the array
        // from the beginning and end
        // to find the breaking point
        while (start < end)
        {
            // If the current element
            // is less than or equal to the next,
            // move forward
            if (nums[start] <= nums[start + 1])
            {
                start++;
            }
            // If the current element
            // from the end is greater than or equal to
            // the previous,
            // move backward
            else if (nums[end] >= nums[end - 1])
            {
                end--;
            }
            // If neither condition is met,
            // break the loop
            else
            {
                break;
            }
        }

        // Check if the array can be considered rotated and sorted
        // Case 1: The array is fully traversed and meets the condition
        // Case 2:
        // The array is rotated such that
        // the last element is less than or equal to the first
        if ((start + 1 == end) && (nums[0] >= nums[n - 1]) || start == end)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};