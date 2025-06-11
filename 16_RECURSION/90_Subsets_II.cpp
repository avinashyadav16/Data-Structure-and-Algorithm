/**
 *  @file: 90_Subsets_II.cpp
 *  @author: Avinash Yadav
 *  @date: 09-06-2025
 *  @link: https://leetcode.com/problems/subsets-ii/description/
 *  @brief: Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
                The solution set must not contain duplicate subsets. Return the solution in any order.
                    Example 1:
                        Input: nums = [1,2,2]
                        Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 */

#include <bits/stdc++.h>
using namespace std;

// Solution class to generate all unique subsets (the power set) of a list with possible duplicates
class Solution
{
public:
    // Helper function to recursively build subsets
    // idx: current index in nums
    // nums: input vector (sorted)
    // res: stores all unique subsets
    // ds: current subset being constructed
    void findSubSets(int idx, vector<int> &nums, vector<vector<int>> &res, vector<int> &ds)
    {
        // Add the current subset to the result
        res.push_back(ds);

        // Iterate through the array starting from idx
        for (int i = idx; i < nums.size(); i++)
        {
            // Skip duplicates:
            // if current element is same as previous and not at the starting index
            if (i != idx && nums[i] == nums[i - 1])
            {
                continue;
            }

            // Include nums[i] in the current subset
            ds.push_back(nums[i]);

            // Recurse with next index
            findSubSets(i + 1, nums, res, ds);

            // Backtrack: remove last element before next iteration
            ds.pop_back();
        }
    }

    // Main function to return all unique subsets
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // Stores all unique subsets
        vector<vector<int>> res;

        // Temporary vector for current subset
        vector<int> ds;

        // Sort the input to bring duplicates together
        sort(nums.begin(), nums.end());

        // Start recursive subset generation from index 0
        findSubSets(0, nums, res, ds);

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

    vector<vector<int>> result = sol.subsetsWithDup(nums);

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
