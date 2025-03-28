#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        Approach 1: Brute Force (Nested Loops) - O(N²)

        - We check every possible pair of buy and sell days.
        - If the difference (profit) is greater than maxProfit, update maxProfit.
        - This approach is inefficient for large inputs
        - TLE in competitive programming.
    */
    int maxProfitBruteForce(vector<int> &prices)
    {
        int size = prices.size();
        int maxProfit = 0;

        for (int buyDay = 0; buyDay < size - 1; buyDay++)
        {
            for (int sellDay = buyDay + 1; sellDay < size; sellDay++)
            {
                maxProfit = max(maxProfit, prices[sellDay] - prices[buyDay]);
            }
        }
        return maxProfit;
    }

    /*
        Approach 2: Dynamic Programming (O(N) Time & O(N) Space)

        - We create an array maxSellPrice[] to store the maximum selling price from the right side.
        - Iterate from right to left and fill maxSellPrice[i] with the maximum value seen so far.
        - In another pass:
        -   We calculate the maxProfit by checking the difference of maxSellPrice[i] - prices[i].
    */
    int maxProfitDP(vector<int> &prices)
    {
        int size = prices.size();
        if (size == 0)
            return 0;

        vector<int> maxSellPrice(size, 0);
        maxSellPrice[size - 1] = prices[size - 1];

        for (int i = size - 2; i >= 0; i--)
        {
            maxSellPrice[i] = max(maxSellPrice[i + 1], prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i < size; i++)
        {
            maxProfit = max(maxProfit, maxSellPrice[i] - prices[i]);
        }

        return maxProfit;
    }

    /*
        Approach 3: Optimized Dynamic Programming (O(N) Time & O(1) Space)

        - We maintain two variables:
            1. minBuyPrice → The minimum price encountered so far.
            2. maxProfit → The maximum profit that can be achieved.
        - Iterate through prices and update minBuyPrice and maxProfit accordingly.
        - This approach uses constant space.
    */
    int maxProfitOptimizedDP(vector<int> &prices)
    {
        // Set initial min buy price to a very large number.
        int minBuyPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices)
        {
            // Update min buy price if a lower price is found.
            minBuyPrice = min(minBuyPrice, price);

            // Calculate and update max profit.
            maxProfit = max(maxProfit, price - minBuyPrice);
        }

        return maxProfit;
    }

    /*
        Approach 4: Two-Pointer (Sliding Window) - O(N) Time & O(1) Space

        - We use two pointers: `left` (buying day) and `right` (selling day).
        - If `prices[right] > prices[left]`, calculate profit and update maxProfit.
        - If `prices[right] < prices[left]`, move `left` to `right` (i.e., update buy day).
        - This approach is intuitive and also runs in O(N) time.
    */
    int maxProfitTwoPointer(vector<int> &prices)
    {
        // Buying day
        int left = 0;

        // Selling day
        int right = 1;

        int maxProfit = 0;

        while (right < prices.size())
        {
            if (prices[right] > prices[left])
            {
                // Calculate max profit.
                maxProfit = max(maxProfit, prices[right] - prices[left]);
            }
            else
            {
                // Move buy pointer if a lower price is found.
                left = right;
            }
            right++;
        }

        return maxProfit;
    }
};

int main()
{
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Brute Force: " << solution.maxProfitBruteForce(prices) << endl;
    cout << "Dynamic Programming (O(N) Space): " << solution.maxProfitDP(prices) << endl;
    cout << "Optimized DP (O(1) Space): " << solution.maxProfitOptimizedDP(prices) << endl;
    cout << "Two-Pointer Technique: " << solution.maxProfitTwoPointer(prices) << endl;

    return 0;
}
