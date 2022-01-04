#include "../headers/graph.h"
#include <math.h>

Graph_t *createGraph(Matrice_t *matrice)
{
    Graph_t *graph = malloc(sizeof(Graph_t));
    graph->size = matrice->size;
    graph->vertices = malloc(sizeof(Vertex_t) * graph->size);

    int i = 0;
    createVertex(matrice->datas[0].inee, matrice, graph, &i);

    return graph;
}

Node_t *createSuccessor(Data_t data, Matrice_t *matrice, Graph_t *graph, int *gp, int mp)
{
    int succ_inee = data.neighbors[mp];
    // unwanted city are changed to -1, this block ensure we treat a valid city
    while (succ_inee == -1)
    {
        if (mp < data.nb_neighbors - 1)
        {
            mp++;
            succ_inee = data.neighbors[mp];
        }
        else
        {
            return NULL;
        }
    }

    Node_t *n = malloc(sizeof(Node_t));

    int succ_g_idx = matrice->datas[succ_inee - INEE_MIN].isAlocated;

    // check if the neighbor city has already been treated, if not it initialise it
    if (succ_g_idx != -1)
        n->v = &graph->vertices[succ_g_idx];
    else
    {
        *gp += 1;
        int succ_idx = *gp;
        createVertex(succ_inee, matrice, graph, gp);
        n->v = &graph->vertices[succ_idx];
    }

    // distance from current vertex to neighbor
    n->dist = computeDistance(matrice->datas[data.inee - INEE_MIN].lat, matrice->datas[data.inee - INEE_MIN].lon, matrice->datas[succ_inee - INEE_MIN].lat, matrice->datas[succ_inee - INEE_MIN].lon);

    // Go to the next successor, or end the sequence if there is no successor
    if (mp < data.nb_neighbors - 1)
    {
        mp++;
        n->next = createSuccessor(data, matrice, graph, gp, mp);
    }
    else
        n->next = NULL;

    return n;
}

void createVertex(int new_inee, Matrice_t *m, Graph_t *g, int *gp)
{
    m->datas[new_inee - INEE_MIN].isAlocated = *gp;
    g->vertices[*gp].code = m->datas[new_inee - INEE_MIN].inee;
    g->vertices[*gp].succ = createSuccessor(m->datas[new_inee - INEE_MIN], m, g, gp, 0);
}

void freeGraph(Graph_t *g)
{
    for (int i = 0; i < g->size; i++)
    {
        freeSuccessor(g->vertices[i].succ);
    }
    free(g->vertices);
    free(g);
}

void freeSuccessor(Node_t *n)
{
    if (n->next)
        freeSuccessor(n->next);
    free(n);
}

// Distance from A to B
// picked from https://www.geeksforgeeks.org/program-distance-two-points-earth/
float computeDistance(float latA, float lonA, float latB, float lonB)
{
    latA = toRadians(latA);
    latB = toRadians(latB);
    lonA = toRadians(lonA);
    lonB = toRadians(lonB);

    // Haversine Formula
    float dlat = latB - latA;
    float dlon = lonB - lonA;

    float res = powf(sinf(dlat / 2), 2) +
                cosf(latA) * cosf(latB) *
                    powf(sinf(dlon / 2), 2);

    res = 2 * asinf(sqrtf(res));

    // Earth radius
    int R = 6371;

    return res * R;
}

float toRadians(float deg)
{
    return deg * M_PI / 180;
}
