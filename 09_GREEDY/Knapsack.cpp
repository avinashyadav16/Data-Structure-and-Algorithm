#include <bits/stdc++.h>
using namespace std;

// Structure to represent an item with value and weight
struct Item
{
    int value, weight;
};

// Comparator function to sort items based on value-to-weight ratio
class Solution
{
public:
    static bool compareRatio(const Item &a, const Item &b)
    {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }

    // Function to get the maximum total value in the fractional knapsack
    double fractionalKnapsack(vector<int> &values, vector<int> &weights, int capacity)
    {
        int n = values.size();
        vector<Item> items;

        // Creating item list from values and weights
        for (int i = 0; i < n; i++)
        {
            items.push_back({values[i], weights[i]});
        }

        // Sort items by decreasing value-to-weight ratio
        sort(items.begin(), items.end(), compareRatio);

        // Stores the total value of knapsack
        double totalValue = 0.0;

        int remainingCapacity = capacity;

        // Iterate through sorted items
        for (const auto &item : items)
        {
            if (item.weight <= remainingCapacity)
            {
                // Take the whole item
                totalValue += item.value;
                remainingCapacity -= item.weight;
            }
            else
            {
                // Take the fractional part of the item
                totalValue += ((double)item.value / item.weight) * remainingCapacity;

                // Knapsack is full
                break;
            }
        }

        return totalValue;
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    cout << "Maximum value in Knapsack: " << sol.fractionalKnapsack(values, weights, capacity) << endl;
    return 0;
}
