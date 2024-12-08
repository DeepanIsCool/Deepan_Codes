/*
Pseudocode for Recursive Linear Search:

1. Function: LINEAR_SEARCH(arr, n, key)
   Input:
      - arr: Pointer to the array.
      - n: Number of elements in the array.
      - key: Element to search for.
   Output:
      - Index of the element `key` in the array if found, otherwise -1.

   Steps:
      a. Base Case:
         - If `n == 0` (array is empty), return -1.
      b. Check the last element:
         - If `arr[n - 1] == key`, return `n - 1`.
      c. Recursive Case:
         - Call LINEAR_SEARCH with the array and size `n - 1`.

2. MAIN Program
   Input:
      a. Read the size of the array `n`.
      b. Dynamically allocate memory for the array.
      c. Read `n` elements into the array.
      d. Read the key to search for.

   Process:
      a. Call LINEAR_SEARCH with the array, size `n`, and `key`.
      b. If the result is -1, print "Key Not Found".
      c. Otherwise, print the index where the key is found (adjusting for 1-based indexing).

   Cleanup:
      a. Free the dynamically allocated memory.

3. End.
*/

#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr, int n, int key)
{
    // Base Case: if there are no elements, return -1
    if (n == 0)
        return -1;

    // If the element at (n - 1) index is equal to key, return (n - 1)
    if (arr[n - 1] == key)
    {
        return n - 1;
    }

    // If element is not at n - 1, call linear search for same array arr but reducing the size by a single element
    return linearSearch(arr, n - 1, key);
}

int main()
{
    int n, key;

    // Taking input for the size of the array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    // Dynamically allocating memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Taking input for the elements of the array
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Taking input for the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Calling linearSearch function
    int i = linearSearch(arr, n, key);

    if (i == -1)
        printf("Key Not Found\n");
    else
        printf("Key Found at Index: %d\n", i + 1);

    // Freeing the allocated memory
    free(arr);

    return 0;
}