/**
*  @file: maxNinConsecutiveSum.cpp
*  @author: Avinash Yadav
*  @brief: Given an array of integers(positive as well as negative) ,select some elements from this array(select a subset) such that:-
            1. Sum of those elements is maximum(Sum of the subset is maximum) .
            2. No two elements in the subset should be consecutive.
                Example :- {2,4,6,7,8}
                Answer:- {2 + 6 + 8 = 16}
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }

    cout << dp[n - 1] << endl;

    return 0;
}