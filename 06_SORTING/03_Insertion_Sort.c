/*
*                                                               INSERTION SORT

~   Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands.
~   The array is virtually split into a sorted and an unsorted part.
~   Values from the unsorted part are picked and placed at the correct position in the sorted part.


*/

#include <stdio.h>

int main()
{
    int size, i, j, temp;
    printf("Enter the array size: ");
    scanf("%d", &size);
    int arr[size];


    printf("\nEnter the array elements: \n");
    for (i = 0; i < size; i++)
    {
        printf("Element_%d:  ", i + 1);
        scanf("%d", &arr[i]);
    }


    printf("\nUnsorted array elements are: \n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }


    for (i = 1; i <= size - 1; i++)
    {
        j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
    

    printf("\n\nSorted array elements are: \n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}