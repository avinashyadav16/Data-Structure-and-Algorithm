/**
 *  @file: 02_EfficientApproach.cpp
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
    int arr[9] = {1, 3, 3, 4, 1, 4, 4, 4, 4};

    int query[3] = {1, 3, 4};

    int arrB[9] = {0};

    for (int i = 0; i < 9; i++)
    {
        int x = arr[i];
        arrB[x] += 1;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << query[i] << " = " << arrB[query[i]] << endl;
    }

    return 0;
}