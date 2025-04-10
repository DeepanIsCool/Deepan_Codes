#include <stdio.h>
#include <limits.h>

typedef struct node {
    int s, d, w;
} Ele;

int main() {
    int e, v;
    printf("Enter the number of edges and the number of vertices in the graph:\n");
    scanf("%d%d", &e, &v);

    int mat[v][v], P[v][v];
    Ele arr[e];
    int i, j, k;

    // Initialize adjacency matrix and path matrix
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            if (i == j) {
                mat[i][j] = 0;
                P[i][j] = -1;  // No predecessor for itself
            } else {
                mat[i][j] = INT_MAX;
                P[i][j] = -1;
            }
        }
    }

    // Read input edges
    printf("Enter the edges (1-based index) and their weights:\n");
    for (i = 0; i < e; i++) {
        scanf("%d%d%d", &arr[i].s, &arr[i].d, &arr[i].w);

        // Convert 1-based input to 0-based for correct indexing
        arr[i].s--;
        arr[i].d--;

        int r = arr[i].s;
        int c = arr[i].d;

        if (mat[r][c] > arr[i].w) {
            mat[r][c] = arr[i].w;
            P[r][c] = r;  // Set predecessor
        }
    }

    // Print Initial Matrix
    printf("\nInitial Matrix M0:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            if (mat[i][j] == INT_MAX)
                printf("%7s", "INF");
            else
                printf("%7d", mat[i][j]);
        }
        printf("\n");
    }

    // Floyd-Warshall Algorithm
    for (k = 0; k < v; k++) {
        for (i = 0; i < v; i++) {
            for (j = 0; j < v; j++) {
                if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && mat[i][j] > mat[i][k] + mat[k][j]) {
                    mat[i][j] = mat[i][k] + mat[k][j];
                    P[i][j] = P[k][j];  // Update predecessor correctly
                }
            }
        }

        // Print Matrix at each step
        printf("\nM%d:\n", k + 1);
        for (i = 0; i < v; i++) {
            for (j = 0; j < v; j++) {
                if (mat[i][j] == INT_MAX)
                    printf("%7s", "INF");
                else
                    printf("%7d", mat[i][j]);
            }
            printf("\n");
        }
    }

    // Print Path Matrix
    printf("\nPath Matrix:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            printf("%3d", P[i][j] + 1);  // Convert back to 1-based for display
        }
        printf("\n");
    }

    return 0;
}
