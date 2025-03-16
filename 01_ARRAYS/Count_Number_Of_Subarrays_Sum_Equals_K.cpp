#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    // Map to store frequency of prefix sums
    unordered_map<int, int> prefixSumCount;

    // Base case: prefix sum of 0 appears once
    prefixSumCount[0] = 1;

    int current_sum = 0, count = 0;

    for (int num : nums)
    {
        // Update running sum
        current_sum += num;

        // Check if a subarray sum (current_sum - k) exists
        if (prefixSumCount.find(current_sum - k) != prefixSumCount.end())
        {
            count += prefixSumCount[current_sum - k];
        }

        // Store the current prefix sum in the map
        prefixSumCount[current_sum]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << "Count of subarrays: " << subarraySum(nums, k) << endl; // Output: 2
    return 0;
}