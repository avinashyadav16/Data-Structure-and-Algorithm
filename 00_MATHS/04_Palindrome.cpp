#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool palindrome(int n)
{
    int original = n;
    int reverse = 0;

    while (n > 0)
    {

        reverse = (reverse * 10) + (n % 10);
        n /= 10;
    }

    return original == reverse;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (palindrome(num))
        cout << num << " is a palindrome." << endl;
    else
        cout << num << " is not a palindrome." << endl;

    return 0;
}
