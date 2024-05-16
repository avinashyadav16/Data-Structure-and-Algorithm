/**
 *  @file: Question_02_Coin_Change.cpp
 *  @author: Avinash Yadav
 *  @brief: Provide the implementation of the Coin Change using a greedy approach
 *  @date: 16-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to find the minimum number of coins using a greedy approach
int coinChangeGreedy(const vector<int> &coins, int amount)
{
    // Sort coins in descending order
    vector<int> sorted_coins = coins;
    sort(sorted_coins.rbegin(), sorted_coins.rend());

    int coin_count = 0;
    for (int coin : sorted_coins)
    {
        if (amount == 0)
        {
            break;
        }

        // Use as many of the current coin as possible
        coin_count += amount / coin;
        amount %= coin;
    }

    // If amount is not zero, it means we cannot make the amount with the given coins
    if (amount != 0)
    {
        return -1;
    }

    return coin_count;
}

int main()
{
    vector<int> coins = {1, 5, 10, 25};
    int amount = 63;

    cout << "==> Coin Change Problem <==" << endl;
    cout << "Coin Denominations Are: ";
    for (int coin : coins)
    {
        cout << coin << " ";
    }
    cout << endl;
    cout << "Required Amount: " << amount << endl;

    int result = coinChangeGreedy(coins, amount);

    if (result != -1)
    {
        cout << "Minimum coins needed: " << result << endl;
    }
    else
    {
        cout << "The amount cannot be made with the given coin denominations." << endl;
    }

    return 0;
}