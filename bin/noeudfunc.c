#include "../headers/sommetfunc.h"

Noeud_t *create_noeud()
{
    Noeud_t *c = (Noeud_t *)malloc(sizeof(Noeud_t));

    c->s = NULL;
    c->next = NULL;

    return c;
}

void free_noeud(Noeud_t *c)
{
    if (c)
    {
        if (c->s)
            free_sommet(c->s);
        if (c->next)
            free_noeud(c->next);
        free(c);
    }
}

Successeur *creer_successeur(u_int8_t city_count)
{
    Successeur *l = (Successeur *)malloc(sizeof(Successeur) * city_count);

    return l;
}

void free_successeur(Successeur *l)
{
    free_noeud(*l);
    free(l);
}