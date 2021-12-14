#include <stdlib.h>

typedef struct Node
{
    struct Vertex *s;
    struct Node *next;
} Node_t;
typedef Node_t *Successor;

typedef struct Vertex
{
    u_int8_t code;
    float dist;
    Successor succ;
} Vertex_t;
typedef struct Vertex Vertex_t;
