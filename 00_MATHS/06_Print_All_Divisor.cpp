#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> printDivisors(int n)
{
    vector<int> result;

    // Loop to find divisors from 1 to sqrt(n)
    for (int i = 1; i <= sqrt(n); i++)
    {
        // If i is a divisor of n
        if (n % i == 0)
        {
            result.push_back(i);

            // Check to avoid adding the square root twice
            // If i is not equal to n / i, add n / i as well
            if (i != n / i)
            {
                result.push_back(n / i);
            }
        }
    }

    // Sorting divisors in ascending order
    sort(result.begin(), result.end());

    return result;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    vector<int> divisors = printDivisors(num);

    cout << "Divisors of " << num << " are: ";
    for (int i : divisors)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
