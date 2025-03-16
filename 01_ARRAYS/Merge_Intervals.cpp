/**
*  @file: Merge_Intervals.cpp
*  @author: Avinash Yadav
*  @brief:

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        // Edge case: If there are no intervals, return an empty vector
        if (n == 0)
        {
            return {};
        }

        // Step 1: Sort the intervals based on the starting time
        // Sorting ensures that overlapping intervals come next to each other
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged; // Vector to store the merged intervals

        // Step 2: Iterate through the intervals to merge overlapping ones
        for (int i = 0; i < n; i++)
        {
            // Extract the current interval's start and end times
            int start = intervals[i][0];
            int end = intervals[i][1];

            // If the merged list is not empty and the current interval is fully contained within
            // the last merged interval, we skip it as it's redundant
            if (!merged.empty() && end <= merged.back()[1])
            {
                continue; // Skip this interval as it's already covered
            }

            // Step 3: Check for overlapping intervals
            for (int j = i + 1; j < n; j++)
            {
                // If the next interval starts before or when the current one ends, they overlap
                if (intervals[j][0] <= end)
                {
                    // Extend the end time to merge the intervals
                    end = max(end, intervals[j][1]);
                }
                else
                {
                    // If no further overlapping intervals exist, stop checking
                    break;
                }
            }

            // Step 4: Add the merged interval to the result
            merged.push_back({start, end});
        }

        // Return the merged intervals
        return merged;
    }
};

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        // Edge case: If there are no intervals, return an empty vector
        if (n == 0)
            return {};

        // Step 1: Sort the intervals based on the starting value
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        // Step 2: Iterate through the sorted intervals to merge overlapping ones
        for (int i = 0; i < n; i++)
        {
            // If merged is empty OR no overlap, add new interval
            if (merged.empty() || intervals[i][0] > merged.back()[1])
            {
                merged.push_back(intervals[i]); // Push the new interval
            }
            else
            {
                // Merge overlapping intervals by updating the end time
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
        }

        return merged;
    }
};

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n == 0)
            return {}; // Edge case: Empty input

        // Step 1: Sort intervals based on the starting value
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged; // Stores merged intervals

        // Step 2: Initialize first interval
        int start = intervals[0][0];
        int end = intervals[0][1];

        // Step 3: Iterate through all intervals
        for (int i = 1; i < n; i++)
        {
            // If intervals overlap, merge them
            if (intervals[i][0] <= end)
            {
                // Overlapping intervals
                // Update end to merge
                end = max(end, intervals[i][1]);
            }
            else
            {
                // Push merged interval into result
                merged.push_back({start, end});

                // Move to the next interval
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // Step 4: Push the last interval
        merged.push_back({start, end});

        return merged;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result = sol.merge(intervals);

    // Print the merged intervals
    cout << "Merged Intervals: " << endl;
    for (auto interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
