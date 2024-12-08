/*
Pseudocode for Optimized Bubble Sort Program

1. Swap Function:
   - Input: Two integer pointers `xp` and `yp`.
   - Perform the following steps:
     - Store the value of `*xp` in a temporary variable.
     - Assign the value of `*yp` to `*xp`.
     - Assign the temporary variable's value to `*yp`.

2. Optimized Bubble Sort:
   Function bubbleSort(arr[], n):
   - Input: Array `arr` of size `n`.
   - For i = 0 to n - 2:
       - Initialize `swapped` to false.
       - For j = 0 to n - i - 2:
           - If arr[j] > arr[j + 1], swap them using `swap()`.
           - Set `swapped` to true.
       - If `swapped` is false (no swaps made in the inner loop), break the loop.

3. Print Array:
   Function printArray(arr[], size):
   - Input: Array `arr` of size `size`.
   - Iterate from 0 to `size - 1`, printing each element of `arr`.

4. Main Function:
   - Input: Read the size of the array `n` from the user.
   - Declare an array `arr` of size `n`.
   - Read `n` elements into the array from the user.
   - Call `bubbleSort(arr, n)` to sort the array.
   - Call `printArray(arr, n)` to display the sorted array.
*/

#include <stdio.h>
#include <stdbool.h>

// Function to swap two integers
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Optimized Bubble Sort function
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop, break
        if (!swapped)
            break;
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;

    // Take input for the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare array of size n

    // Take input for array elements
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Perform Bubble Sort
    bubbleSort(arr, n);

    // Display the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}