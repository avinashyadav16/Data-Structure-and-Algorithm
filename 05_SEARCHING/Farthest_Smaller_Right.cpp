/**
*  @file: Farthest_Smaller_Right.cpp
*  @author: Avinash Yadav
*  @date: 19-08-2025
*  @link: https://www.geeksforgeeks.org/problems/farthest-smaller-right/1
*  @brief: You are given an array arr[]. For each element at index i (0-based indexing),
            find the farthest index j to the right (i.e., j > i) such that arr[j] < arr[i].
            If no such index exists for a given position, return -1 for that index.
            Return the resulting array of answers.

            Examples:
            Input:
                arr[] = [2, 5, 1, 3, 2]
            Output:
                [2, 4, -1, 4, -1]
            Explanation:
                arr[0] = 2: Farthest smaller element to the right is arr[2] = 1.
                arr[1] = 5: Farthest smaller element to the right is arr[4] = 2.
                arr[2] = 1: No smaller element to the right → -1.
                arr[3] = 3: Farthest smaller element to the right is arr[4] = 2.
                arr[4] = 2: No elements to the right → -1.

            Input:
                arr[] = [2, 3, 5, 4, 1]
            Output:
                [4, 4, 4, 4, -1]
            Explanation:
                arr[4] is the farthest smallest element to the right for arr[0], arr[1], arr[2] and arr[3].


            [Expected Approach] Binary Search
                O(n*log(n)) Time and O(n) Space

                The idea is to find the farthest smaller element to the right for each arr[i],
                we want a way to quickly know if a smaller element exists further ahead and how far it is.
                Instead of scanning all elements to the right of every index, we can precompute:
                The minimum values in all suffixes of the array.
                This allows us to efficiently search for the farthest valid position using binary search.

            Step By Step Implementations:

                Suffix Minimum Array
                    -> For each position in the array, store the minimum value among all elements from that index to the end.
                    -> This allows us to know quickly if there's any smaller element on the right.
                Binary Search for Each Element
                    -> For every element arr[i], use binary search on the suffix minimum array to find the farthest index j > i
                    such that the value at j is smaller than arr[i].
                    -> We try to go as far as possible to the right while the condition holds.
                Store and Return Results
                    -> If such an index is found, store it.
                    -> If not, store -1 for that position.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> farMin(vector<int> &arr)
{
    int n = arr.size();

    vector<int> FSE(n, -1);

    // build suffix min array
    vector<int> suffixMin(n);
    suffixMin[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suffixMin[i] = min(arr[i], suffixMin[i + 1]);
    }

    // binary search on suffix for farthest smaller element
    for (int i = 0; i < n; ++i)
    {
        int lo = i + 1;
        int hi = n - 1;
        int res = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            
            if (suffixMin[mid] < arr[i])
            {
                res = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        FSE[i] = res;
    }

    return FSE;
}

int main()
{
    vector<int> arr = {2, 5, 1, 3, 2};
    vector<int> res = farMin(arr);

    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}