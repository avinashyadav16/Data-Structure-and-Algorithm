#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

double myPow(double x, int n)
{
    // Initialize the result in the case of double input
    double ans = 1.0;

    // If the base is 0 or 1
    if (x == 0 || x == 1)
    {
        return x;
    }

    // Handle negative exponents by making 'x' its reciprocal and 'n' positive
    bool isNegative = (n < 0);
    if (isNegative)
    {
        x = 1 / x;

        // Note: this works as long as `n` is not INT_MIN
        n = -(n);
    }

    // Loop to compute the result iteratively
    while (n > 0)
    {
        // If 'n' is odd, multiply 'ans' by 'x' and decrement 'n' by 1
        if (n % 2 == 1)
        {
            ans *= x;
            n -= 1;
        }
        // If 'n' is even, divide 'n' by 2 and multiply 'x' by itself
        else
        {
            x *= x;
            n /= 2;
        }
    }

    return ans;
}

int main()
{
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    double result = myPow(x, n);

    cout << "Result: " << x << "^" << n << " = " << result << endl;

    return 0;
}
