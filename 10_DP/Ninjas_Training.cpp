/**
*  @file: Ninja’s_Training.cpp
*  @author: Avinash Yadav
*  @date: 13-06-2025
*  @link: https://www.naukri.com/code360/problems/ninja%E2%80%99s-training_3621003?leftPanelTabValue=PROBLEM
*  @brief: Ninja is planing this ‘N’ days-long training schedule.
            Each day, he can perform any one of these three activities.
            (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day.
            As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days.
            Can you help Ninja find out the maximum merit points Ninja can earn?
            You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity.
            Your task is to calculate the maximum number of merit points that Ninja can earn.

            For Example
            If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
// Parameters:
//   day  - current day (0-based index)
//   last - the activity performed on the previous day
//       (0, 1, 2), or 3 if no activity was performed yet
//   points - 2D vector containing merit points for each activity on each day
class Solution1
{
public:
    int maxPoints(int day, int last, vector<vector<int>> &points)
    {
        // Initialize the maximum points to the smallest integer value
        int maxi = INT_MIN;

        // Base case:
        // If it's the first day,
        // choose the best activity except the one done last (if any)
        if (day == 0)
        {
            for (int task = 0; task < 3; task++)
            {
                // Ensure the activity is not the same as the last one
                if (task != last)
                {
                    // Update with the highest points for the first day
                    maxi = max(maxi, points[day][task]);
                }
            }

            // Return the maximum points for the first day
            return maxi;
        }

        // Recursive case:
        // For each possible activity, except the one done last,
        // calculate the points earned
        // by doing that activity today plus the best result from previous days
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                // Recursively calculate the points for the previous day,
                // with the current task as the last activity
                int currPoint = points[day][task] + maxPoints(day - 1, task, points);

                // Update maxi if this choice yields more points
                maxi = max(maxi, currPoint);
            }
        }

        // Return the maximum points achievable up to this day
        return maxi;
    }

    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        return maxPoints(n - 1, 3, points);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
// Function to compute the maximum points Ninja can earn up to a given day
// Parameters:
//   day   - current day (0-based index)
//   last  - the activity performed on the previous day
//           (0, 1, 2), or 3 if no activity was performed yet
//   points- 2D vector containing merit points for each activity on each day
//   dp    - 2D vector for memoization,
//           where dp[day][last] stores the result for a given day and last activity
class Solution2
{
public:
    int maxPoints(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        // Initialize the maximum points to the smallest integer value
        int maxi = INT_MIN;

        // Base case:
        // If it's the first day,
        // choose the best activity except the one done last (if any)
        if (day == 0)
        {
            for (int task = 0; task < 3; task++)
            {
                // Ensure the activity is not the same as the last one
                if (task != last)
                {
                    // Update with the highest points for the first day
                    maxi = max(maxi, points[day][task]);
                }
            }
            // Return the maximum points for the first day
            return maxi;
        }

        // If the result for this state has already been computed,
        // return it to avoid recomputation
        if (dp[day][last] != -1)
        {
            return dp[day][last];
        }

        // Try all possible activities for the current day except the one done last
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                // Recursively calculate the points for the previous day,
                // with the current task as the last activity
                int currPoint = points[day][task] + maxPoints(day - 1, task, points, dp);

                // Update maxi if this choice yields more points
                maxi = max(maxi, currPoint);
            }
        }

        // Store the computed result in dp table and return it
        return dp[day][last] = maxi;
    }

    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        // dp[i][j] will store the maximum points up to day i with last activity j
        // Initialize all values to -1 (uncomputed)
        vector<vector<int>> dp(n, vector<int>(4, -1));

        // Start the recursion from the last day,
        // with '3' as last (meaning no activity restriction)
        maxPoints(n - 1, 3, points, dp);

        // The answer is stored in dp[n-1][3]
        return dp[n - 1][3];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        // dp[day][last]:
        //      Max points up to 'day' if last task done was 'last'
        // last = 0,1,2 for tasks,
        //       3 means no task restriction (used for initialization)
        vector<vector<int>> dp(n, vector<int>(4, -1));

        // Base case:
        // On day 0, if last task was 'last',
        // pick the best among the other two tasks

        // Last task was 0, so pick max of 1 or 2
        dp[0][0] = max(points[0][1], points[0][2]);

        // Last task was 1, so pick max of 0 or 2
        dp[0][1] = max(points[0][0], points[0][2]);

        // Last task was 2, so pick max of 0 or 1
        dp[0][2] = max(points[0][0], points[0][1]);

        // No last task, pick max of all
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        // Fill the dp table for each day
        for (int day = 1; day < n; day++)
        {
            // For each possible last task
            for (int last = 0; last < 4; last++)
            {
                // Initialize for this state
                dp[day][last] = 0;

                // Try all tasks for today
                for (int task = 0; task < 3; task++)
                {
                    // Can't do the same task as yesterday
                    if (task != last)
                    {
                        // Calculate current points:
                        //       today's task points + best from previous day
                        int currPts = points[day][task] + dp[day - 1][task];

                        // Update dp for the best option
                        dp[day][last] = max(dp[day][last], currPts);
                    }
                }
            }
        }

        // The answer is the max points on the last day
        // with no restriction on previous task
        return dp[n - 1][3];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
// This approach reduces the space complexity from O(N*4) to O(4)
// by only keeping track of the previous day's results,
// since each day's result only depends on the previous day.

class Solution4
{
public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        // prevDP[last]:
        //   stores the max points up to previous day
        //    with 'last' as the last activity
        // last = 0,1,2 for tasks,
        // 3 means no restriction (used for initialization)
        vector<int> prevDP(4, -1);

        // Base case:
        // On day 0, if last activity was 'last',
        // pick the best among the other two tasks

        // Last was 0, pick max of 1 or 2
        prevDP[0] = max(points[0][1], points[0][2]);

        // Last was 1, pick max of 0 or 2
        prevDP[1] = max(points[0][0], points[0][2]);

        // Last was 2, pick max of 0 or 1
        prevDP[2] = max(points[0][0], points[0][1]);

        // No last, pick max of all
        prevDP[3] = max(points[0][0], max(points[0][1], points[0][2]));

        // Iterate over each day starting from day 1
        for (int day = 1; day < n; day++)
        {
            // tempDP will store the results for the current day
            vector<int> tempDP(4, 0);

            // For each possible last activity
            for (int last = 0; last < 4; last++)
            {
                tempDP[last] = 0;

                // Try all tasks for today
                for (int task = 0; task < 3; task++)
                {
                    // Can't do the same task as yesterday
                    if (task != last)
                    {
                        // Calculate current points:
                        // today's task points + best from previous day
                        // with 'task' as last
                        int currPts = points[day][task] + prevDP[task];

                        // Update tempDP for the best option
                        tempDP[last] = max(tempDP[last], currPts);
                    }
                }
            }

            // Update prevDP for the next iteration (next day)
            prevDP = tempDP;
        }

        // The answer is the max points on the last day
        // with no restriction on previous task
        return prevDP[3];
    }
};

int main()
{

    int n1 = 3;
    vector<vector<int>> points1 = {{18, 11, 19}, {4, 13, 7}, {1, 8, 13}}; // 45

    int n2 = 2;
    vector<vector<int>> points2 = {{10, 50, 1}, {5, 100, 11}}; // 110

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.ninjaTraining(n1, points1) << endl;
    cout << sol1.ninjaTraining(n2, points2) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.ninjaTraining(n1, points1) << endl;
    cout << sol2.ninjaTraining(n2, points2) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.ninjaTraining(n1, points1) << endl;
    cout << sol3.ninjaTraining(n2, points2) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.ninjaTraining(n1, points1) << endl;
    cout << sol4.ninjaTraining(n2, points2) << endl;

    return 0;
}