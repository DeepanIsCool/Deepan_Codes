/*
Pseudocode for Insertion Sort:

1. Function: INSERTION_SORT(arr, N)
   Input:
      - arr: Array of integers.
      - N: Number of elements in the array.
   Steps:
      a. For i = 1 to N-1:
         i. Set `key = arr[i]`.
         ii. Set `j = i - 1`.
         iii. While `j >= 0` and `arr[j] > key`:
              - Shift `arr[j]` to `arr[j + 1]`.
              - Decrement `j` by 1.
         iv. Insert `key` at `arr[j + 1]`.

2. MAIN Program
   Steps:
      a. Input size `N` of the array.
      b. Declare an array `arr` of size `N`.
      c. Input elements of the array into `arr`.
      d. Print the original (unsorted) array.
      e. Call `INSERTION_SORT(arr, N)` to sort the array.
      f. Print the sorted array.

3. End.
*/

#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int N)
{
    // Starting from the second element
    for (int i = 1; i < N; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position to the right of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Place the key in its correct position
        arr[j + 1] = key;
    }
}

int main()
{
    int N;

    // Accept size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N]; // Declare array of size N

    // Accept array elements from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call insertion sort on the array
    insertionSort(arr, N);

    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}