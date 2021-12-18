#include <stdlib.h>

typedef struct Node
{
    struct Vertex *v;
    float dist;
    struct Node *next;
} Node_t;
typedef Node_t *Successor;

typedef struct Vertex
{
    u_int8_t code;
    Successor succ;
} Vertex_t;
typedef struct Vertex Vertex_t;
