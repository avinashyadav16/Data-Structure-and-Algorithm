/**
*  @file: 01_NeiveApproach.cpp
*  @author: Avinash Yadav
*  @brief: Say I give you an array : [1,3,3,4,1,4,4,4,4]
            And ask you(query) to find the frequency of some number in this array.
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

    for (int i = 0; i < 3; i++)
    {
        int q = query[i];
        int count = 0;
        for (int j = 0; j < 9; j++)
        {
            if (q == arr[j])
            {
                count++;
            }
        }
        cout << q << " = " << count << endl;
    }

    return 0;
}