#include "../headers/hamiltonian.h"

int main(int argc, char const *argv[])
{
   if (argc != 2)
   {
      printf("usage: ./run <file>\n");
      exit(1);
   }

   Matrice_t *matrice = parseFile(argv[1]);

   Graph_t *graph = createGraph(matrice);

   hamCycle(graph);

   freeData(matrice);
   freeGraph(graph);

   return 0;
}
