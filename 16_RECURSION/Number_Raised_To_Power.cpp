/**
 *  @file: Number_Raised_To_Power.cpp
 *  @author: Avinash Yadav
 *  @brief: This program calculates the power of a number using recursion.
 *  @links: https://leetcode.com/problems/powx-n/description
 */

#include <bits/stdc++.h>
using namespace std;

// Function to calculate a^b using recursion
int fun(int a, int b)
{
    // Base case: if b is 0, return 1 (a^0 = 1)
    if (!b)
        return 1;

    // Recursive call: calculate a^(b/2)
    int ans = fun(a, b / 2);

    // Square the result of a^(b/2)
    ans = ans * ans;

    // If b is odd, multiply the result by a
    if (b % 2)
        ans = ans * a;

    return ans;
}

int main()
{
    cout << fun(2, 10) << endl;

    return 0;
}