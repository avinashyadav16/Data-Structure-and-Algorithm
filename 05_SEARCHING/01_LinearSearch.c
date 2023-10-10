#include <stdio.h>

int main()
{
    int size, key, flag = 0;
    printf("Enter the array size: ");
    scanf("%d", &size);
    int arr[size];

    printf("\nEnter the array elements: \n");
    for (int i = 0; i < size; i++)
    {
        printf("Element_%d:  ",i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements are: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nEnter the key to search: ");
    scanf("%d", &key);
    printf("Result of the search operation: \n");
    for (int j = 0; j < size; j++)
    {
        if (arr[j] == key)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("The Element %d Successfully Found At Index %d.", arr[j], j);
    }
    else
    {
        printf("Search Not Found.");
    }

    return 0;
}

//      Linear Search for Multiple Occurrences
/*
#include <stdio.h>

int main()
{
    int size, key, i, j, countKey = 0;
    printf("Number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter elements of the array: \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);
    printf("\n");

    for (j = 0; j < size; j++)
    {
        if (arr[j] == key)
        {
            printf("Key element found at index: %d\n", j);
            countKey++;
        }
    }

    if (countKey == 0)
    {
        printf("\nKey element not found");
    }
    else
    {
        printf("\nKey element is present %d times in the array.\n", countKey);
    }

    return 0;
}
*/