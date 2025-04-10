#include<stdio.h>

int main()
{
    char X[5] = {'B', 'A', 'C', 'D', 'B'};
    char Y[4] = {'B', 'D', 'C', 'B'};

    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);

    int mat[m + 1][n + 1];
    int i, j;

    // Initialize the matrix
    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                mat[i][j] = 0;
        }
    }

    // Fill the matrix using LCS logic
    for (i = 1; i < m + 1; i++)
    {
        for (j = 1; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else
            {
                if (mat[i - 1][j] >= mat[i][j - 1])
                    mat[i][j] = mat[i - 1][j];
                else
                    mat[i][j] = mat[i][j - 1];
            }
        }
    }

    // Print the matrix
    printf("The matrix that is finally created:\n");
    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // LCS length
    int p = mat[m][n];
    printf("%d\n", p);

    // Array for storing LCS
    char arr[p];
    int k = p - 1; // Adjust for 0-based indexing
    i = m;
    j = n;

    // Reconstruct the LCS
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1]) // Match case
        {
            arr[k] = X[i - 1];
            i--;
            j--;
            k--;
        }
        else if (mat[i - 1][j] > mat[i][j - 1]) // Move up
        {
            i--;
        }
        else // Move left
        {
            j--;
        }
    }

    // Print the LCS
    printf("The subsequence is:\n");
    for (i = 0; i < p; i++)
    {
        printf("%c ", arr[i]);
    }

    return 0;
}