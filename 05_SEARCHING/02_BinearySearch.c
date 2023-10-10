/*
!                                                 Binary Search:

~    Binary Search is defined as a searching algorithm used in a sorted array by repeatedly dividing the search interval in half.
~    The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(log N).

^    Time Complexity
?        Best Case	        O(1)
?        Average Case	    O(log n)
?        Worst Case	        O(log n)

^    Space Complexit:
?        Iterative method    O(1)
?        Recursive method    O(log n)

~    The Binary Search Algorithm can be implemented in the following two ways:
~        1.  Iterative Binary Search Algorithm
~        2.  Recursive Binary Search Algorithm: This method of binary search follows the divide and conquer approach.

*/

/*
 *  1.  Iterative Binary Search:
 */

/*
#include <stdio.h>
int main()
{
    int arr[7] = {8, 17, 33, 55, 63, 75, 98};
    int key, flag = 0;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int start = 0, end = 6, mid;

    // searching till search space reduces to a single element so to come out of searching:
    while (start <= end)
    {
        mid = (start + end) / 2;

        // if search element (key) is equal to the middle element, then break and return the mid index
        if (key == arr[mid])
        {
            flag = 1;
            break;
        }

        // else if search element (key) is less than the middle element
        //  reduce the end index to mid - 1
        else if (key < arr[mid])
        {
            end = mid - 1;
        }

        // else if search element (key) is greater than the middle element
        //  increase the start index to mid + 1
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
    }

    if (flag == 1)
    {
        printf("\nElement Found at Position: %d, Index: %d\n", mid + 1, mid);
    }
    else
    {
        printf("\nElement not found");
    }
    return 0;
}
*/


/*
 *    2.  Recursive Binary Search:
 */


#include <stdio.h>

int binary_search(int *,int ,int, int);

int main()
{
    int arr[7] = {1, 4, 6, 9, 13, 16, 20};
    int data, flag = 0;
    printf("Enter the key to search: ");
    scanf("%d", &data);

    int result = binary_search(arr, 0, 6, data);

    if (result != -1)
    {
        printf("\nElement Found at Position: %d, Index: %d\n", result + 1, result);
    }
    else
    {
        printf("\nElement not found");
    }

    return 0;
}

int binary_search(int *a, int start, int end, int key)
{
    // exit/base condition for recursive calls, if element not found
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;

    // if search element (key) is equal to the middle element, then return mid index
    if (key == a[mid])
    {
        return mid;
    }
    // else if search element (key) is less than the middle element
    //  pass mid - 1 in place of end index
    else if (key < a[mid])
    {
        return binary_search(a, start, mid - 1, key);
    }
    // if search element (key) is greater than the middle element
    // pass mid + 1 in place of end index
    else if (key > a[mid])
    {
        return binary_search(a, mid + 1, end, key);
    }

    // if element is not found return -1
    return -1;
}

