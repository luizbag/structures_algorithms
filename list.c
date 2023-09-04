#include<stdlib.h>
#include "list.h"

List* createList() {
  List* list = malloc(sizeof(List));
  list->first = NULL;
  list->last = NULL;
  return list;
}

Node* createNode() {
  Node* node = malloc(sizeof(Node));
  node->value = 0;
  node->next = NULL;
  return node;
}

void addValue(List* list, int value) {
  Node* node = createNode();
  node->value = value;
  if(list->first == NULL) {
    list->first = node;
    list->last = node;
    return;
  }
  list->last->next = node;
  list->last = node;
}

void removeValue(List* list, int value) {
  Node* node = list->first;
  Node* prev;
  while(node != NULL) {
    if(node->value == value)
      break;
    prev = node;
    node = node->next;
  }
  if(prev == NULL) {
    list->first = node->next;
    return;
  }
  if(node->next == NULL) {
    list->last = prev;
  }
  prev->next = node->next;
  free(node);
}

void printList(List* list) {
  Node* node = list->first;
  while(node != NULL) {
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n");
}
  
