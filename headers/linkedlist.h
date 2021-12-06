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

Cell_t* create_cell();
void free_cell(Cell_t*);

Linkedlist_t* create_linkedlist(u_int8_t);
void free_linkedlist(Linkedlist_t*);

Vertex_t *create_vertex(u_int8_t);
void free_vertex(Vertex_t *);
void debug_vertex_code(Vertex_t *);

