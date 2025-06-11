/**
 *  @file: Count_Number_Of_Subsequences_With_Sum_Equals_K.cpp
 *  @author: Avinash Yadav
 *  @brief:  https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532
 */

#include <bits/stdc++.h>
using namespace std;

int cntSubsequences(vector<int> &arr, vector<int> &res, int index, int sum, int target, int n)
{
    if (index >= n)
    {
        if (sum == target)
        {
            for (auto num : res)
            {
                cout << num << " ";
            }
            cout << endl;

            return 1;
        }

        return 0;
    }

    res.push_back(arr[index]);
    sum += arr[index];
    int left = cntSubsequences(arr, res, index + 1, sum, target, n);

    res.pop_back();
    sum -= arr[index];
    int right = cntSubsequences(arr, res, index + 1, sum, target, n);

    return left + right;
}

int main()
{
    vector<int> arr = {1, 2, 1};

    int target = 2;

    int n = arr.size();

    vector<int> res;

    int sum = 0;

    cout << cntSubsequences(arr, res, 0, sum, target, n) << endl;

    return 0;
}