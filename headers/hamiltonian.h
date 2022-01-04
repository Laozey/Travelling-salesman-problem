#include "../headers/graph.h"

int isSafe(int vertex_inee, Graph_t* graph, int path[], int pos);
void printSolution(int path[], Graph_t* graph);
int hamCycle(Graph_t *graph);
int hamCycleUtil(Graph_t *graph, int *path, int pos);
int isNeighbor(Node_t* neighbor, int wanted_neighbor_inee);
