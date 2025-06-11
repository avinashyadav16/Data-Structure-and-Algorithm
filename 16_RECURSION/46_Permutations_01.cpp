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

// METHOD 01: SC = O(n!) + O(n)

#include <bits/stdc++.h>
using namespace std;

// Solution class to generate all permutations of a given vector of distinct integers
class Solution
{
public:
    // Helper function to recursively find all permutations
    // nums: input vector of integers
    // res: stores all the permutations
    // ds: current permutation being constructed
    // freq: boolean vector to track which elements are already used in the current permutation
    void findPermutations(vector<int> &nums, vector<vector<int>> &res, vector<int> ds, vector<bool> &freq)
    {
        // Base case: if the current permutation is complete, add it to the result
        if (ds.size() == nums.size())
        {
            res.push_back(ds);
            return;
        }

        // Try to include each unused element in the current position
        for (int i = 0; i < nums.size(); i++)
        {
            // If nums[i] is not used yet
            if (freq[i]) 
            {
                ds.push_back(nums[i]); // Include nums[i] in the current permutation
                freq[i] = false;       // Mark nums[i] as used

                // Recurse to fill the next position
                findPermutations(nums, res, ds, freq);

                // Backtrack: remove nums[i] and mark it as unused for the next iteration
                ds.pop_back();
                freq[i] = true;
            }
        }
    }

    // Main function to be called for generating permutations
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> res;    // Stores all permutations
        vector<int> ds;             // Current permutation
        vector<bool> freq(n, true); // Tracks used elements (true = unused)

        // Start the recursive process
        findPermutations(nums, res, ds, freq);

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