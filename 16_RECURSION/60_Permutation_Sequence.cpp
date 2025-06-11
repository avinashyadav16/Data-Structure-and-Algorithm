/**
*  @file: 60_Permutation_Sequence.cpp
*  @author: Avinash Yadav
*  @date: 10-06-2025
*  @link: https://leetcode.com/problems/permutation-sequence/description/
*  @brief: The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
            By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
                "123"
                "132"
                "213"
                "231"
                "312"
                "321"

            Given n and k, return the kth permutation sequence.

            Example 1:
                Input: n = 3, k = 3
                Output: "213"

            Example 2:
                Input: n = 4, k = 9
                Output: "2314"

            Example 3:
                Input: n = 3, k = 1
                Output: "123"

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the kth permutation sequence of numbers from 1 to n
    string getPermutation(int n, int k)
    {
        // Stores the numbers to be used in the permutation
        vector<int> nums;

        // Stores (n-1)!
        int fact = 1;

        // Initialize the nums vector with numbers from 1 to n
        for (int i = 1; i < n; i++)
        {
            // Compute (n-1)!
            fact = fact * i;

            nums.push_back(i);
        }
        // Add the last number
        nums.push_back(n);

        // Convert k to zero-based index
        k = k - 1;
        string ans = "";

        // Build the permutation one digit at a time
        while (true)
        {
            // Select the index of the current digit
            ans = ans + to_string(nums[k / fact]);

            // Remove the used number from the list
            nums.erase(nums.begin() + k / fact);

            // If all numbers are used, break
            if (nums.size() == 0)
            {
                break;
            }

            // Update k and fact for the next position
            k = k % fact;
            fact = fact / nums.size();
        }

        return ans;
    }
};

int main()
{

    int n;
    cin >> n;

    int k;
    cin >> k;

    Solution sol;

    cout << sol.getPermutation(n, k) << endl;

    return 0;
}