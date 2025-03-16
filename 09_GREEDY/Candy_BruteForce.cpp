#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();

        // Edge case: No children, no candies needed
        if (n == 0)
            return 0;

        // Stores candies distribution from left to right
        vector<int> leftToRight(n, 1);

        // Stores candies distribution from right to left
        vector<int> rightToLeft(n, 1);

        // Left-to-right pass: Ensuring increasing ratings get more candies
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                leftToRight[i] = leftToRight[i - 1] + 1;
            }
        }

        // Right-to-left pass: Ensuring decreasing ratings get more candies
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                rightToLeft[i] = rightToLeft[i + 1] + 1;
            }
        }

        // Calculate the minimum candies required
        int minCandies = 0;
        for (int i = 0; i < n; i++)
        {
            // Take max candies needed at each index
            minCandies += max(leftToRight[i], rightToLeft[i]);
        }

        return minCandies;
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> ratings = {1, 0, 2};
    cout << "Minimum candies required: " << sol.candy(ratings) << endl;

    return 0;
}
