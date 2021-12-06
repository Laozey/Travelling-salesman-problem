#include <stdlib.h>

typedef struct Vertex Vertex_t;

typedef struct Cell
{
    Vertex_t *v;
    struct Cell *next;
} Cell_t;
typedef Cell_t *Linkedlist_t;

typedef struct Vertex
{
    u_int8_t code;
    Linkedlist_t succ;
} Vertex_t;