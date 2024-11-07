#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> allPrimes(ll num)
{
    // Initialize array with 1's (assuming all numbers are prime)
    vector<ll> primeArr(num + 1, 1);
    primeArr[0] = primeArr[1] = 0; // 0 and 1 are not prime

    // Sieve of Eratosthenes to mark non-prime numbers
    for (ll i = 2; i * i <= num; i++)
    {
        if (primeArr[i])
        {
            for (ll j = i * i; j <= num; j += i)
            {
                primeArr[j] = 0; // Mark multiples of i as non-prime
            }
        }
    }

    // Create prefix sum array to count primes up to each index
    vector<ll> prefixPrimes(num + 1, 0);
    for (ll i = 1; i <= num; i++)
    {
        prefixPrimes[i] = primeArr[i] + prefixPrimes[i - 1];
    }

    return prefixPrimes;
}

int main()
{
    int n;
    cout << "Enter the number of queries: ";
    cin >> n;

    vector<pair<ll, ll>> queries(n);
    for (int i = 0; i < n; i++)
    {
        ll L, R;
        cout << "Enter the L: ";
        cin >> L;
        cout << "Enter the R: ";
        cin >> R;
        queries[i] = {L, R};
    }

    // Precompute prime counts up to 10^6 for efficient range queries
    vector<ll> primes = allPrimes(1e6);

    for (int i = 0; i < queries.size(); i++)
    {
        ll L = queries[i].first;
        ll R = queries[i].second;

        cout << "Total Primes between " << L << " and " << R << " are: ";
        ll ans = primes[R] - primes[L - 1];
        cout << ans << endl;
    }

    return 0;
}