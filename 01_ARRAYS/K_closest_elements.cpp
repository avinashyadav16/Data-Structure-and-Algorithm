/**
*  @file: K_closest_elements.cpp
*  @author: Avinash Yadav
*  @date: 12-06-2025
*  @link: https://www.geeksforgeeks.org/problems/k-closest-elements3619/1
*  @brief: You are given a sorted array arr[] of unique integers, an integer k, and a target value x.
            Return exactly k elements from the array closest to x, excluding x if it exists.
            An element a is closer to x than b if:
                |a - x| < |b - x|, or
                |a - x| == |b - x| and a > b (i.e., prefer the larger element if tied)

            Return the k closest elements in order of closeness.

            Example 01:
                Input: arr[] = [1, 3, 4, 10, 12], k = 2, x = 4
                Output: 3 1
                Explanation: 4 is excluded, Closest elements to 4 are: 3 (1), 1 (3). So, the 2 closest elements are: 3 1

            Example 02:
                Input: arr[] = [12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56], k = 4, x = 35
                Output: 39 30 42 45
                Explanation: First closest element to 35 is 39.
                    Second closest element to 35 is 30.
                    Third closest element to 35 is 42.
                    And fourth closest element to 35 is 45.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void binarySearch(int n, int k, int x, vector<int> &arr, vector<int> &ans)
    {
        // Find the crossover point: the index of the largest element <= x
        int left = 0, right = n - 1, cross = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= x)
            {
                cross = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        // Now use two pointers to find k closest elements (excluding x itself if present)
        int l = cross, r = cross + 1;
        int cnt = 0;
        while (l >= 0 && r < n && cnt < k)
        {
            if (arr[l] == x)
            {
                l--;
                continue;
            }

            if (arr[r] == x)
            {
                r++;
                continue;
            }

            if ((abs(arr[l] - x) < abs(arr[r] - x)) || ((abs(arr[l] - x) == abs(arr[r] - x)) && (arr[l] > arr[r])))
            {
                ans.push_back(arr[l--]);
            }
            else
            {
                ans.push_back(arr[r++]);
            }

            cnt++;
        }

        while (cnt < k && l >= 0)
        {
            if (arr[l] != x)
            {
                ans.push_back(arr[l]);
                cnt++;
            }

            l--;
        }

        while (cnt < k && r < n)
        {
            if (arr[r] != x)
            {
                ans.push_back(arr[r]);
                cnt++;
            }

            r++;
        }
    }

    vector<int> printKClosest(vector<int> arr, int k, int x)
    {
        vector<int> ans;
        int n = arr.size();

        binarySearch(n, k, x, arr, ans);

        return ans;
    }
};

int main()
{
    vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int k = 4, x = 35;

    Solution sol;

    vector<int> res = sol.printKClosest(arr, k, x);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}