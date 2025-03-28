/**
 *  @file: Fruit_Into_Baskets.cpp
 *  @author: Avinash Yadav
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        // Get the total number of trees
        int n = fruits.size();

        // Two pointers for the sliding window
        int left = 0, right = 0;

        // Variable to store the maximum length of valid subarray
        int maxLen = 0;

        // Map to store the count of each fruit type in the current window
        unordered_map<int, int> mpp;

        while (right < n)
        {
            // Add the fruit at 'right' to the basket
            mpp[fruits[right]]++;

            // If we have more than 2 types of fruits,
            // shrink the window from the left
            if (mpp.size() > 2)
            {
                // Reduce count of the leftmost fruit
                mpp[fruits[left]]--;

                if (mpp[fruits[left]] == 0)
                {
                    // Remove the fruit type if its count becomes zero
                    mpp.erase(fruits[left]);
                }

                // Move left pointer to shrink the window
                left++;
            }

            // Update the maximum length of the valid subarray
            // (only containing 2 types of fruits)
            maxLen = max(maxLen, right - left + 1);

            // Expand the window by moving 'right' forward
            right++;
        }

        return maxLen;
    }
};

int main()
{

    return 0;
}