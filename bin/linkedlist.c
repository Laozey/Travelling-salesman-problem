#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../headers/linkedlist.h"

// TODO: tout changer en fonction du fichier .h

Linkedlist_t *create_list(char *p, int city_count)
{
    Linkedlist_t *lst = (Linkedlist_t *)malloc(sizeof(Linkedlist_t));
    assert(lst);
    lst->city_count = 0;
    lst->cities = (City_t **)malloc(sizeof(City_t *) * city_count);
    assert(lst->cities);

    char *line = NULL, code[6], nc[2];
    size_t len = 0;
    ssize_t read;
    FILE *fd;

    fd = fopen(p, "r");

    if (fd == NULL)
        exit(EXIT_FAILURE);

    if ((read = getline(&line, &len, fd)) != -1)
    {
        strncpy(code, line, 5);
        code[5] = '\0';
        strncpy(nc, line + 5, 1);
        nc[1] = '\0';
        add_cities(lst, atoi(code), atoi(nc), line + 6);
    }

    if (line)
        free(line);

    fclose(fd);

    return lst;
}

void add_cities(Linkedlist_t *l, int code, int nc, char *neigh)
{
    char neighbor[6];
    int offset = 0;
    City_t *c = (City_t *)malloc(sizeof(City_t));
    assert(c);
    c->code = code - 95500;
    c->neighbor_count = nc;
    c->neighbours = (u_int8_t *)malloc(sizeof(u_int8_t) * c->neighbor_count);
    assert(c->neighbours);

    for (size_t i = 0; i < c->neighbor_count; i++)
    {
        strncpy(neighbor, neigh + offset, 5);
        neighbor[5] = '\0';
        c->neighbours[i] = atoi(neighbor);

        offset += 5;
    }

    l->cities[l->city_count] = c;
    l->city_count += 1;
}

void free_city(City_t *c)
{
    free(c->neighbours);
    free(c);
}

void free_linkedlist(Linkedlist_t *l)
{
    for (size_t i = 0; i < l->city_count; i++)
    {
        free_city(l->cities[i]);
    }
    free(l->cities);
    free(l);
}
