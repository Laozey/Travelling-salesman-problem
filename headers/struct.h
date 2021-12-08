#include <stdlib.h>

typedef struct Sommet Sommet_t;

typedef struct Noeud
{
    Sommet_t *s;
    struct Noeud *next;
} Noeud_t;
typedef Noeud_t *Successeur;

typedef struct Sommet
{
    u_int8_t code;
    float distance;
    Successeur succ;
} Sommet_t;