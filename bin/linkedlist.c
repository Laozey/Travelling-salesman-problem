#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../headers/linkedlist.h"

Cell_t *create_cell()
{
    Cell_t *c = (Cell_t *)malloc(sizeof(Cell_t));

    c->v = NULL;
    c->next = NULL;

    return c;
}

void free_cell(Cell_t *c)
{
    if (c)
    {
        if (c->v)
            free_vertex(c->v);
        if (c->next)
            free_cell(c->next);
        free(c);
    }
}

Linkedlist_t *create_linkedlist(u_int8_t city_count)
{
    Linkedlist_t *l = (Linkedlist_t *)malloc(sizeof(Linkedlist_t) * city_count);

    return l;
}

void free_linkedlist(Linkedlist_t *l)
{
    free_cell(*l);
    free(l);
}

Vertex_t *create_vertex(u_int8_t code)
{
    Vertex_t *v = (Vertex_t *)malloc(sizeof(Vertex_t));

    v->code = code;
    v->succ = NULL;

    return v;
}

void free_vertex(Vertex_t *v)
{
    if (v)
        free(v);
}

void debug_vertex_code(Vertex_t *v)
{
    printf("%d\n", v->code);
}
