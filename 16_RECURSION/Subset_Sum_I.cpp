/**
 *  @file: Subset_Sum_I.cpp
 *  @author: Avinash Yadav
 *  @brief: https://www.geeksforgeeks.org/problems/subset-sums2234/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to recursively find all subset sums
    void findSubSetSums(int idx, int sum, vector<int> &arr, vector<int> &res)
    {
        // Base case:
        // if we have processed all elements in the array
        if (idx == arr.size())
        {
            // Add the computed sum to the result vector
            res.push_back(sum);

            return;
        }

        // Include the current element in the subset and move to the next index
        findSubSetSums(idx + 1, sum + arr[idx], arr, res);

        // Exclude the current element from the subset and move to the next index
        findSubSetSums(idx + 1, sum, arr, res);
    }

    // Compute all subset sums of the given array
    vector<int> subsetSums(vector<int> &arr)
    {
        // Vector to store the subset sums
        vector<int> res;

        // Start the recursive process from index 0 with an initial sum of 0
        findSubSetSums(0, 0, arr, res);

        // Sort the result vector to return the subset sums in ascending order
        sort(res.begin(), res.end());

        return res;
    }
};