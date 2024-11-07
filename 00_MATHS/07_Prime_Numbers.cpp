#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string isPrime(int num)
{
    if (num <= 1)
    {
        return "false";
    }

    // Check divisibility from 2 to sqrt(num)
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return "false";
        }
    }

    return "true";
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << num << " is prime: " << isPrime(num) << endl;

    return 0;
}
