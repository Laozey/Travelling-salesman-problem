#include "../headers/sommetfunc.h"

int main(void)
{
   Sommet_t* v = create_vertex(42);

   debug_vertex_code(v);

   free_vertex(v);
   
   return 0;
}
