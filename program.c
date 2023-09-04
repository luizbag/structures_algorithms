#include<stdio.h>
#include "list.h"

int main() {
  int i;
  List* list;
  list = createList();
  for(i=0;i<10;i++)
    addValue(list, i);
  printList(list);
  removeValue(list, 5);
  printList(list);
  removeValue(list, 0);
  printList(list);
  removeValue(list, 9);
  printList(list);
  addValue(list, 100);
  printList(list);
  return 0;
}
