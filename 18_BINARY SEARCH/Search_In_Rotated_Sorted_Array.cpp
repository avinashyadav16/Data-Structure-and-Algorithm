/**
 *  @file: Search_In_Rotated_Sorted_Array.cpp
 *  @brief: This file contains the implementation of the solution to the Search in Rotated Sorted Array problem.
 *          The problem is to determine the index of a target value in a rotated sorted array.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    /**
     * @brief Searches for a target value in a rotated sorted array.
     *
     * @param nums The rotated sorted array.
     * @param target The target value to search for.
     * @return The index of the target value if found, otherwise -1.
     */
    int search(vector<int> &nums, int target)
    {
        int numsSize = nums.size();
        int left = 0;
        int right = numsSize - 1;

        while (left <= right)
        {
            // Calculate the middle index to avoid overflow.
            int mid = left + (right - left) / 2;

            if (target == nums[mid])
            {
                // Target found at the middle index.
                return mid;
            }

            // Check if the left half is sorted.
            if (nums[left] <= nums[mid])
            {
                // Check if the target is within the range of the left half.
                if (target < nums[mid] && target >= nums[left])
                {
                    // Narrow down to the left half.
                    right = mid - 1;
                }
                else
                {
                    // Narrow down to the right half.
                    left = mid + 1;
                }
            }
            else // The right half must be sorted.
            {
                // Check if the target is within the range of the right half.
                if (target > nums[mid] && target <= nums[right])
                {
                    // Narrow down to the right half.
                    left = mid + 1;
                }
                else
                {
                    // Narrow down to the left half.
                    right = mid - 1;
                }
            }
        }

        // Target not found.
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = sol.search(nums, target);
    cout << "Index of target (" << target << "): " << result << endl;

    return 0;
}