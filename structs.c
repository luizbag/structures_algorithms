#include<stdlib.h>
#include "structs.h"

List* createList() {
  List* list = malloc(sizeof(List));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
}

void destroyList(List **list) {
  List *pointer = *list;
  int value;
  while(pointer->first != NULL) {
    value = removeFirst(pointer);
  }
  free(pointer);
  *list = NULL;
}

Node* createNode(int value) {
  Node* node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void addFirst(List* list, int value) {
  if(list == NULL)
    return;
  Node* node = createNode(value);
  Node* aux = list->first;
  node->next = aux;
  if(aux != NULL) {
    aux->prev = node;
  } else {
    list->last = node;
  }
  list->first = node;
  list->length++;
}

void addLast(List* list, int value) {
  if(list == NULL)
    return;
  Node* node = createNode(value);
  node->prev = list->last;
  if(list->last != NULL) {
    list->last->next = node;
  } else {
    list->first = node;
  }
  list->last = node;
  list->length++;
}

int removeFirst(List* list) {
  if(list == NULL || list->first == NULL)
    return -1;
  Node* node = list->first;
  int value = node->value;
  list->first = node->next;
  if(node->next != NULL)
    list->first->prev = NULL;
  list->length--;
  free(node);
  return value;
}

int removeLast(List* list) {
  return 0;
}

void printList(List* list) {
  if(list == NULL)
    return;
  Node* node = list->first;
  printf("Length: %d\n", list->length);
  while(node != NULL) {
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n");
}
  
