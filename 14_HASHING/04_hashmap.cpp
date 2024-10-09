/**
 *  @file: 04_hashmap.cpp
 *  @author: Avinash Yadav
 *  @brief:
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
    unordered_map<int, int> unmpp;
    unmpp[2] = 6;
    unmpp[4] = 5;
    unmpp[1] = 3;

    for (auto &ele : unmpp)
    {
        cout << ele.first << " " << ele.second << endl;
    }

    if (unmpp.find(4) != unmpp.end())
    {
        cout << "Key = 4 : Value = " << unmpp[4] << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    //////////////////////////////////////////////////////

    map<int, int> mpp;
    mpp[2] = 6;
    mpp[4] = 5;
    mpp[1] = 3;

    for (auto &ele : mpp)
    {
        cout << ele.first << " " << ele.second << endl;
    }

    if (mpp.find(4) != mpp.end())
    {
        cout << "Key = 4 : Value = " << mpp[4] << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}