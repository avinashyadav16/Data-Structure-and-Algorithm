#include <stdio.h>

void radix(int *, int);
int get_max(int *, int);
void counting_sort(int *, int, int);

int main()
{
    int size;
    printf("\nEnter the size: ");
    scanf("%d", &size);
    int arr[size];
    printf("\nEnter the elements: \n");
    for (int i = 0; i < size; i++)
    {
        printf("Element_%d:\t", i + 1);
        scanf("%d", &arr[i]);
    }

    radix(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void radix(int *arr, int size)
{
    int max = get_max(arr, size);

    for (int place = 1; max / place > 0; place *= 10)
    {
        counting_sort(arr, size, place);
    }
}

int get_max(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void counting_sort(int *arr, int size, int place)
{
    int output[size + 1];
    int max = (arr[0] / place) % 10;

    for (int i = 1; i < size; i++)
    {
        if (((arr[i] / place) % 10) > max)
        {
            max = arr[i];
        }
    }

    int count[max + 1];

    for (int i = 0; i < max; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}