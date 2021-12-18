#include "../headers/vertexfunc.h"

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

void print_vertex_code(Vertex_t *v)
{
    printf("%d\n", v->code);
}