#include "../headers/parser.h"

Matrice_t *parseFile(const char *file_path)
{
    FILE *fp = fopen(file_path, "r");
    assert(fp);

    Matrice_t *matrice = malloc(sizeof(Matrice_t));
    matrice->datas = malloc(sizeof(Data_t) * SIZE);
    matrice->size = 0;
    assert(matrice);

    // used to delocate neighbors in free
    for (int i = 0; i < SIZE; i++)
    {
        matrice->datas[i].inee = -1;
    }

    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, fp)) != -1)
    {
        treatLine(matrice, line);
    }

    if (line)
        free(line);

    fclose(fp);
    return matrice;
}

void treatLine(Matrice_t *matrice, char *line)
{
    const char *separators = ",";
    char *inee_neighbor;
    int code, idx, nbn;

    char *inee_s = strtok(line, separators);
    if (!isInDepartement("95", inee_s))
        return;
    ++matrice->size;
    code = atoi(inee_s);
    idx = code - INEE_MIN;
    matrice->datas[idx].inee = code;
    matrice->datas[idx].lat = atof(strtok(NULL, separators));
    matrice->datas[idx].lon = atof(strtok(NULL, separators));

    nbn = atoi(strtok(NULL, separators));
    matrice->datas[idx].neighbors = malloc(sizeof(int) * nbn);
    matrice->datas[idx].nb_neighbors = nbn;
    assert(matrice->datas[idx].neighbors);
    do
    {
        inee_neighbor = strtok(NULL, separators);
        if (isInDepartement("95", inee_neighbor))
            matrice->datas[idx].neighbors[--nbn] = atoi(inee_neighbor);
        else
            matrice->datas[idx].neighbors[--nbn] = -1;
    } while (nbn);
    matrice->datas[idx].isAlocated = -1;
}

void freeData(Matrice_t *matrice)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (matrice->datas[i].inee != -1)
            free(matrice->datas[i].neighbors);
    }
    free(matrice->datas);
    free(matrice);
}

int isInDepartement(const char *departement, char *inee)
{
    if (memcmp(departement, inee, 2) == 0)
        return 1;
    return 0;
}
