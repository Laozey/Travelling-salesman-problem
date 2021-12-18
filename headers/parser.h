#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/vertexfunc.h"

typedef struct Data
{
    Vertex_t *isAlocated;
    int inee;
    float lat;
    float lon;
    int nb_neighbors;
    int *neighbors;
} Data_t;

Data_t **parseFile(const char *file_path, const char *departement, int INEE_MAX, int INEE_MIN);
void treatLine(Data_t **data, char *line, const char *departement, int INEE_MIN);
void freeData(Data_t **data, int size);
int isInDepartement(const char *departement, char *inee);