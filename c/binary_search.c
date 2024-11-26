#include <stdio.h>
#include <stdlib.h>

// A recursive binary search function. It returns
// location of x in given array arr[low..high] if present,
// otherwise -1
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, high, x);
    }

    // We reach here when element is not present in array
    return -1;
}

// Driver code
int main()
{
    int n, x;

    // Taking input for the size of the array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    // Dynamically allocating memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Taking input for the elements of the array
    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Taking input for the element to search
    printf("Enter the element to search: ");
    scanf("%d", &x);

    // Performing binary search
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result + 1);

    // Freeing the allocated memory
    free(arr);

    return 0;
}