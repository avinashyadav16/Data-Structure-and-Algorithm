/**
*  @file: Minimum_Operations_to_Transform_Array_Elements.cpp
*  @author: Avinash Yadav
*  @brief: You are given an array b of n integers.
            For each element in the array, you can perform the following operation:
            Increase or decrease the element to match a given target value at a cost equal to the absolute difference between the element and the target.

            You are also given q queries.
            In each query, you will be given a target value.
            Your task is to determine the minimum total cost required to make all elements in the array equal to this target value.
*  @date: 18-10-2024
*/

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;

// int main()
// {
//     ll n;
//     cin >> n;

//     // Array to store the elements
//     vector<ll> elements(n + 1);

//     // Prefix sum array
//     vector<ll> prefixSum(n + 1, 0);

//     ll totalSum = 0;

//     // Setting a very low sentinel value
//     elements[0] = -1e18;

//     // Setting a very high sentinel value
//     elements[n + 1] = 1e18;

//     // Input array elements and calculate total sum
//     for (ll i = 1; i <= n; i++)
//     {
//         cin >> elements[i];
//         totalSum += elements[i];
//     }

//     // Sort the elements for binary search
//     sort(elements.begin() + 1, elements.begin() + n + 1);

//     // Calculate prefix sums
//     for (ll i = 1; i <= n; i++)
//     {
//         prefixSum[i] = elements[i] + prefixSum[i - 1];
//     }

//     // Process each query
//     ll numQueries;
//     cin >> numQueries;
//     while (numQueries--)
//     {
//         ll targetValue;
//         cin >> targetValue;

//         // Binary search to find the largest element <= targetValue
//         ll low = 1, high = n, lastIndex = 0;

//         while (low <= high)
//         {
//             ll mid = (low + high) / 2;
//             if (elements[mid] <= targetValue)
//             {
//                 lastIndex = mid;
//                 low = mid + 1;
//             }
//             else
//             {
//                 high = mid - 1;
//             }
//         }

//         // Calculate operations required for the left part and the right part
//         ll leftOperations = targetValue * lastIndex - prefixSum[lastIndex];
//         ll rightOperations = (totalSum - prefixSum[lastIndex]) - targetValue * (n - lastIndex);

//         // Output the total number of operations needed to match targetValue
//         cout << leftOperations + rightOperations << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to find the largest index of an element in a sorted vector that is <= target
ll getLastIndex(const vector<ll> &elements, ll target)
{
    // `upper_bound` returns an iterator to the first element greater than `target`
    auto upperIt = upper_bound(elements.begin(), elements.end(), target);

    // The index of the last element <= `target` is one position before `upperIt`
    ll lastIndex = upperIt - elements.begin() - 1;

    // Return the calculated index
    return lastIndex;
}

int main()
{
    // Input the number of elements in the array
    ll n;
    cin >> n;

    // Array to store the elements (with two extra bounds)
    vector<ll> elements(n + 2);

    // Prefix sum array initialized to 0 for quick summation
    vector<ll> prefixSum(n + 1, 0);

    // Variable to store the sum of all elements in the array
    ll totalSum = 0;

    // Input the elements and calculate the total sum
    for (ll i = 1; i <= n; i++)
    {
        cin >> elements[i];

        // Update the total sum with each element
        totalSum += elements[i];
    }

    // Set boundary elements to very large and very small values
    elements[0] = -1e18;
    elements[n + 1] = 1e18;

    // Sort the array from index 1 to `n` for binary search operations
    sort(elements.begin() + 1, elements.begin() + n + 1);

    // Compute prefix sums for quick range sum calculations
    for (ll i = 1; i <= n; i++)
    {
        prefixSum[i] = elements[i] + prefixSum[i - 1];
    }

    // Input the number of queries
    ll numQueries;
    cin >> numQueries;

    // Process each query
    while (numQueries--)
    {
        // Input the target value for the current query
        ll target;
        cin >> target;

        // Find the largest index `lastIndex` such that elements[lastIndex] <= target
        ll lastIndex = getLastIndex(elements, target);

        // Calculate the cost to transform elements on the left side of `lastIndex` to `target`
        ll leftPart = target * lastIndex - prefixSum[lastIndex];

        // Calculate the cost to transform elements on the right side of `lastIndex` to `target`
        ll rightPart = (totalSum - prefixSum[lastIndex]) - target * (n - lastIndex);

        // Output the minimum total cost for this query
        cout << leftPart + rightPart << endl;
    }

    return 0;
}
