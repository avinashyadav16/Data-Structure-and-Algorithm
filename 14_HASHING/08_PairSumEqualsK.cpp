/**
 *  @file: 08_PairSumEqualsK.cpp
 *  @author: Avinash Yadav
 *  @brief: Given an array and target 'x', find a pair in the array whose sum is equal to 'x'.
 *  @date: 10-10-2024
 *
 *  @copyright Copyright (c) 2024
 *
 */

#include <bits/stdc++.h>
using namespace std;

// Brute-Force Approach: O(n^2) complexity
bool bruteForce(int arr[], int x, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == x)
            {
                cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << endl;
                return true;
            }
        }
    }
    return false;
}

// Efficient Approach: O(n) complexity
bool efficientApproach(int arr[], int x, int size)
{
    unordered_set<int> uset;

    for (int i = 0; i < size; i++)
    {
        int temp = x - arr[i];

        if (uset.find(temp) != uset.end())
        {
            cout << "Pair found: (" << arr[i] << ", " << temp << ")" << endl;
            return true;
        }

        uset.insert(arr[i]);
    }
    return false;
}

int main()
{
    int arr[] = {0, -1, 2, -3, 1};
    int x = 2;
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Using Brute-Force Approach:" << endl;
    if (!bruteForce(arr, x, size))
    {
        cout << "No pair with the given sum found." << endl;
    }

    cout << "\nUsing Efficient Approach:" << endl;
    if (!efficientApproach(arr, x, size))
    {
        cout << "No pair with the given sum found." << endl;
    }

    return 0;
}
