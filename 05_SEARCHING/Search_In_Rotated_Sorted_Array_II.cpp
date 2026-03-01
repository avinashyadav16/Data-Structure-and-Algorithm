/**
 *  @file: Search_In_Rotated_Sorted_Array_II.cpp
 *  @brief: This file contains the implementation of the solution to the Search in Rotated Sorted Array II problem.
 *          The problem is to determine if a target value exists in a rotated sorted array that may contain duplicates.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    /**
     * @brief Searches for a target value in a rotated sorted array that may contain duplicates.
     *
     * @param nums The rotated sorted array.
     * @param target The target value to search for.
     * @return true if the target value is found, otherwise false.
     */
    bool search(vector<int> &nums, int target)
    {
        // Size of the input array.
        int n = nums.size();

        // Left pointer for binary search.
        int left = 0;

        // Right pointer for binary search.
        int right = n - 1;

        while (left <= right)
        {
            // Calculate the middle index to avoid overflow.
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                // Target found at the middle index.
                return true;
            }

            // Handle duplicates:
            // If the middle element is equal to both the left and right elements,
            // move both pointers inward.
            if (nums[mid] == nums[left] && nums[mid] == nums[right])
            {
                left += 1;
                right -= 1;
                continue;
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
        return false;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};

    int target = 0;

    bool result = sol.search(nums, target);
    
    cout << (result ? "Target found in the array." : "Target not found in the array.") << endl;

    return 0;
}