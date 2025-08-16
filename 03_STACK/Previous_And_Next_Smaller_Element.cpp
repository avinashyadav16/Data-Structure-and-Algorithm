/**
*  @file: Previous_And_Next_Smaller_Element.cpp
*  @author: Avinash Yadav
*  @date: 12-08-2025
*  @link: https://takeuforward.org/plus/dsa/problems/next-smaller-element
*  @brief: Given an array of integers arr, your task is to find the Previous And Next Smaller Element (PSE & NSE) for every element in the array.
            The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.
            If there is no smaller element to the right, then the NSE is -1.
            Examples:
                Input: arr = [4, 8, 5, 2, 25]
                Output: [2, 5, 2, -1, -1]
                Explanation:
                - For 4, the next smaller element is 2.
                - For 8, the next smaller element is 5.
                - For 5, the next smaller element is 2.
                - For 2, there is no smaller element to its right → -1.
                - For 25, no smaller element exists → -1.

                Input: arr = [10, 9, 8, 7]
                Output: [9, 8, 7, -1]
                Explanation:
                    Each element’s next right neighbor is smaller.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    vector<int> previousSmallerElements(const vector<int> &arr)
    {
        int n = arr.size();
        vector<int> PSE(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() >= arr[i])
            {
                st.pop();
            }

            PSE[i] = st.empty() ? -1 : st.top();

            st.push(arr[i]);
        }

        return PSE;
    }
};

class Solution2
{
public:
    vector<int> nextSmallerElements(const vector<int> &arr)
    {
        int n = arr.size();
        vector<int> NSE(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() >= arr[i])
            {
                st.pop();
            }

            NSE[i] = st.empty() ? -1 : st.top();

            st.push(arr[i]);
        }

        return NSE;
    }
};

int main()
{
    Solution1 sol1;
    vector<int> arr1 = {4, 8, 5, 2, 25}; // OUTPUT: [-1, 4, 4, -1, 2]
    vector<int> ans1 = sol1.previousSmallerElements(arr1);
    for (auto &num : ans1)
    {
        cout << num << " ";
    }
    cout << endl;

    Solution2 sol2;
    vector<int> arr2 = {10, 9, 8, 7}; // OUTPUT: [9, 8, 7, -1]
    vector<int> ans2 = sol2.nextSmallerElements(arr2);
    for (auto &num : ans2)
    {
        cout << num << " ";
    }

    return 0;
}