/**
 *  @file: Fractional_Knapsack.cpp
 *  @author: Avinash Yadav
 *  @brief: Implementation of the Fractional Knapsack Problem using the Greedy algorithm
 *  @date: 09-05-2024
 */

#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(int bagCapacity, vector<pair<int, int>> &knapsack, int totalItems)
{
    // Sorting items based on profit per unit weight ratio in decreasing order
    sort(knapsack.begin(), knapsack.end(),
         [](const pair<int, int> &a, const pair<int, int> &b)
         {
             double ratioA = static_cast<double>(a.first) / a.second;
             double ratioB = static_cast<double>(b.first) / b.second;
             return ratioA > ratioB;
         });

    double maxProfit = 0.0;

    for (int i = 0; i < totalItems; i++)
    {
        // knapsack's weight   <= bagCapacity
        if (knapsack[i].second <= bagCapacity)
        {
            bagCapacity -= knapsack[i].second;
            maxProfit += knapsack[i].first;
        }
        else
        {
            maxProfit += knapsack[i].first * ((double)bagCapacity / (double)knapsack[i].second);
            break;
        }
    }
    return maxProfit;
}

// Driver code
int main()
{
    // Total capacity of the knapsack
    int bagCapacity = 50;

    // Number of items
    int totalItems = 3;

    // List of items {profit, weight}
    vector<pair<int, int>> knapsack = {{60, 10}, {100, 20}, {120, 30}};

    // Output the maximum profit
    cout << "The maximum profit is: " << fractionalKnapsack(bagCapacity, knapsack, totalItems);
    return 0;
}