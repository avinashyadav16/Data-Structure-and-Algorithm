/**
*  @file: 18_4Sum.cpp
*  @author: Avinash Yadav
*  @date: 16-08-2025
*  @link: https://leetcode.com/problems/4sum/description/
*  @brief: Given an array nums of n integers,
            return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
                0 <= a, b, c, d < n
                a, b, c, and d are distinct.
                nums[a] + nums[b] + nums[c] + nums[d] == target

            You may return the answer in any order.

            Example 1:
                Input: nums = [1,0,-1,0,-2,2], target = 0
                Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

            Example 2:
                Input: nums = [2,2,2,2,2], target = 8
                Output: [[2,2,2,2]]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int binary_search(const vector<int> &nums, int start, int end, int comp)
    {
        int left = start, right = end - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == comp)
            {
                return mid;
            }
            else if (nums[mid] < comp)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<vector<int>> res;
        set<vector<int>> s;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int currSum = nums[i] + nums[j] + nums[k];
                    int comp = target - currSum;

                    int index = binary_search(nums, k + 1, n, comp);

                    if (index != -1)
                    {
                        vector<int> quad = {nums[i], nums[j], nums[k], nums[index]};

                        sort(quad.begin(), quad.end());

                        s.insert(quad);
                    }
                }
            }
        }

        for (auto &quad : s)
        {
            res.push_back(quad);
        }

        return res;
    }
};

class Solution2
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            // skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                // skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int leftPtr = j + 1;
                int rightPtr = n - 1;

                while (leftPtr < rightPtr)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[leftPtr] + nums[rightPtr];

                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[leftPtr], nums[rightPtr]});

                        while (leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr + 1])
                        {
                            leftPtr++;
                        }

                        while (leftPtr < rightPtr && nums[rightPtr] == nums[rightPtr - 1])
                        {
                            rightPtr--;
                        }

                        leftPtr++;
                        rightPtr--;
                    }
                    else if (sum < target)
                    {
                        leftPtr++;
                    }
                    else
                    {
                        rightPtr--;
                    }
                }
            }
        }

        return res;
    }
};
