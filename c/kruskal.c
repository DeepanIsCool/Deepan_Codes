/*
Pseudocode for Kruskal's Algorithm:

1. Initialize:
   a. `n`: Number of vertices.
   b. `cost`: Cost adjacency matrix for the graph.
   c. `parent`: Array to track connected components.
   d. `mincost`: Total cost of the Minimum Spanning Tree (MST), initialized to 0.
   e. `ne`: Edge counter, initialized to 1.

2. Input:
   a. Accept the number of vertices `n`.
   b. Accept the cost adjacency matrix `cost`:
      - Replace 0 with a large value (e.g., 999) for disconnected edges.

3. Kruskal's Algorithm:
   a. Repeat until `ne < n` (MST will have `n-1` edges):
      i. Find the smallest cost edge `(u, v)` in the `cost` matrix.
         - Update `min` with the smallest edge weight.
         - Track the vertices `u` and `v` connected by this edge.
      ii. Check if including this edge forms a cycle:
         - Use the `FIND` function to determine the root of `u` and `v`.
         - If roots are different, include the edge in the MST.
         - Increment `ne` and add the edge weight to `mincost`.
         - Mark the edge as used by setting `cost[u][v]` and `cost[v][u]` to 999.

4. FIND Function:
   Input:
      - A vertex `i`.
   Steps:
      - Traverse the `parent` array to find the root of the component containing `i`.

5. UNION Function:
   Input:
      - Vertices `i` and `j`.
   Steps:
      - If `i` and `j` are in different components, union them by updating the `parent` array and return true.
      - Otherwise, return false.

6. Output:
   a. Print the edges in the MST with their weights.
   b. Print the total minimum cost of the MST.

7. End.
*/

#include <stdio.h>
#include <stdlib.h>
int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
int find(int);
int uni(int, int);
void main()
{
    printf("\n\n\tImplementation of Kruskal's algorithm\n\n");
    printf("\nEnter the no. of vertices\n");
    scanf("%d", &n);
    printf("\nEnter the cost adjacency matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    printf("\nThe edges of Minimum Cost Spanning Tree are\n\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("\n%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n\tMinimum cost = %d\n", mincost);
}
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}