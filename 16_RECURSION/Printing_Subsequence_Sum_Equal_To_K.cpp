/**
 *  @file: Printing_Subsequence_Sum_Equal_To_K.cpp
 *  @author: Avinash Yadav
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;

// Function to print all subsequences of the array whose sum is equal to the target
void printingSubsequences(vector<int> &arr, vector<int> &res, int index, int sum, int target, int n)
{
    // Base case: If we have traversed all elements in the array
    if (index >= n)
    {
        // Check if the current sum is equal to the target
        if (sum == target)
        {
            // Print the current subsequence
            for (auto num : res)
            {
                cout << num << " ";
            }
            cout << endl;
        }

        // Return to explore other possibilities
        return;
    }

    // Include the current element in the subsequence
    res.push_back(arr[index]);
    sum += arr[index];
    // Recursive call to process the next element
    printingSubsequences(arr, res, index + 1, sum, target, n);

    // Backtrack: Remove the current element from the subsequence
    res.pop_back();
    sum -= arr[index];
    // Recursive call to process the next element without including the current one
    printingSubsequences(arr, res, index + 1, sum, target, n);

    // Return to the previous state
    return;
}

int main()
{
    vector<int> arr = {1, 2, 1};

    int target = 2;

    int n = arr.size();

    vector<int> res;

    int sum = 0;

    printingSubsequences(arr, res, 0, sum, target, n);

    return 0;
}
