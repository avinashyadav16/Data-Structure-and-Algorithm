/*
*                                                               SELECTION SORT:

~   Selection sort is a simple and efficient sorting algorithm that works by repeatedly selecting the smallest (or largest) element
~   from the unsorted portion of the list and moving it to the sorted portion of the list.

&>   It is an in-place comparison sorting algorithm.

?>   In this algorithm, the array is divided into two parts, first is sorted part, and another one is the unsorted part.
?    Initially, the sorted part of the array is empty, and unsorted part is the given array. Sorted part is placed at the left,
?    while the unsorted part is placed at the right.

^>   Time Complexity
^                    Best Case       O(n^2)
^                    Average Case    O(n^2)
^                    Worst Case      O(n^2)

*/

#include <stdio.h>
int main()
{
    int size = 10;
    int a[] = {3, 2, 6, 5, 4, 7, 8, 9, 5, 1};

    int min_index;

    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", a[i]);
    }
    return 0;
}