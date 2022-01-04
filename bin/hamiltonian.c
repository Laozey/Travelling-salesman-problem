#include "../headers/hamiltonian.h"

int isSafe(int vertex_inee, Graph_t *graph, int path[], int pos)
{
    // Check if this vertex is a neighbor of the previous vertex in the path
    if (!isNeighbor(graph->vertices[pos - 1].succ, vertex_inee))
        return 0;

    // Check if the vertex is already in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == vertex_inee)
            return 0;

    return 1;
}

void printSolution(int path[], Graph_t *graph)
{
    printf("Following is one Hamiltonian Cycle\n");
    for (int i = 0; i < graph->size; i++)
        printf(" %d ", path[i]);

    printf(" %d ", path[0]);
    printf("\n");
}

int hamCycle(Graph_t *graph)
{
    int *path = malloc(sizeof(int) * graph->size);

    for (int i = 0; i < graph->size; i++)
        path[i] = -1;

    path[0] = graph->vertices[0].code;

    if (!hamCycleUtil(graph, path, 1))
    {
        printf("\nSolution does not exist\n");
        free(path);
        return 0;
    }

    printSolution(path, graph);
    free(path);
    return 1;
}

int hamCycleUtil(Graph_t *graph, int *path, int pos)
{
    printf("%d %%\n", 100 * pos / graph->size);
    if (pos == graph->size)
    {
        if (isNeighbor(graph->vertices[pos - 1].succ, path[0]))
            return 1;
        return 0;
    }

    for (int i = 1; i < graph->size; i++)
    {
        if (isSafe(graph->vertices[i].code, graph, path, pos))
        {
            path[pos] = graph->vertices[i].code;

            if (hamCycleUtil(graph, path, pos + 1))
                return 1;

            path[pos] = -1;
        }
    }

    return 0;
}

int isNeighbor(Node_t *neighbor, int wanted_neighbor_inee)
{
    if (neighbor->v->code == wanted_neighbor_inee)
        return 1;
    if (!neighbor->next)
        return 0;
    else
        return isNeighbor(neighbor->next, wanted_neighbor_inee);
}