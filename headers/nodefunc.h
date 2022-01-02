typedef struct Node
{
    struct Vertex *v;
    float dist;
    struct Node *next;
} Node_t;
