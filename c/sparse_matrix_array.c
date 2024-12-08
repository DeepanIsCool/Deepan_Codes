/*
Pseudocode for Sparse Matrix Representation Using Arrays

1. Input Sparse Matrix:
   - Define a 2D array `sparseMatrix` to represent a sparse matrix (mostly zeroes).

2. Count Non-Zero Elements:
   - Initialize `size = 0`.
   - For each element `sparseMatrix[i][j]`:
     - If `sparseMatrix[i][j] != 0`, increment `size`.

3. Create Compact Matrix:
   - Allocate memory for a 2D array `compactMatrix` of size 3 x `size`.
   - Each row in `compactMatrix` represents:
     - Row indices of non-zero elements.
     - Column indices of non-zero elements.
     - Values of the non-zero elements.

4. Populate Compact Matrix:
   - Initialize `k = 0` (index for compactMatrix columns).
   - For each element `sparseMatrix[i][j]`:
     - If `sparseMatrix[i][j] != 0`:
       - Set `compactMatrix[0][k] = i` (row index).
       - Set `compactMatrix[1][k] = j` (column index).
       - Set `compactMatrix[2][k] = sparseMatrix[i][j]` (value).
       - Increment `k`.

5. Display Compact Matrix:
   - For each row in `compactMatrix`:
     - Print all elements in the row.

6. Free Allocated Memory:
   - Free the memory allocated for each row of `compactMatrix`.
   - Free the memory allocated for `compactMatrix`.

7. End.
*/

// C program for Sparse Matrix Representation
// using Array
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Assume 4x5 sparse matrix
    int sparseMatrix[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}};

    int size = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
                size++;

    // number of columns in compactMatrix (size) must be
    // equal to number of non - zero elements in
    // sparseMatrix
    int **compactMatrix = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
        compactMatrix[i] = (int *)malloc(size * sizeof(int));

    // Making of new matrix
    int k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d ", compactMatrix[i][j]);

        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < 3; i++)
        free(compactMatrix[i]);
    free(compactMatrix);

    return 0;
}