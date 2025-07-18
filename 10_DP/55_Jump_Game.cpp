/**
*  @file: 55_Jump_Game.cpp
*  @author: Avinash Yadav
*  @date: 13-06-2025
*  @link: https://leetcode.com/problems/jump-game/description/
*  @brief: You are given an integer array nums.
            You are initially positioned at the array's first index,
            and each element in the array represents your maximum jump length at that position.
            Return true if you can reach the last index, or false otherwise.

            Example 1:
                Input: nums = [2,3,1,1,4]
                Output: true
                Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

            Example 2:
                Input: nums = [3,2,1,0,4]
                Output: false
                Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0,
                            which makes it impossible to reach the last index.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    // 0: unvisited,
    // 1: can reach end,
    // -1: cannot reach end
    bool isPossible(int idx, vector<int> &nums, vector<int> &dp)
    {
        if (idx >= nums.size() - 1)
        {
            return true;
        }

        if (dp[idx] != 0)
        {
            return dp[idx] == 1;
        }

        // To ensure that we do not go out of the array bound.
        // (int)nums.size() - 1
        //  => Last index value of the array.
        // idx + nums[idx]
        //  => The max index we can go from the current index.
        // Taking min of both
        // ensures that we remain within the array last index.
        int furthestJump = min((int)nums.size() - 1, idx + nums[idx]);
        for (int i = idx + 1; i <= furthestJump; i++)
        {
            if (isPossible(i, nums, dp))
            {
                dp[idx] = 1;
                return true;
            }
        }

        dp[idx] = -1;
        return false;
    }

    // MEMOMIZATION APPROACH:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, 0);

        return isPossible(0, nums, dp);
    }
};

class Solution2
{
public:
    // TABULATION APPROACH:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, 0);

        // The last index is always reachable from itself
        dp[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            int furthestJump = min(i + nums[i], n - 1);
        
            for (int j = i + 1; j <= furthestJump; j++)
            {
                if (dp[j] == 1)
                {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[0] == 1;
    }
};

int main()
{
    vector<int> nums1 = {2, 3, 1, 1, 4}; // true
    vector<int> nums2 = {3, 2, 1, 0, 4}; // false

    Solution1 sol1;
    cout << "MEMOIZATION APPROACH:" << endl;
    cout << boolalpha << sol1.canJump(nums1) << endl;
    cout << boolalpha << sol1.canJump(nums2) << endl;

    Solution2 sol2;
    cout << "TABULATION APPROACH:" << endl;
    cout << boolalpha << sol2.canJump(nums1) << endl;
    cout << boolalpha << sol2.canJump(nums2) << endl;

    return 0;
}