#include "../headers/vertexfunc.h"

Node_t *create_node()
{
    Node_t *c = (Node_t *)malloc(sizeof(Node_t));

    c->s = NULL;
    c->next = NULL;

    return c;
}

void free_node(Node_t *c)
{
    if (c)
    {
        if (c->s)
            free_vertex(c->s);
        if (c->next)
            free_node(c->next);
        free(c);
    }
}

Successor *create_successor(u_int8_t city_count)
{
    Successor *l = (Successor *)malloc(sizeof(Successor) * city_count);

    return l;
}

void free_successor(Successor *l)
{
    free_node(*l);
    free(l);
}