/*
!                                                                   MERGE SORT

?    Merge sort is defined as a sorting algorithm that works by dividing an array into smaller subarrays,
?    sorting each subarray, and then merging the sorted subarrays back together to form the final sorted array.

*   Alogorithm:
        MERGE_SORT(arr, beg, end)

            if start < end
                set mid = (start + end)/2
                MERGE_SORT(arr, start, mid)
                MERGE_SORT(arr, mid + 1, end)
                MERGE (arr, start, mid, end)
            end if

        END MERGE_SORT

^   Time Complexity
        Case	            Time Complexity
        Best Case	        O(n*logn)
        Average Case	    O(n*logn)
        Worst Case	        O(n*logn)

^   Space Complexity
        Space Complexity	O(n)

*/

#include <stdio.h>
#include <stdlib.h>

void printArray(int *, int);
void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is: \n");
    printArray(arr, arr_size);
    return 0;
}


void printArray(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        // Sort first and second halves
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[start  .....  mid] and Second subarray is arr[mid+1  .....  end]
void merge(int *arr, int start, int mid, int end)
{
    int i, j, k;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // Create temp arrays
    int left_arr[len1], right_arr[len2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < len1; i++)
    {
        left_arr[i] = arr[start + i];
    }

    for (j = 0; j < len2; j++)
    {
        right_arr[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = start;
    while (i < len1 && j < len2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_arr[], if there are any
    while (i < len1)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_arr[], if there are any
    while (j < len2)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}
