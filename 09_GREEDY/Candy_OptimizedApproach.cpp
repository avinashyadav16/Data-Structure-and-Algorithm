#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();

        // Edge case: Single student
        if (n == 1)
            return 1;

        // Every student gets at least one candy
        int totalCandies = n;
        int i = 1;

        while (i < n)
        {
            if (ratings[i] == ratings[i - 1])
            {
                // Equal ratings, no additional candy needed
                i++;
                continue;
            }

            // Increasing Slope (i.e., ratings[i] > ratings[i-1])
            int upSlope = 0;
            while (i < n && ratings[i] > ratings[i - 1])
            {
                // Candies should increase
                upSlope++;
                totalCandies += upSlope;
                i++;

                // If we reach the last element, return totalCandies
                if (i == n)
                    return totalCandies;
            }

            // Decreasing Slope (i.e., ratings[i] < ratings[i-1])
            int downSlope = 0;
            while (i < n && ratings[i] < ratings[i - 1])
            {
                // Candies should decrease
                downSlope++;
                totalCandies += downSlope;
                i++;
            }

            // Adjust for Peak Overcounting
            totalCandies -= min(upSlope, downSlope);
        }

        return totalCandies;
    }
};

int main()
{
    Solution sol;
    vector<int> ratings = {1, 0, 2};
    cout << "Minimum candies required: " << sol.candy(ratings) << endl;
    return 0;
}
