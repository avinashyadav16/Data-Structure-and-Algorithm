#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> primeFactors(int num)
{
    vector<int> prime;

    // Loop through possible factors starting from 2
    for (int i = 2; i * i <= num; i++)
    {
        // Found a prime factor
        if (num % i == 0)
        {
            prime.push_back(i);

            // Removing all occurrences of this prime factor
            while (num % i == 0)
            {
                num /= i;
            }
        }
    }

    // After you have divided num by all of its smaller prime factors,
    // if num is still greater than 1, it means that what remains is a prime number itself.
    // This situation arises when the original number is a prime number greater than sqrt(num)
    // (e.g., for num = 29, it wouldn't be divisible by any number less than 6, so after the loop, num would still be 29).

    if (num > 1)
    {
        prime.push_back(num);
    }

    return prime;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    vector<int> factors = primeFactors(num);

    cout << "Prime factors of " << num << " are: ";
    for (int factor : factors)
    {
        cout << factor << " ";
    }

    return 0;
}
