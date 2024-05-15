/**
 *  @file: Question_01_Knapsack.cpp
 *  @author: Avinash Yadav
 *  @brief: Provide the implementation of the problems such as 0/1 Knapsack
 *  @date: 12-04-2024
 */

#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> ZeroOneKnapsack(int bagCapacity, vector<int> &weights, vector<int> &profits)
{
    int weightSize = weights.size();
    vector<vector<int>> dp(weightSize + 1, vector<int>(bagCapacity + 1, 0));
    vector<vector<bool>> chosen(weightSize + 1, vector<bool>(bagCapacity + 1, false));

    for (int itemIndex = 1; itemIndex <= weightSize; ++itemIndex)
    {
        for (int currentCapacity = 1; currentCapacity <= bagCapacity; ++currentCapacity)
        {
            if (weights[itemIndex - 1] <= currentCapacity)
            {
                if (profits[itemIndex - 1] + dp[itemIndex - 1][currentCapacity - weights[itemIndex - 1]] > dp[itemIndex - 1][currentCapacity])
                {
                    dp[itemIndex][currentCapacity] = profits[itemIndex - 1] + dp[itemIndex - 1][currentCapacity - weights[itemIndex - 1]];
                    chosen[itemIndex][currentCapacity] = true;
                }
                else
                {
                    dp[itemIndex][currentCapacity] = dp[itemIndex - 1][currentCapacity];
                }
            }
            else
            {
                dp[itemIndex][currentCapacity] = dp[itemIndex - 1][currentCapacity];
            }
        }
    }

    int max_value = dp[weightSize][bagCapacity];
    vector<int> chosen_items;
    int currentCapacity = bagCapacity;

    for (int itemIndex = weightSize; itemIndex > 0 && max_value > 0; --itemIndex)
    {
        if (chosen[itemIndex][currentCapacity])
        {
            chosen_items.push_back(itemIndex - 1);
            max_value -= profits[itemIndex - 1];
            currentCapacity -= weights[itemIndex - 1];
        }
    }

    return {dp[weightSize][bagCapacity], chosen_items};
}

int main()
{
    vector<int> weights = {2, 3, 4, 5};
    vector<int> profits = {3, 4, 5, 6};
    int bagCapacity = 12;

    pair<int, vector<int>> result = ZeroOneKnapsack(bagCapacity, weights, profits);

    cout << "Maximum Profit: " << result.first << endl;

    cout << "Chosen Weights: ";
    for (int item : result.second)
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}