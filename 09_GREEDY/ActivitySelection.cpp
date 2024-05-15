/**
 *  @file: ActivitySelection.cpp
 *  @author: Avinash Yadav

 *  @brief:
            Provide the implementation of the Activity Selection problem (greedy algorithm)
            Test your implementation with the following set of activities:
            Activity StartTime FinishTime
                1         1          4
                2         3          5
                3         0          6
                4         5          7
                5         3          8
                6         5          9
                7         6          10
                8         8          11
                9         8          12
                10        12         13
                11        12         14
            Determine and output the maximum number of activities
            that can be performed without any conflicts,
            along with the selected activities.

 *  @date: 15-03-2024
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Total number of activities
    int activities = 11;

    // Vector to store start times and finish times of activities
    vector<int> startTime = {1, 3, 0, 5, 3, 5, 6, 8, 8, 12, 12};
    vector<int> finishTime = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    // int activities = 6;
    // vector<int> startTime = {1, 3, 0, 5, 8, 5};
    // vector<int> finishTime = {2, 4, 6, 7, 9, 9};

    // Vector to store pairs of activity times (finish time, start time)
    vector<pair<int, int>> activityTimes;

    // Loop to populate activityTimes vector with pairs of finish and start times
    for (int i = 0; i < activities; ++i)
    {
        activityTimes.push_back({finishTime[i], startTime[i]});
    }

    // Sort the activityTimes vector based on finish times in ascending order
    sort(activityTimes.begin(), activityTimes.end());

    // Variable to store previous finish time
    int prevFinishTime = -1;

    cout << "Selected Activities are : ";

    // Loop to iterate through activityTimes vector and select activities
    for (int i = 0; i < activities; ++i)
    {
        // Find the index of the selected activity based on its start time
        int activityIndex = -1;
        for (int j = 0; j < activities; ++j)
        {
            if (startTime[j] == activityTimes[i].second)
            {
                activityIndex = j;
                break;
            }
        }

        // Check if the current activity's start time is after or equal to the previous finish time
        if (activityIndex != -1 && activityTimes[i].second >= prevFinishTime)
        {
            cout << activityIndex << " "; // Output the index of the selected activity
            // Update previous finish time
            prevFinishTime = activityTimes[i].first;
        }
    }
    return 0;
}