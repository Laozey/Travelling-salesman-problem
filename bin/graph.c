#include "../headers/graph.h"
#include <math.h>

Graph_t *createGraph(Matrice_t *m)
{
    Graph_t *graph = malloc(sizeof(Graph_t));
    graph->size = m->size;
    graph->vertices = malloc(sizeof(Vertex_t) * graph->size);

    int i = 0;
    createVertex(m->datas[0].inee, m, graph, &i);

    return graph;
}

Node_t *createSuccessor(Data_t d, Matrice_t *m, Graph_t *g, int *gp, int mp)
{
    int succ_inee = d.neighbors[mp];
    // unwanted city are changed to -1, this block ensure we treat a valid city
    while (succ_inee == -1)
    {
        if (mp < d.nb_neighbors - 1)
        {
            mp++;
            succ_inee = d.neighbors[mp];
        }
        else
        {
            return NULL;
        }
    }

    Node_t *n = malloc(sizeof(Node_t));

    int succ_g_idx = m->datas[succ_inee - INEE_MIN].isAlocated;

    // check if the neighbor city has already been treated, if not it initialise it
    if (succ_g_idx != -1)
        n->v = &g->vertices[succ_g_idx];
    else
    {
        *gp += 1;
        int succ_idx = *gp;
        createVertex(succ_inee, m, g, gp);
        n->v = &g->vertices[succ_idx];
    }

    // distance from current vertex to neighbor
    n->dist = computeDistance(m->datas[d.inee - INEE_MIN].lat, m->datas[d.inee - INEE_MIN].lon, m->datas[succ_inee - INEE_MIN].lat, m->datas[succ_inee - INEE_MIN].lon);

    // Go to the next successor, or end the sequence if there is no successor
    if (mp < d.nb_neighbors - 1)
    {
        mp++;
        n->next = createSuccessor(d, m, g, gp, mp);
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
