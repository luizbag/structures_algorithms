#include<stdio.h>
#include "structs.h"

int main() {
  int i;
  List* list;
  list = createList();
  for(i=0;i<10;i++)
    addLast(list, i+1);
  printList(list);
  addFirst(list, 100);
  printList(list);
  addAt(list, 5, 200);
  printList(list);
  addLast(list, 300);
  printf("Removed Last: %d\n", removeLast(list));
  printList(list);
  printf("Removed First: %d\n", removeFirst(list));
  printList(list);
  int pos = find(list, 200);
  printf("Found 200 at %d\n", pos);
  printf("Value at position %d: %d\n", pos, getValueAt(list, 5));
  printf("Removed At %d: %d\n", pos, removeAt(list, 5));
  printList(list);
  destroyList(&list);
  return 0;
}
