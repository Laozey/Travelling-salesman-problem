#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../headers/linkedlist.h"

int main(void)
{
   Vertex_t* v = create_vertex(42);

   debug_vertex_code(v);

   free_vertex(v);
   
   return 0;
}
