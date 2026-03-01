/**
 *  @file: C._Little_Girl_and_Maximum_Sum.cpp
 *  @author: Avinash Yadav
 *  @date: 03-06-2025
 *  @link: https://codeforces.com/contest/276/problem/C
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    vector<int> diffStart(n + 1, 0);
    vector<int> diffEnd(n + 1, 0);

    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;

        diffStart[l]++;

        if (r + 1 <= n)
        {
            diffEnd[r + 1]++;
        }
    }

    int queryIdx = 0;
    vector<int> querySum(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        queryIdx += (diffStart[i] - diffEnd[i]);
        querySum[i] = queryIdx;
    }

    sort(nums.begin(), nums.end());
    sort(querySum.begin(), querySum.end());

    long long maxSum = 0;
    for (int i = 1; i <= n; i++)
    {
        maxSum += (static_cast<long long>(nums[i]) * querySum[i]);
    }

    cout << maxSum << endl;

    return 0;
}