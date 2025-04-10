#include <stdio.h>
#include <limits.h>
typedef struct node
{
    int s, d, w;
} Ele;
int main()
{
    int e, v;
    printf("Enter the number of edges and the number of vertices:\n");
    scanf("%d%d", &e, &v);
    int mat[v][v];
    Ele arr[e];
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            mat[i][j] = 0;
        }
    }
    printf("Enter the edges and their weights:\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d%d%d", &arr[i].s, &arr[i].d, &arr[i].w);
        int r = arr[i].s;
        int c = arr[i].d;
        mat[r][c] = arr[i].w;
    }
    printf("The adjacency matrix is:\n");
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
    int Dist[v];
    int prev_node[v];
    for (i = 0; i < v; i++)
    {
        Dist[i] = INT_MAX;
        prev_node[i] = -1;
    }
    Dist[0] = 0;
    int iter = v - 1;
    int k = 0;
    while (k != v)
    {
        for (i = 0; i < v; i++)
        {
            for (j = 0; j < v; j++)
            {
                if (mat[i][j] == 0)
                    continue;
                if (Dist[j] > Dist[i] + mat[i][j])
                {
                    Dist[j] = Dist[i] + mat[i][j];
                    prev_node[j] = i;
                }
            }
        }
        k++;
    }
    printf("The distance array is:\n");
    for (i = 0; i < v; i++)
    {
        printf("%d ", Dist[i]);
    }
    printf("The node array is:\n");
    for (i = 0; i < v; i++)
    {
        printf("%d ", prev_node[i]);
    }
    return 0;
}