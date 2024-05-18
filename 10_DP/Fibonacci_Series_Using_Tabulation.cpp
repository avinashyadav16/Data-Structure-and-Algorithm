/**
 *  @file: Fibonacci_Series_Using_Tabulation.cpp
 *  @author: Avinash Yadav
 *  @brief: Fibonacci Series Using Tabulation

            Initialization:
            A vector table is initialized with 0s and the base case table[1] = 1.

            Iterative Computation:
            The table is filled iteratively from the bottom up, using the relation table[i] = table[i-1] + table[i-2].

            Final Result:
            The result is stored in table[n].

 *  @date: 18-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Tabulation function to compute Fibonacci
ll fibonacci_tabulation(int n)
{
    if (n <= 1)
        return n;

    // Initialize the table
    vector<ll> table(n + 1, 0);

    // Base case
    table[1] = 1;

    // Fill the table iteratively
    for (int i = 2; i <= n; ++i)
    {
        table[i] = table[i - 1] + table[i - 2];
    }

    return table[n];
}

int main()
{
    int n = 10;

    ll result = fibonacci_tabulation(n);
    
    cout << "Fibonacci number " << n << " is " << result << endl;

    return 0;
}