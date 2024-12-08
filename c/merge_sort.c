/*
Pseudocode for Merge Sort Algorithm:

1. Function: MERGE(arr, left, mid, right)
   Input:
      - arr: Array of elements.
      - left, mid, right: Indices defining two subarrays:
        - First subarray: arr[left..mid].
        - Second subarray: arr[mid+1..right].
   Steps:
      a. Calculate sizes of the subarrays:
         - n1 = mid - left + 1.
         - n2 = right - mid.
      b. Create temporary arrays `leftArr[n1]` and `rightArr[n2]`.
      c. Copy data to temporary arrays:
         - Copy arr[left..mid] to `leftArr`.
         - Copy arr[mid+1..right] to `rightArr`.
      d. Initialize indices:
         - i = 0 (index for `leftArr`).
         - j = 0 (index for `rightArr`).
         - k = left (index for merged array).
      e. Merge elements back into arr[left..right]:
         - While i < n1 and j < n2:
             - If `leftArr[i] <= rightArr[j]`, copy `leftArr[i]` to `arr[k]` and increment i.
             - Else, copy `rightArr[j]` to `arr[k]` and increment j.
             - Increment k.
      f. Copy any remaining elements:
         - Copy remaining `leftArr` elements to `arr`.
         - Copy remaining `rightArr` elements to `arr`.

2. Function: MERGE_SORT(arr, left, right)
   Input:
      - arr: Array of elements.
      - left, right: Indices defining the subarray to sort.
   Steps:
      a. If left < right:
         - Calculate mid = left + (right - left) / 2.
         - Recursively call MERGE_SORT(arr, left, mid) to sort the left half.
         - Recursively call MERGE_SORT(arr, mid + 1, right) to sort the right half.
         - Call MERGE(arr, left, mid, right) to merge the sorted halves.

3. MAIN Program
   Input:
      a. Read the size `n` of the array.
      b. Read `n` elements into `arr`.
   Process:
      a. Print the original array.
      b. Call MERGE_SORT(arr, 0, n-1) to sort the array.
      c. Print the sorted array.

4. End.
*/

#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[]: arr[left..mid] and arr[mid+1..right]
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive function to sort subarray arr[left..right] using Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

    int arr[n]; // Declare array dynamically

    // Input the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    // Call mergeSort to sort the array
    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}