#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Find all prime numbers up to 'n' using the Sieve of Eratosthenes
vector<int> findAllPrimes(int n)
{
    // Initialize a vector to track prime status of each number
    // Start by assuming all numbers are prime (1)
    vector<int> prime(n + 1, 1);

    // 0 and 1 are not prime numbers
    prime[0] = prime[1] = 0;

    // Apply the Sieve of Eratosthenes algorithm
    // Loop until the square root of n
    for (int i = 2; i * i <= n; ++i)
    {
        // Check if i is still marked as prime
        if (prime[i] == 1)
        {
            // Mark all multiples of i starting from i^2 as not prime
            for (int j = i * i; j <= n; j += i)
            {
                // Mark j as not prime
                prime[j] = 0;
            }
        }
    }

    // Collect all prime numbers
    vector<int> ans;

    for (int i = 2; i <= n; ++i)
    {
        // If i is marked as prime
        if (prime[i] == 1)
        {
            // Add i to the list of primes
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number (n) to find all primes up to: ";
    cin >> n;

    vector<int> primes = findAllPrimes(n);

    cout << "Prime numbers up to " << n << " are: ";
    for (int prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
