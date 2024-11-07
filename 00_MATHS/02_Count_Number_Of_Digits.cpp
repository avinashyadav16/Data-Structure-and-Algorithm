#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// log10(45) = 1.6     => 1 + 1 = 2
// log10(382) = 2.5    => 2 + 1 = 3
// log10(4774) = 3.6   => 3 + 1 = 4
// log10(67698) = 4.8  => 4 + 1 = 5

// Function to count digits in a given number
int countDigits(int n)
{
    // Edge case for zero, as log10(0) is undefined
    // 0 has 1 digit
    if (n == 0)
        return 1;

    return (int)log10(n) + 1;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Number of digits: " << countDigits(n) << endl;

    return 0;
}
