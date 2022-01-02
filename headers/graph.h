#include "../headers/parser.h"

typedef struct Graph
{
    int size;
    Vertex_t *vertices;
} Graph_t;

Graph_t *createGraph(Matrice_t *m);
void createVertex(int new_inee, Matrice_t *m, Graph_t *g, int *gp);
void createSuccessor(Node_t *n, Data_t d, Matrice_t *m, Graph_t *g, int* gp, int mp);
void freeGraph(Graph_t *g);
float computeDistance(float latA, float lonA, float latB, float lonB);
float toRadians(float deg);
