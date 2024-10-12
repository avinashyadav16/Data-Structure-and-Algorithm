/**
 *  @file: 06_AllElementsEqual.cpp
 *  @author: Avinash Yadav
 *  @brief: Program to find the minimum number of operations required to make all elements in a vector equal.
 *  @date: 08-10-2024
 *
 *  @copyright Copyright (c) 2024
 *
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 5, 6, 7, 8, 1, 2, 5};

    // Brute-force approach
    int maxFreq = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[i] == vec[j])
            {
                cnt++;
            }
        }
        if (cnt > maxFreq)
        {
            maxFreq = cnt;
        }
    }

    cout << (vec.size() - maxFreq) << endl;

    // Optimized approach
    unordered_map<int, int> freq;

    for (int i = 0; i < vec.size(); i++)
    {
        int x = vec[i];
        freq[x]++;
    }

    int maxfreqEle;
    int ele_cnt = 0;
    for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); it++)
    {
        if (it->second > ele_cnt)
        {
            ele_cnt = it->second;
            maxfreqEle = it->first;
        }
    }

    cout << (vec.size() - ele_cnt) << endl;

    return 0;
}
