#include "../headers/graph.h"

int main(int argc, char const *argv[])
{
   if (argc != 2)
   {
      printf("usage: ./run <file>\n");
      exit(1);
   }

   Matrice_t *matrice = parseFile(argv[1]);

   // debug purpose
   int i, j;
   // for (i = 0; i < SIZE; i++)
   // {
   //    if (matrice->datas[i].inee != -1)
   //    {
   //       printf("%d - %d - [%f , %f] {", i, matrice->datas[i].inee, matrice->datas[i].lat, matrice->datas[i].lon);
   //       for (j = 0; j < matrice->datas[i].nb_neighbors; j++)
   //       {
   //          printf(" %d ", matrice->datas[i].neighbors[j]);
   //       }
   //       printf("}\n");
   //    }
   // }
   // printf("%d\n", matrice->size);

   Graph_t *graph = createGraph(matrice);

   // debug purpose
   for (int i = 0; i < graph->size; i++)
   {
      printf("%f\n", graph->vertices[i].succ->dist);
   }

   freeData(matrice);
   // freeGraph(graph);

   return 0;
}
