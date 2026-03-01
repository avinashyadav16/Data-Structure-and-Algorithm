/**
 *  @file: Subarray_Sum_Equals_K.cpp
 *  @author: Avinash Yadav
 *  @brief: This program finds the number of subarrays with a given sum 'k'.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; 

// Find all subarrays with a given sum 'k'
int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    // Hash map to store prefix sums and their frequencies
    unordered_map<int, int> mpp;

    // Variable to store the running prefix sum
    int preSum = 0;

    // Counter to store the number of subarrays with sum 'k'
    int cnt = 0;

    // Initialize the map with prefix sum 0 having frequency 1
    mpp[0] = 1;

    // Iterate through the array
    for (int i = 0; i < arr.size(); i++)
    {
        // Add the current element to the prefix sum
        preSum += arr[i];

        // Calculate the required prefix sum to form a subarray with sum 'k'
        int toRemoved = preSum - k;

        // Add the frequency of the required prefix sum to the counter
        cnt += mpp[toRemoved];

        // Increment the frequency of the current prefix sum in the map
        mpp[preSum] += 1;
    }

    // Return the total count of subarrays with sum 'k'
    return cnt;
}

// Class to encapsulate the solution for finding subarray sums
class Solution
{
public:
    // Function to find the number of subarrays with sum equal to 'k'
    int subarraySum(vector<int> &nums, int k)
    {
        // Variable to store the running sum
        int sum = 0;
        // Counter to store the number of subarrays with sum 'k'
        int cnt = 0;
        // Hash map to store prefix sums and their frequencies
        unordered_map<int, int> map;

        // Initialize the map with prefix sum 0 having frequency 1
        map[0] = 1;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {
            // Add the current element to the running sum
            sum += nums[i];

            // Check if the required prefix sum exists in the map
            if (map.find(sum - k) != map.end())
            {
                // Add the frequency of the required prefix sum to the counter
                cnt += map[sum - k];
            }

            // Increment the frequency of the current prefix sum in the map
            map[sum]++;
        }

        // Return the total count of subarrays with sum 'k'
        return cnt;
    }
};
