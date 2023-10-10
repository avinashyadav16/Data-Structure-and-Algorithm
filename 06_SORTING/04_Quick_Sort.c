/*
!                                                                            QUICK SORT

~   QuickSort is a sorting algorithm based on the Divide and Conquer algorithm.
~   Divide and conquer is a technique of breaking down the algorithms into subproblems, then solving the subproblems,
~   and combining the results back together to solve the original problem.

~   An array is divided into subarrays by selecting a pivot element (element selected from the array).
~   While dividing the array, the pivot element should be positioned in such a way that elements less than pivot are kept on the left side and
~   elements greater than pivot are on the right side of the pivot.
~   The left and right subarrays are also divided using the same approach. This process continues until each subarray contains a single element.
~   At this point, elements are already sorted. Finally, elements are combined to form a sorted array.

^        Divide:
                In Divide, first pick a pivot element.
                After that, partition or rearrange the array into two sub-arrays
                such that each element in the left sub-array is less than or equal to the pivot element
                and each element in the right sub-array is larger than the pivot element.

^        Conquer:
                Recursively, sort two subarrays with Quicksort.

^        Combine:
                Combine the already sorted array.

*   Algorithm:
            QUICKSORT (array A, start, end)
            {
                1   if (start < end)
                2   {
                3       p = partition(A, start, end)
                4       QUICKSORT (A, start, p - 1)
                5       QUICKSORT (A, p + 1, end)
                6   }
            }

*   Partition Algorithm:
The partition algorithm rearranges the sub-arrays in a place.

            PARTITION (array A, start, end)
            {
                1   pivot ? A[end]
                2   i ? start-1
                3   for j ? start to end -1 {
                4   do if (A[j] < pivot) {
                5   then i ? i + 1
                6   swap A[i] with A[j]
                7   }
                8   }
                9   swap A[i+1] with A[end]
                10   return i+1
            }

*   Time Complexity
            Case	            Time Complexity
            Best Case	        O(n*logn)       It occurs when the pivot element is always the middle element or near to the middle element.
            Worst Case	        O(n^2)          It occurs when the pivot element picked is either the greatest or the smallest element.
            Average Case	    O(n*logn)       It occurs when the above conditions do not occur.

*   Space Complexity
            Space Complexity	O(n*logn)
*/

#include <stdio.h>

void printArr(int *, int);
void quick_sort(int *, int, int);
int partition(int *, int, int);

int main()
{
    // int a[] = {24, 9, 29, 14, 19, 27};
    int a[] = {1, 3, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting array elements are - \n");
    printArr(a, n);

    quick_sort(a, 0, n - 1);

    printf("\n\nAfter sorting array elements are - \n");
    printArr(a, n);

    return 0;
}

//  Function to print the array
void printArr(int *a, int n)
{
    printf("%d\n", a[0] + a[n - 1]);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

//  Function to implement quick sort
void quick_sort(int *a, int start, int end) //   a = array to be sorted, start = Starting index, end = Ending index
{
    if (start < end)
    {
        int p = partition(a, start, end); // p is the partitioning index
        quick_sort(a, start, p - 1);
        quick_sort(a, p + 1, end);
    }
}

/*
    Function that consider last element as pivot, place the pivot at its exact position, and
    place smaller elements to left of pivot and greater elements to right of pivot.
*/

int partition(int *a, int start, int end)
{
    int p_index = start;
    int pivot = a[end]; // pivot element

    for (int i = start; i < end; i++)
    {
        // If current element is smaller than the pivot
        if (a[i] < pivot)
        {
            int temp = a[p_index];
            a[p_index] = a[i];
            a[i] = temp;
            p_index++; // increment index of smaller element
        }
    }
    int temp = a[p_index];
    a[p_index] = a[end];
    a[end] = temp;
    return p_index;
}

// int partition(int *a, int start, int end)
// {
//     int pivot = a[end];         // pivot element

//     int i = (start - 1);
//     for (int j = start; j <= end - 1; j++)
//     {
//         // If current element is smaller than the pivot
//         if (a[j] < pivot)
//         {
//             i++; // increment index of smaller element
//             int t = a[i];
//             a[i] = a[j];
//             a[j] = t;
//         }
//     }
//     int t = a[i + 1];
//     a[i + 1] = a[end];
//     a[end] = t;
//     return (i + 1);
// }