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