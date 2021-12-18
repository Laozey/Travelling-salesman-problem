#include "../headers/parser.h"

int main(int argc, char const *argv[])
{
   if (argc != 5)
   {
      printf("usage: ./run <file> <code département> <INEE_MIN> <INEE_MAX>\n");
      exit(1);
   }
   int INEE_MIN = atoi(argv[3]), INEE_MAX = atoi(argv[4]), size = INEE_MAX - INEE_MIN + 1;

   Data_t **data = parseFile(argv[1], argv[2], INEE_MIN, size);
   
   // debug purpose
   // for (int i = 0; i < size; i++) {
   //    if (data[i]->neighbors) {
   //       printf("%d - [%f , %f] {", data[i]->inee, data[i]->lat, data[i]->lon);
   //       for (int j = 0; j < data[i]->nb_neighbors; j++) {
   //          printf(" %d ", data[i]->neighbors[j]);
   //       }
   //       printf("}\n");
   //    }
   // }

   freeData(data, size);

   return 0;
}
