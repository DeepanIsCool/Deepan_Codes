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