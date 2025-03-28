/**
 *  @file: Maximum_Points_You_Can_Obtain_From_Cards.cpp
 *  @author: Avinash Yadav
 *  @brief: This program calculates the maximum points one can obtain
 *          from a given set of card points by picking exactly k cards
 *          from either the beginning or the end of the array.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        // Sum of first k elements from the left
        int leftSum = 0;

        // Sum of elements picked from the right
        int rightSum = 0;

        // Maximum points that can be obtained
        int maxPoints = 0;

        int totalCards = cardPoints.size();

        // Calculate initial sum by picking the first k cards from the left
        for (int i = 0; i < k; i++)
        {
            leftSum += cardPoints[i];
        }

        // Initially, the maximum sum is the leftSum
        maxPoints = leftSum;

        // Start picking from the right end
        int rightIndex = totalCards - 1;

        // Try replacing leftmost cards with rightmost cards to maximize the sum
        for (int i = k - 1; i >= 0; i--)
        {
            // Remove the leftmost card from the sum
            leftSum -= cardPoints[i];

            // Add the rightmost card to the sum
            rightSum += cardPoints[rightIndex];

            // Update maxPoints with the best possible score
            maxPoints = max(maxPoints, (leftSum + rightSum));

            // Move towards the left in the right section
            rightIndex--;
        }

        // Return the maximum points obtained
        return maxPoints;
    }
};

int main()
{
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    Solution sol;
    cout << "Maximum Points: " << sol.maxScore(cardPoints, k) << endl;

    return 0;
}
