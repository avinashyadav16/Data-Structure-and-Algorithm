/**
 *  @file: Max_Consecutive_Ones_III.cpp
 *  @author: Avinash Yadav
 *  @brief: Finds the longest contiguous subarray of 1s by flipping at most `k` zeroes
 *          using the sliding window approach.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Left boundary of the sliding window
        int leftPtr = 0;

        // Right boundary of the sliding window
        int rightPtr = 0;

        // Stores the maximum length of a valid subarray
        int maxLen = 0;

        // Count of zeroes in the current window
        int zeroCnt = 0;

        while (rightPtr < n)
        {
            // Expand the window:
            // If we encounter a zero, increase zero count
            if (nums[rightPtr] == 0)
            {
                zeroCnt += 1;
            }

            // If the number of zeroes exceeds `k`,
            // shrink the window from the left
            while (zeroCnt > k)
            {
                if (nums[leftPtr] == 0)
                {
                    // Reduce zero count as we move the left boundary
                    zeroCnt -= 1;
                }

                // Always move the left boundary forward
                leftPtr += 1;
            }

            // Calculate the length of the current valid subarray and
            // update max length
            maxLen = max(maxLen, rightPtr - leftPtr + 1);

            // Move right pointer forward to expand the window
            rightPtr += 1;
        }

        return maxLen;
    }
};

// OPTIMAL CODE:

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        // Left boundary of the sliding window
        int left = 0;

        // Right boundary of the sliding window
        int right = 0;

        // Count of zeroes in the current window
        int zeroCount = 0;

        // Stores the maximum length of valid subarray
        int maxLength = 0;

        while (right < nums.size())
        {
            // Expand the window: If we encounter a zero,
            // increase zeroCount
            if (nums[right] == 0)
            {
                zeroCount++;
            }

            // Shrink the window if zeroCount exceeds k
            if (zeroCount > k)
            {
                // If the leftmost element is a zero,
                // decrement zeroCount
                if (nums[left] == 0)
                {
                    zeroCount--;
                }

                // Move the left pointer to maintain a valid window
                left++;
            }

            // Update the maximum valid window size
            maxLength = max(maxLength, right - left + 1);

            // Expand the window by moving the right pointer
            right++;
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << "Longest contiguous subarray with at most " << k << " flips: "
         << sol.longestOnes(nums, k) << endl;

    return 0;
}
