/*
*                                                               BUBBLE SORT

~        Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.
~        This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.


* Bubble Sort Algorithm:
~        In this algorithm, traverse from left and compare adjacent elements and the higher one is placed at right side.
~        In this way, the largest element is moved to the rightmost end at first.
~        This process is then continued to find the second largest and place it and so on until the data is sorted.


* Complexity Analysis of Bubble Sort:
~        Time Complexity:
                        Case	             Time Complexity
                        Best Case	            O(n)
                        Average Case	        O(n^2)
                        Worst Case	            O(n^2)

~        Auxiliary Space: O(1)


* Advantages of Bubble Sort:
~        Bubble sort is easy to understand and implement.
~        It does not require any additional memory space.
~        It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.


* Disadvantages of Bubble Sort:
~        Bubble sort has a time complexity of O(N^2) which makes it very slow for large data sets.
~        It's a comparison-based sorting algorithm, i.e. it requires a comparison operator to determine the relative order of elements in the input data set.
~        It can limit the efficiency of the algorithm in certain cases.

*/

#include <stdio.h>

int main()
{
    int size, temp;
    printf("Enter the array size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the array elements: \n");
    for (int i = 0; i < size; i++)
    {
        printf("Element_%d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted Array Elements Are: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
& ANOTHER APPROACH:

~  for (int i = 0; i < n - 1; i++) {
~    for (int j = 0; j < n - i - 1; j++)
     {
      if (arr[j] > arr[j + 1]) {

        // checking and swapping adjacent elements when left_elem > right_elem
        
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

*/


/*
for (int i = 0; i < n - 1; i++)
{
    for (int j = 0; j < n - i - 1; j++)
    {

    }
}
*/
