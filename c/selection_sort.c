/*
Pseudocode for Selection Sort Algorithm

1. Selection Sort:
   Function selectionSort(arr, n):
     - Input: Array `arr` of size `n`.
     - For each position `i` from 0 to `n - 2`:
       - Assume the current position holds the minimum element:
         Set `min_idx = i`.
       - Iterate through the unsorted portion (`j = i + 1` to `n - 1`):
         - If `arr[j] < arr[min_idx]`, update `min_idx = j`.
       - Swap `arr[i]` and `arr[min_idx]` to move the minimum element to its correct position.

2. Print Array:
   Function printArray(arr, n):
     - Input: Array `arr` of size `n`.
     - Iterate from 0 to `n - 1`, printing each element of the array.

3. Main Function:
   - Input the size of the array (`n`) and declare an array `arr[]` of size `n`.
   - Input the elements of the array.
   - Print the original array using `printArray`.
   - Call `selectionSort(arr, n)` to sort the array.
   - Print the sorted array using `printArray`.

4. End.
*/

#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Assume the current position holds the minimum element
        int min_idx = i;

        // Iterate through the unsorted portion to find the actual minimum
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j; // Update min_idx if a smaller element is found
            }
        }

        // Move the minimum element to its correct position
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
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

int main()
{
    int n;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare the array dynamically

    // Input the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    // Call selection sort
    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}