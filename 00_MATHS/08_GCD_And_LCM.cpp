/*
    A * B = LCM(A, B) * GCD(A, B)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// GCD using the Euclidean algorithm
int gcd(int a, int b)
{

    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }

    if (a > b)
    {
        return gcd(a % b, b);
    }
    else
    {
        return gcd(a, b % a);
    }
}

// Simplified Version:
int simplifiedGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << endl;

    cout << "LCM of " << num1 << " and " << num2 << " is: " << lcm(num1, num2) << endl;

    return 0;
}
