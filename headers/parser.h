#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/vertexfunc.h"

#define INEE_MIN 95002
#define INEE_MAX 95690
#define SIZE (INEE_MAX - INEE_MIN + 1)

typedef struct Data
{
    int isAlocated;
    int inee;
    float lat;
    float lon;
    int nb_neighbors;
    int *neighbors;
} Data_t;

typedef struct Matrice
{
    int size;
    Data_t *datas;
} Matrice_t;

Matrice_t *parseFile(const char *file_path);
void treatLine(Matrice_t *matrice, char *line);
void freeData(Matrice_t *matrice);
int isInDepartement(const char *departement, char *inee);