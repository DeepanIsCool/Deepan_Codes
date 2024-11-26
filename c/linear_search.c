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