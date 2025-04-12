/**
 *  @file: Combination_Sum.cpp
 *  @author: Avinash Yadav
 *  @brief: Combination Sum
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function to find all combinations that sum up to the target
    void findCombinations(int idx, int target, vector<int> &candidates, vector<vector<int>> &result, vector<int> &ds)
    {
        // Base case: if we have considered all elements
        if (idx == candidates.size())
        {
            // If the target is met, add the current combination to the result
            if (target == 0)
            {
                result.push_back(ds);
            }
            return;
        }

        // Include the current element in the combination if it does not exceed the target
        if (candidates[idx] <= target)
        {
            // Add the element to the current combination
            ds.push_back(candidates[idx]);

            // Recur with the same index (allowing repetition) and reduced target
            findCombinations(idx, target - candidates[idx], candidates, result, ds);

            // Backtrack by removing the last added element
            ds.pop_back();
        }

        // Exclude the current element and move to the next index
        findCombinations(idx + 1, target, candidates, result, ds);
    }

    // Main function to find all unique combinations that sum up to the target
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // To store all valid combinations
        vector<vector<int>> result;

        // Temporary data structure to store the current combination
        vector<int> ds;

        // Start the recursive process
        findCombinations(0, target, candidates, result, ds);

        return result;
    }
};