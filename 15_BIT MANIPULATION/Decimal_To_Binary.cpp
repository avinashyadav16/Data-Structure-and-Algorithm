/**
 *  @file: Decimal_To_Binary.cpp
 *  @author: Avinash Yadav
 *  @brief: Convert the dei=cimal number to binary number.
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int number;
    cout << "Enter the number: ";
    cin >> number;

    int n = (int)(log2(number));

    cout << "The Binary Number Is : " << bitset<64>(number).to_string().substr(64 - n - 1);
}
