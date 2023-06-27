#include <stdio.h>
#include <stdlib.h>

void printSolution(int color[]);
int isSafe(int v, int **graph, int color[], int c);
int graphColoringUtil(int **graph, int m, int color[], int v);
void graphColoring(int **graph, int m, int V);

int main()
{
    int V, m;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph[i] = (int *)malloc(V * sizeof(int));

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);

    // Free dynamically allocated memory
    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}

void graphColoring(int **graph, int m, int V)
{
    int *color = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == 0)
        printf("No solution exists.");
    else
        printSolution(color);

    free(color);
}

int graphColoringUtil(int **graph, int m, int color[], int v)
{
    if (v == V)
        return 1;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1) == 1)
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

int isSafe(int v, int **graph, int color[], int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

void printSolution(int color[])
{
    printf("Vertex\tColor\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, color[i]);
}
