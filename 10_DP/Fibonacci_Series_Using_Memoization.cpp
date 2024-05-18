/**
 *  @file: Fibonacci_Series_Using_Memoization.cpp
 *  @author: Avinash Yadav
 *  @brief: Fibonacci Series Using Memoization

            Initialization:
            A vector memo is initialized with -1 to indicate uncomputed Fibonacci values.

            Base Case:
            If n is 0 or 1, the function returns n.

            Recursive Case:
            If the result for n is already computed (memo[n] != -1), it returns the cached result.
            Otherwise, it computes the result recursively and stores it in the memo vector.

 *  @date: 18-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Memoization function to compute Fibonacci
ll fibonacci_memoization(int n, vector<ll> &memo)
{
    if (n <= 1)
        return n;

    // Return cached result if available
    if (memo[n] != -1)
        return memo[n];

    // Compute and cache the result
    memo[n] = fibonacci_memoization(n - 1, memo) + fibonacci_memoization(n - 2, memo);
    
    return memo[n];
}

int main()
{
    int n = 10;

    // Initialize memoization vector with -1
    vector<ll> memo(n + 1, -1);

    ll result = fibonacci_memoization(n, memo);

    cout << "Fibonacci number " << n << " is " << result << endl;

    return 0;
}