#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int rev = 0;
    while (num > 0)
    {

        // Extracting and adding last digit to rev
        rev = (rev * 10) + (num % 10);

        // Removing the last digit from num
        num /= 10;
    }

    cout << rev << endl;

    return 0;
}
