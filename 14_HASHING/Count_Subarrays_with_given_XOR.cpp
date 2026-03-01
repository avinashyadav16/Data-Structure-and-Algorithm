/**
*  @file: Count_Subarrays_with_given_XOR.cpp
*  @author: Avinash Yadav
*  @date: 17-08-2025
*  @link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
*  @brief: Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.
            Examples:
                Input: arr[] = [4, 2, 2, 6, 4], k = 6
                Output: 4
                Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6].
                            Hence, the answer is 4.

                Input: arr[] = [5, 6, 7, 8, 9], k = 5
                Output: 2
                Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9].
                            Hence, the answer is 2.

                Input: arr[] = [1, 1, 1, 1], k = 0
                Output: 4
                Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        int n = arr.size();

        // Stores the prefix XOR up to current index
        int currXor = 0;

        // Stores the count of subarrays with XOR equal to k
        int cnt = 0;

        // Hash map to store frequency of prefix XORs
        unordered_map<int, int> xorFreqMpp;

        // Traverse the array
        for (int i = 0; i < n; i++)
        {
            // Update the prefix XOR
            currXor ^= arr[i];

            // If the current prefix XOR is equal to k,
            // increment count
            if (currXor == k)
            {
                cnt++;
            }

            // If there exists a prefix XOR such that
            // (currXor ^ k) has occurred before,
            // it means the subarray between
            // that previous index and current index has XOR equal to k.
            if (xorFreqMpp.find(currXor ^ k) != xorFreqMpp.end())
            {
                cnt += xorFreqMpp[currXor ^ k];
            }

            // Store/update the frequency of current prefix XOR
            xorFreqMpp[currXor] += 1;
        }

        // Return the total count of subarrays with XOR equal to k
        return cnt;
    }
};
