#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to calculate the smallest prime factors for every number up to `num`
vector<ll> smallestPrimeFactors(ll num)
{
    // Initialize a vector to store smallest prime factors for each number
    vector<ll> primeArr(num + 1);

    // Initialize each number as its own smallest prime factor
    for (ll i = 2; i <= num; i++)
    {
        primeArr[i] = i;
    }

    // Set smallest prime factor for 1 as 1 (1 is neither prime nor composite)
    primeArr[1] = 1;

    // Use Sieve of Eratosthenes method to determine smallest prime factors
    for (ll i = 2; i * i <= num; i++)
    {
        // Check if `i` is prime
        if (primeArr[i] == i)
        {
            // Mark multiples of `i` with `i` as their smallest prime factor
            for (ll j = i * i; j <= num; j += i)
            {
                // Only update if it has not been marked by a smaller prime
                if (primeArr[j] == j)
                {
                    primeArr[j] = i;
                }
            }
        }
    }

    return primeArr;
}

int main()
{
    int n;
    cout << "Enter the number of queries: ";
    cin >> n;

    vector<ll> queries(n);

    // Variable to store the maximum value among all queries
    ll maxQuery = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of Query-" << i + 1 << ": ";
        cin >> queries[i];
        maxQuery = max(maxQuery, queries[i]);
    }

    // Precompute smallest prime factors up to the maximum query value
    // This ensures we compute smallest prime factors only once for all queries
    vector<ll> primes = smallestPrimeFactors(maxQuery);

    cout << "Smallest prime factors of the queries:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Query-" << i + 1 << " (" << queries[i] << "): " << primes[queries[i]] << endl;
    }

    return 0;
}
