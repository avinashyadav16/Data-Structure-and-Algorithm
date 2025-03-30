/**
 *  @file: Koko_Eating_Banana.cpp
 *  @author: Avinash Yadav
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    // Function to calculate total hours required for a given eating speed
    int calculateHours(vector<int> &piles, int eatingSpeed)
    {
        // Track total hours needed
        int totalHrs = 0;

        for (int i = 0; i < piles.size(); i++)
        {
            // Compute hours needed to finish the current pile
            totalHrs += ceil((double)piles[i] / (double)eatingSpeed);
        }

        // Return total hours required
        return totalHrs;
    }

    // Function to find the minimum eating speed using Binary Search
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // Minimum possible speed (at least 1 banana per hour)
        int low = 1;

        // Maximum speed (largest pile size)
        int high = *max_element(piles.begin(), piles.end());

        // Perform Binary Search
        while (low < high)
        {
            // Middle speed to check
            int mid = (low + high) / 2;

            // Get required hours for this speed
            int reqHrs = calculateHours(piles, mid);

            if (reqHrs <= h)
            {
                // If we can finish in <= h, try a lower speed (optimize)
                high = mid;
            }
            else
            {
                // If we need more hours, increase the speed
                low = mid + 1;
            }
        }

        // Minimum eating speed that meets the condition
        return low;
    }
};

int main()
{
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum Eating Speed: " << result << endl; // Expected Output: 4

    return 0;
}