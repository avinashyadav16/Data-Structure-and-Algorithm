/**
 *  @file: 08_Radix_Sort.cpp
 *  @author: Avinash Yadav
 *  @brief: Radix Sort is a linear sorting algorithm that sorts elements by processing them digit by digit.
            It is an efficient sorting algorithm for integers or strings with fixed-size keys.
            The key idea behind Radix Sort is to exploit the concept of place value.
            It assumes that sorting numbers digit by digit will eventually result in a fully sorted list.
            Radix Sort can be performed using different variations,
            such as Least Significant Digit (LSD) Radix Sort or Most Significant Digit (MSD) Radix Sort.
 *  @date: 18-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// A function to do counting sort of arr[]
// according to the digit represented by exp.
void countSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i]
    // so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[],
    // so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixsort(vector<int> &arr)
{
    // Find the maximum number to know number of digits
    int maxVal = *max_element(arr.begin(), arr.end());

    // Do counting sort for every digit.
    // Note that instead of passing digit number, exp is passed.
    // exp is 10^i where i is current digit number
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(arr, exp);
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixsort(arr);

    cout << "Sorted Array is: " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}