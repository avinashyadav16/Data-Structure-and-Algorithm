/**
 *  @file: 07_CheckDuplicateElementWithinDistanceK.cpp
 *  @author: Avinash Yadav
 *  @brief: Check if the following given array contains duplicate elements within k distance from each other.
 *  @date: 10-10-2024
 *
 *  @copyright Copyright (c) 2024
 *
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Brute-Force Approach
bool containsDuplicateWithinDistanceK_BruteForce(const vector<int> &vec, int k)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i + 1; j <= i + k && j < vec.size(); j++)
        {
            if (vec[i] == vec[j])
            {
                cout << "For " << vec[i] << ", it contains duplicate within distance k" << endl;
                return true;
            }
        }
    }
    return false;
}

// Efficient Approach using unordered_map
bool containsDuplicateWithinDistanceK_Efficient(const vector<int> &vec, int k)
{
    unordered_map<int, int> unmpp;
    for (int i = 0; i < vec.size(); i++)
    {
        // Check if element is already present in the map
        if (unmpp.find(vec[i]) != unmpp.end())
        {
            if (i - unmpp[vec[i]] <= k)
            {
                cout << "For " << vec[i] << ", it contains duplicate within distance k" << endl;
                return true;
            }
        }
        // Update the index of the current element
        unmpp[vec[i]] = i;
    }
    return false;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    int k;
    cout << "Enter the k value: ";
    cin >> k;

    // Using Brute-Force Approach
    cout << "\nUsing Brute-Force Approach:" << endl;
    if (!containsDuplicateWithinDistanceK_BruteForce(vec, k))
    {
        cout << "The given array does not contain duplicates within distance k" << endl;
    }

    // Using Efficient Approach
    cout << "\nUsing Efficient Approach:" << endl;
    if (!containsDuplicateWithinDistanceK_Efficient(vec, k))
    {
        cout << "The given array does not contain duplicates within distance k" << endl;
    }

    return 0;
}
