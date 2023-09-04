#include<stdio.h>
#include "structs.h"

int main() {
  int i;
  List* list;
  list = createList();
  for(i=0;i<10;i++)
    addLast(list, i+1);
  printList(list);
  printf("List %d\n", list);
  destroyList(list);
  printf("NULL %d\n", list);
  return 0;
}
