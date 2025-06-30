/**
*  @file: Frog_Jump.cpp
*  @author: Avinash Yadav
*  @date: 12-06-2025
*  @link: https://www.naukri.com/code360/problems/frog-jump_3621012
*  @brief: There is a frog on the '1st' step of an 'N' stairs long staircase.
            The frog wants to reach the 'Nth' stair. '
            HEIGHT[i]' is the height of the '(i+1)th' stair.
            If Frog jumps from 'ith' to 'jth' stair,
            the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ).
            If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair.
            Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

            For Example
                If the given ‘HEIGHT’ array is [10,20,30,10],
                the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and
                then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.

                Sample Input 1:
                    2
                    4
                    10 20 30 10
                    3
                    10 50 10

                Sample Output 1:
                    20
                    0

                Explanation of sample input 1:
                    For the first test case,
                    The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
                    Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
                    So, the total energy lost is 20 which is the minimum.
                    Hence, the answer is 20.

                For the second test case:
                    The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
                    So, the total energy lost is 0 which is the minimum.
                    Hence, the answer is 0.

                Sample Input 2:
                    8
                    2
                    7 4 4 2 6 6 3 4
                    6
                    4 8 3 10 4 4

                    Sample Output 2:
                    7
                    2

                    */

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
// APPROACH 01: RECURSION
//////////////////////////////////////////////////////////////////////////////////////////
int minEnergy(int idx, vector<int> &heights)
{
    if (idx == 0)
    {
        return 0;
    }

    int left = minEnergy(idx - 1, heights) +
               abs(heights[idx] - heights[idx - 1]);

    int right = INT_MAX;
    if (idx > 1)
    {
        right = minEnergy(idx - 2, heights) +
                abs(heights[idx] - heights[idx - 2]);
    }

    return min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    return minEnergy(n - 1, heights);
}

//////////////////////////////////////////////////////////////////////////////////////////
// APPROACH 02: MEMOIZATION
//////////////////////////////////////////////////////////////////////////////////////////

int minEnergy(int idx, vector<int> &heights, vector<int> &dp)
{
    if (idx == 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int left = minEnergy(idx - 1, heights, dp) +
               abs(heights[idx] - heights[idx - 1]);

    int right = INT_MAX;
    if (idx > 1)
    {
        right = minEnergy(idx - 2, heights, dp) +
                abs(heights[idx] - heights[idx - 2]);
    }

    return dp[idx] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);

    return minEnergy(n - 1, heights, dp);
}

//////////////////////////////////////////////////////////////////////////////////////////
// APPROACH 03: TABULATION
//////////////////////////////////////////////////////////////////////////////////////////

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int firstStep = dp[i - 1] +
                        abs(heights[i] - heights[i - 1]);

        int secondStep = INT_MAX;
        if (i > 1)
        {
            secondStep = dp[i - 2] +
                         abs(heights[i] - heights[i - 2]);
        }

        dp[i] = min(firstStep, secondStep);
    }

    return dp[n - 1];
}

//////////////////////////////////////////////////////////////////////////////////////////
// APPROACH 04: SPACE OPTIMIZATION
//////////////////////////////////////////////////////////////////////////////////////////

int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int firstStep = prev1 +
                        abs(heights[i] - heights[i - 1]);

        int secondStep = INT_MAX;
        if (i > 1)
        {
            secondStep = prev2 +
                         abs(heights[i] - heights[i - 2]);
        }

        int curri = min(firstStep, secondStep);
        prev2 = prev1;
        prev1 = curri;
    }

    return prev1;
}

int main()
{
    int n;
    cout << "Enter Stairs Lengths: ";
    cin >> n;

    cout << "Enter Stairs Heights: " << endl;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        heights[i] = temp;
    }

    cout << frogJump(n, heights) << endl;

    return 0;
}