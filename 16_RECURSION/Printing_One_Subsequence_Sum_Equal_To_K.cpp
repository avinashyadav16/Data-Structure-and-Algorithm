/**
 *  @file: Printing_One_Subsequence_Sum_Equal_To_K.cpp
 *  @author: Avinash Yadav
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;

// Function to print one subsequence whose sum is equal to the target
bool printingSubsequences(vector<int> &arr, vector<int> &res, int index, int sum, int target, int n)
{
    // Base case: If we have traversed all elements
    if (index >= n)
    {
        // CONDITION SATISFIED
        // Check if the current sum matches the target
        if (sum == target)
        {
            // Print the subsequence
            for (auto num : res)
            {
                cout << num << " ";
            }
            cout << endl;

            // Return true as we found a valid subsequence
            return true;
        }

        // CONDITION NOT SATISFIED
        // Return false if the sum does not match the target
        return false;
    }

    // Include the current element in the subsequence
    res.push_back(arr[index]);
    sum += arr[index];

    // Recursive call to include the next element
    if (printingSubsequences(arr, res, index + 1, sum, target, n) == true)
    {
        // If a valid subsequence is found, propagate true
        return true;
    }

    // Backtrack: Remove the current element from the subsequence
    res.pop_back();
    sum -= arr[index];

    // Recursive call to exclude the current element and move to the next
    return printingSubsequences(arr, res, index + 1, sum, target, n);
}

int main()
{
    vector<int> arr = {1, 2, 1};

    int target = 2;

    int n = arr.size();

    vector<int> res;

    int sum = 0;

    cout << printingSubsequences(arr, res, 0, sum, target, n) << endl;

    return 0;
}
