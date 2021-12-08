#include "../headers/sommetfunc.h"
#include <stdio.h>

Sommet_t *create_vertex(u_int8_t code)
{
    Sommet_t *v = (Sommet_t *)malloc(sizeof(Sommet_t));

    v->code = code;
    v->succ = NULL;

    return v;
}

void free_vertex(Sommet_t *v)
{
    if (v)
        free(v);
}

void debug_vertex_code(Sommet_t *v)
{
    printf("%d\n", v->code);
}