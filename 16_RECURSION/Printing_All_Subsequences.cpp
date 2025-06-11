/**
 *  @file: Printing_All_Subsequences.cpp
 *  @author: Avinash Yadav
 *  @brief: Printing all subsequences of a string using recursion.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to print all subsequences of a given array using recursion
void printingSubsequences(vector<int> &arr, vector<int> &res, int index, int n)
{
    // Base case: If the current index is out of bounds,
    // print the current subsequence
    if (index >= n)
    {
        // Print each element in the current subsequence
        for (auto num : res)
        {
            cout << num << " ";
        }
        if (res.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;

        return;
    }

    // Include the current element in the subsequence
    res.push_back(arr[index]);
    printingSubsequences(arr, res, index + 1, n);

    // Exclude the current element from the subsequence (backtrack)
    // res.erase(res.end() - 1);
    res.pop_back();
    printingSubsequences(arr, res, index + 1, n);

    return;
}

int main()
{
    // Input array
    vector<int> arr = {1, 2, 3};
    // Vector to store the current subsequence
    vector<int> res;

    // Size of the input array
    int n = arr.size();

    // Call the function to print all subsequences
    printingSubsequences(arr, res, 0, n);

    return 0;
}

// class Solution
// {
// public:
//     void findSubsets(int idx, int n, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
//     {
//         if (idx >= n)
//         {
//             ans.push_back(ds);

//             return;
//         }

//         ds.push_back(nums[idx]);
//         findSubsets(idx + 1, n, nums, ans, ds);
//         ds.pop_back();

//         findSubsets(idx + 1, n, nums, ans, ds);
//     }

//     vector<vector<int>> subsets(vector<int> &nums)
//     {
//         vector<vector<int>> ans;
//         int n = nums.size();
//         vector<int> ds;

//         findSubsets(0, n, nums, ans, ds);

//         return ans;
//     }
// };
