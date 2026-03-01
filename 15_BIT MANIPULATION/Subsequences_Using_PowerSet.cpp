/**
*  @file: Subsequences_Using_PowerSet.cpp
*  @author: Avinash Yadav
*  @date: 09-06-2025
*  @link:
*  @brief: Given an array of integers nums of unique elements. Return all possible subsets (power set) of the array.
            Do not include the duplicates in the answer.

            Examples:
                Input : nums = [1, 2, 3]
                Output : [ [ ] , [1] , [2] , [1, 2] , [3] , [1, 3] , [2, 3] , [1, 2 ,3] ]

                Input : nums = [1, 2]
                Output : [ [ ] , [1] , [2] , [1,2] ]
*/

#include <bits/stdc++.h>
using namespace std;

// Solution class to generate all possible subsets (the power set) of a given array of unique integers.
class Solution
{
public:
    // Function to return all subsets of the input vector nums.
    vector<vector<int>> powerSet(vector<int> &nums)
    {
        // Number of elements in nums
        int n = nums.size();

        // To store all subsets
        vector<vector<int>> result;

        // There are 2^n possible subsets for a set of size n.
        // Each subset can be represented by a bitmask of length n.
        for (int num = 0; num < (1 << n); num++)
        {
            // Temporary vector to store the current subset
            vector<int> ds; 

            // Check each bit position
            for (int i = 0; i < n; i++)
            {
                // If the i-th bit is set in num,
                // include nums[i] in the current subset
                if ((num & (1 << i)) != 0)
                {
                    ds.push_back(nums[i]);
                }
            }

            // Add the current subset to the result
            result.push_back(ds);
        }

        // Return all possible subsets
        return result;
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

    vector<vector<int>> result = sol.powerSet(nums);

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