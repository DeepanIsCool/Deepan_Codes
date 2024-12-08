/*
Pseudocode for QuickSort Algorithm

1. Swap Function:
   Function swap(a, b):
     - Input: Pointers to two integers `a` and `b`.
     - Swap the values of `a` and `b` using a temporary variable.

2. Partition Function:
   Function partition(arr, low, high):
     - Input: Array `arr`, lower bound `low`, and upper bound `high`.
     - Select the pivot element as `arr[low]`.
     - Initialize pointers `i = low` and `j = high`.
     - While `i < j`:
       - Increment `i` until `arr[i] > pivot`.
       - Decrement `j` until `arr[j] <= pivot`.
       - If `i < j`, swap `arr[i]` and `arr[j]`.
     - Swap `arr[low]` (pivot) with `arr[j]` to place the pivot in its correct position.
     - Return `j` (partition index).

3. QuickSort Function:
   Function quickSort(arr, low, high):
     - Input: Array `arr`, lower bound `low`, and upper bound `high`.
     - If `low < high`:
       - Call `partition(arr, low, high)` to partition the array and get the partition index `pi`.
       - Recursively sort the left subarray (`arr[low..pi-1]`).
       - Recursively sort the right subarray (`arr[pi+1..high]`).

4. Print Array Function:
   Function printArray(arr, size):
     - Input: Array `arr` and its size.
     - Iterate over the array and print each element.

5. Main Function:
   - Input the size of the array (`n`) and elements of the array (`arr[]`).
   - Print the original array using `printArray`.
   - Call `quickSort(arr, 0, n-1)` to sort the array.
   - Print the sorted array using `printArray`.
*/

#include <stdio.h>

// Swap function to interchange two values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place pivot element in its correct position
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Select the pivot as the first element
    int i = low;
    int j = high;

    while (i < j)
    {
        // Increment i until an element greater than pivot is found
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        // Decrement j until an element less than or equal to pivot is found
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]); // Swap arr[i] and arr[j]
        }
    }
    swap(&arr[low], &arr[j]); // Place pivot in its correct position
    return j;                 // Return partition index
}

// QuickSort function using recursion
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Partition index
        quickSort(arr, low, pi - 1);        // Sort left subarray
        quickSort(arr, pi + 1, high);       // Sort right subarray
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;

    // Input size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare array dynamically based on user input

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    // Call quickSort to sort the array
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}