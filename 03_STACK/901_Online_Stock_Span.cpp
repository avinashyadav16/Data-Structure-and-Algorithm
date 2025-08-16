/**
*  @file: 901_Online_Stock_Span.cpp
*  @author: Avinash Yadav
*  @date: 15-08-2025
*  @link: https://leetcode.com/problems/online-stock-span/description/
*  @brief: Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
           The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward)
           for which the stock price was less than or equal to the price of that day.
           For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2,
           then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
           Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8,
           then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.

            Implement the StockSpanner class:
                StockSpanner() Initializes the object of the class.
                int next(int price) Returns the span of the stock's price given that today's price is price.

            Example 1:
                Input
                    ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
                    [[], [100], [80], [60], [70], [60], [75], [85]]
                Output
                    [null, 1, 1, 1, 2, 1, 4, 6]

                Explanation
                    StockSpanner stockSpanner = new StockSpanner();
                    stockSpanner.next(100); // return 1
                    stockSpanner.next(80);  // return 1
                    stockSpanner.next(60);  // return 1
                    stockSpanner.next(70);  // return 2
                    stockSpanner.next(60);  // return 1
                    stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75)
                                            // were less than or equal to today's price.
                    stockSpanner.next(85);  // return 6

*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// METHOD - 01
class StockSpanner1
{
public:
    vector<int> dArray;
    StockSpanner1()
    {
        dArray.clear();
    }

    int next(int price)
    {
        dArray.push_back(price);

        int cnt = 1;

        for (int i = dArray.size() - 2; i >= 0; i--)
        {
            if (dArray[i] <= price)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }

        return cnt;
    }
};

// METHOD - 02

class StockSpanner2
{
public:
    // Stack stores pairs: {price, index}
    // Maintains a decreasing sequence of prices
    stack<pair<int, int>> st;

    // Tracks the current day (0-based index)
    int index = -1;

    // Constructor initializes the spanner
    StockSpanner2() {}

    // Returns the stock span for the given price
    int next(int price)
    {
        // Move to the next day
        index = index + 1;

        // Pop prices from the stack that are
        // less than or equal to current price
        // This ensures only higher prices remain,
        // which are relevant for span calculation
        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }

        // If stack is empty,
        // all previous prices are less than current
        // Span is index + 1 (all days so far)
        // Otherwise, span is difference between
        // current index and index of last higher price
        int span = index - (st.empty() ? -1 : st.top().second);

        // Push current price and index onto the stack
        st.push({price, index});

        // Return the calculated span
        return span;
    }
};