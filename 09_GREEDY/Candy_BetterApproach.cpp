#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();

        // Edge case: No students, no candies required.
        if (n == 0)
            return 0;

        // Stores candy distribution from left to right
        vector<int> leftToRight(n, 1);

        // Left-to-right pass: Assign candies based on increasing ratings
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                leftToRight[i] = leftToRight[i - 1] + 1;
            }
        }

        // Right-to-left pass with space optimization (without extra array)
        int rightCandy = 1;

        // Initialize for last student
        int totalCandies = max(1, leftToRight[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                rightCandy++;
            }
            else
            {
                rightCandy = 1;
            }

            // Take the maximum of left-to-right and right-to-left computations
            totalCandies += max(leftToRight[i], rightCandy);
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
