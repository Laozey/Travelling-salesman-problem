typedef struct City
{
    u_int8_t code;
    u_int8_t neighbor_count;
    u_int8_t *neighbours;
} City_t;

typedef struct Linkedlist
{
    u_int8_t city_count;
    City_t **cities;
} Linkedlist_t;

Linkedlist_t *create_list(char *, int);

// Prend une chaine de charactère et ajoute cette ville et ses successeurs
void add_cities(Linkedlist_t *, int, int, char *);

void free_city(City_t *);
void free_linkedlist(Linkedlist_t *);
