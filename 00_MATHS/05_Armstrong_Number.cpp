#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool checkArmstrong(int n)
{

    int digits = (int)log10(n) + 1;
    int original = n;

    int newNum = 0;

    while (n > 0)
    {
        newNum += pow((n % 10), digits);
        n /= 10;
    }

    return original == newNum;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (checkArmstrong(num))
        cout << num << " is an Armstrong number." << endl;
    else
        cout << num << " is not an Armstrong number." << endl;

    return 0;
}
