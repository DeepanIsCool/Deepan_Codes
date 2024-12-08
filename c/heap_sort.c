/*
Pseudocode for Heap Sort:

1. Function: HEAPIFY(arr, n, i)
   Input:
      - arr: Array of elements.
      - n: Size of the heap.
      - i: Index of the current node.
   Steps:
      a. Initialize `maximum = i`.
      b. Calculate `left_index = 2 * i + 1` and `right_index = 2 * i + 2`.
      c. Compare left child (`arr[left_index]`) with `arr[maximum]`:
         - If left child exists (`left_index < n`) and is greater, set `maximum = left_index`.
      d. Compare right child (`arr[right_index]`) with `arr[maximum]`:
         - If right child exists (`right_index < n`) and is greater, set `maximum = right_index`.
      e. If `maximum != i`, swap `arr[i]` and `arr[maximum]`, and recursively call `HEAPIFY(arr, n, maximum)`.

2. Function: HEAPSORT(arr, n)
   Input:
      - arr: Array of elements.
      - n: Number of elements in the array.
   Steps:
      a. Build the max heap:
         - Iterate from `n / 2 - 1` to `0` (backwards):
           - Call `HEAPIFY(arr, n, i)` for each index `i`.
      b. Perform heap sort:
         - Iterate from `n - 1` to `1` (backwards):
           - Swap `arr[0]` (root of heap) with `arr[i]`.
           - Reduce heap size to `i`.
           - Call `HEAPIFY(arr, i, 0)` to restore heap properties.

3. Function: PRINT_ARRAY(arr, n)
   Input:
      - arr: Array of elements.
      - n: Number of elements in the array.
   Steps:
      a. Iterate over the array elements and print each value.

4. MAIN Program
   Steps:
      a. Input array size `n`.
      b. Input array elements into `arr`.
      c. Call `PRINT_ARRAY(arr, n)` to display the original array.
      d. Call `HEAPSORT(arr, n)` to sort the array.
      e. Call `PRINT_ARRAY(arr, n)` to display the sorted array.

5. End.
*/

#include <stdio.h>

// Heapify function
void heapify(int arr[], int n, int i)
{
    int temp, maximum, left_index, right_index;

    // Assuming i holds the largest value
    maximum = i;

    // Left child index
    left_index = 2 * i + 1;

    // Right child index
    right_index = 2 * i + 2;

    // Check if left child is larger than root
    if (left_index < n && arr[left_index] > arr[maximum])
        maximum = left_index;

    // Check if right child is larger than the current largest
    if (right_index < n && arr[right_index] > arr[maximum])
        maximum = right_index;

    // If the largest is not the root, swap and heapify recursively
    if (maximum != i)
    {
        temp = arr[i];
        arr[i] = arr[maximum];
        arr[maximum] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, maximum);
    }
}

// HeapSort function
void heapsort(int arr[], int n)
{
    int temp;

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move the current root to the end
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code
int main()
{
    int n;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    printArray(arr, n);

    // Perform heap sort
    heapsort(arr, n);

    printf("Array after performing heap sort: ");
    printArray(arr, n);

    return 0;
}