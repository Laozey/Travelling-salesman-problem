#include "../headers/parser.h"

Data_t **parseFile(const char *file_path, const char *departement, int INEE_MIN, int size)
{
    FILE *fp = fopen(file_path, "r");
    assert(fp);

    Data_t **data = malloc(sizeof(Data_t *) * size);
    for (int i = 0; i < size; i++)
    {
        data[i] = malloc(sizeof(Data_t));
        data[i]->inee = -1;
    }
    assert(data);

    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, fp)) != -1)
    {
        treatLine(data, line, departement, INEE_MIN);
    }

    if (line)
        free(line);

    fclose(fp);
    return data;
}

void treatLine(Data_t **data, char *line, const char *departement, int INEE_MIN)
{
    const char *separators = ",";
    char* inee_neighbor;
    int code, idx, nbn;
    char *inee_s = strtok(line, separators);
    if (!isInDepartement(departement, inee_s))
        return;
    code = atoi(inee_s);
    idx = code - INEE_MIN;
    data[idx]->inee = code;
    data[idx]->lat = atof(strtok(NULL, separators));
    data[idx]->lon = atof(strtok(NULL, separators));

    nbn = atoi(strtok(NULL, separators));
    data[idx]->nb_neighbors = nbn;
    data[idx]->neighbors = malloc(sizeof(int) * nbn);
    assert(data[idx]->neighbors);
    do
    {
        inee_neighbor = strtok(NULL, separators);
        if (isInDepartement(departement, inee_neighbor))
            data[idx]->neighbors[--nbn] = atoi(inee_neighbor);
        else
            data[idx]->neighbors[--nbn] = -1;
    } while (nbn);
    data[idx]->isAlocated = NULL;
}

void freeData(Data_t **data, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i]->inee != -1)
            free(data[i]->neighbors);
        free(data[i]);
    }
    free(data);
}

int isInDepartement(const char *departement, char *inee)
{
    if (memcmp(departement, inee, 2) == 0)
        return 1;
    return 0;
}
