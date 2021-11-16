#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../headers/linkedlist.h"

int main(void)
{
   Linkedlist_t *lst = create_list("./data/cities", 1);
   
   free_linkedlist(lst);
   
   return 0;
}
