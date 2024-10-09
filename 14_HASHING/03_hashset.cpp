/**
 *  @file: 03_hashset.cpp
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
    unordered_set<int> un_set;
    un_set.insert(10);
    un_set.insert(20);
    un_set.insert(30);
    un_set.insert(30);
    un_set.insert(20);
    un_set.insert(10);

    for (auto &ele : un_set)
    {
        cout << ele << " ";
    }
    cout << endl;

    if (un_set.find(20) != un_set.end())
    {
        cout << "20 found" << endl;
    }
    else
    {
        cout << "20 not found" << endl;
    }

    /////////////////////////////////////////////////

    set<int> set;
    set.insert(100);
    set.insert(200);
    set.insert(300);
    set.insert(300);
    set.insert(200);
    set.insert(100);

    for (auto &ele : set)
    {
        cout << ele << " ";
    }
    cout << endl;

    if (set.find(200) != set.end())
    {
        cout << "200 found" << endl;
    }
    else
    {
        cout << "200 not found" << endl;
    }

    return 0;
}