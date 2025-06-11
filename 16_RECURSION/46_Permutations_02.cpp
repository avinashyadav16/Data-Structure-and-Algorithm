/**
*  @file: 46_Permutations.cpp
*  @author: Avinash Yadav
*  @date: 09-06-2025
*  @link: https://leetcode.com/problems/permutations/description/
*  @brief: Given an array nums of distinct integers, return all the possible permutations.
            You can return the answer in any order.

            Example 1:
                Input: nums = [1,2,3]
                Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

            Example 2:
                Input: nums = [0,1]
                Output: [[0,1],[1,0]]
*/

// METHOD 02: SC = O(n!)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function to recursively generate permutations
    // idx: current index to fix
    // nums: current state of the array
    // res: stores all generated permutations
    void findPermutations(int idx, vector<int> &nums, vector<vector<int>> &res)
    {
        // Base case:
        // if we've fixed all positions, add current permutation to result
        if (idx == nums.size())
        {
            res.push_back(nums);
            return;
        }

        // Try all possibilities for the current position
        for (int i = idx; i < nums.size(); i++)
        {
            // Swap the current index with i to fix one element at idx
            swap(nums[idx], nums[i]);

            // Recurse for the next index
            findPermutations(idx + 1, nums, res);

            // Backtrack: restore the original array
            swap(nums[i], nums[idx]);
        }
    }

    // Main function to be called for generating permutations
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res; // Stores all permutations

        // Start the recursive process from index 0
        findPermutations(0, nums, res);

        return res;
    }
};

int main()
{
    string line;
    getline(cin, line);

    stringstream ss(line);

    int input;
    vector<int> nums;

    while (ss >> input)
    {
        nums.push_back(input);
    }

    Solution sol;

    vector<vector<int>> result = sol.permute(nums);

    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";

        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
            {
                cout << ",";
            }
        }

        cout << "]";

        if (i < result.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";

    return 0;
}