#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{

    int num;

    cout << "Enter a number: ";
    cin >> num;

    vector<int> digits;

    cout << "Digits of " << num << " are: ";

    while (num > 0)
    {

        int digit = num % 10;

        digits.push_back(digit);

        cout << digit << " ";

        num /= 10;
    }

    cout << endl;

    cout << "Digits of the number in the same order: ";
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        cout << digits[i] << " ";
    }

    return 0;
}
