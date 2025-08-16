/**
*  @file: 239_Sliding_Window_Maximum.cpp
*  @author: Avinash Yadav
*  @date: 15-08-2025
*  @link: https://leetcode.com/problems/sliding-window-maximum/description/
*  @brief: You are given an array of integers nums,
            there is a sliding window of size k which is moving from the very left of the array to the very right.
            You can only see the k numbers in the window. Each time the sliding window moves right by one position.
            Return the max sliding window.

            Example 1:
                Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
                Output: [3,3,5,5,6,7]
                Explanation:
                    Window position                Max
                    ---------------               -----
                    [1  3  -1] -3  5  3  6  7       3
                    1 [3  -1  -3] 5  3  6  7       3
                    1  3 [-1  -3  5] 3  6  7       5
                    1  3  -1 [-3  5  3] 6  7       5
                    1  3  -1  -3 [5  3  6] 7       6
                    1  3  -1  -3  5 [3  6  7]      7

            Example 2:
                Input: nums = [1], k = 1
                Output: [1]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> ans;

        for (int i = 0; i <= n - k; i++)
        {
            int maxi = nums[i];

            for (int j = i; j <= i + k - 1; j++)
            {
                maxi = max(maxi, nums[j]);
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};

class Solution2
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Stores the result
        vector<int> ans;

        // Stores indices of useful elements in current window
        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // Remove indices whose corresponding values are less than nums[i]
            // They are not useful for future windows
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }

            // Add current index to the deque
            dq.push_back(i);

            // If window has at least k elements, record the maximum
            if (i >= k - 1)
            {
                // The front of deque is the max in current window
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
