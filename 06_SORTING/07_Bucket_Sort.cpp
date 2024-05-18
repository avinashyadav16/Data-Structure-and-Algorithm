/**
*  @file: 07_Bucket_Sort.cpp
*  @author: Avinash Yadav
*  @brief: Bucket sort is a sorting technique that involves dividing elements into various groups, or buckets.
            These buckets are formed by uniformly distributing the elements.
            Once the elements are divided into buckets, they can be sorted using any other sorting algorithm.
            Finally, the sorted elements are gathered together in an ordered fashion.

            Bucket Sort Algorithm:
            Create n empty buckets (Or lists) and do the following for every array element arr[i].
                - Insert arr[i] into bucket[n*array[i]]
                - Sort individual buckets using any stable sorting algorithm(Quick / Merge).
                - Concatenate all sorted buckets.

*  @date: 18-05-2024
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Insertion sort function to sort individual buckets
void insertionSort(vector<int> &bucket)
{
    for (int i = 1; i < bucket.size(); ++i)
    {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to sort arr[] of size n using bucket sort
void bucketSort(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 0)
        return;

    // 1) Create n empty buckets
    vector<vector<int>> buckets(n);

    // 2) Put array elements in different buckets
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        // Normalize to the range of buckets
        int bucket_index = (n * arr[i]) / (maxVal + 1);
        buckets[bucket_index].push_back(arr[i]);
    }

    // 3) Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++)
    {
        insertionSort(buckets[i]);
    }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
}

int main()
{
    vector<int> arr = {54, 12, 84, 57, 69, 41, 9, 5, 66, 16, 2, 49};

    bucketSort(arr);

    cout << "Sorted Array is: " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}