/**
*  @author: Avinash Yadav
*  @link: https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
*  @brief: Given a binary array arr[] containing only 0s and 1s and an integer k,
            you are allowed to flip at most k 0s to 1s.
            Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.

            Examples:
            Input: arr[] = [1, 0, 1], k = 1
            Output: 3
            Explanation: By flipping the zero at index 1, we get the longest subarray from index 0 to 2 containing all 1’s.

            Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
            Output: 5
            Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.

            Input: arr[] = [1, 1], k = 2
            Output: 2
            Explanation: Since the array is already having the max consecutive 1's, hence we dont need to perform any operation.
            Hence the answer is 2.

*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxOnes(vector<int> &arr, int k)
    {
        int n = arr.size();

        int left = 0;
        int right = 0;

        int zeroCount = 0;
        int maxConOne = 0;

        while (right < n)
        {
            if (arr[right] == 0)
            {
                zeroCount++;
            }

            while (zeroCount > k)
            {
                if (arr[left] == 0)
                {
                    zeroCount--;
                }

                left++;
            }

            maxConOne = max(maxConOne, right - left + 1);
            right++;
        }

        return maxConOne;
    }
};
