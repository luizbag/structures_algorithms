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

void addAt(List* list, int position, int value) {
  if(list == NULL)
    return;
  if(position <= 0) {
    addFirst(list, value);
    return;
  }
  if(position >= list->length) {
    addLast(list, value);
    return;
  }
  Node* new = createNode(value);
  Node* current = getNodeAt(list, position);
  new->prev = current;
  new->next = current->next;
  current->next = new;
  new->next->prev = new;
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
  if(list == NULL || list->last == NULL)
    return -1;
  Node* node = list->last;
  int value = node->value;
  list->last = node->prev;
  if(node->prev != NULL)
    list->last->next = NULL;
  list->length--;
  free(node);
  return value;
}

int removeAt(List* list, int position) {
  if(list == NULL)
    return -1;
  if(position <= 0)
    return removeFirst(list);
  if(position >= list->length)
    return removeLast(list);
  Node* old = getNodeAt(list, position);
  int value = old->value;
  Node* next = old->next;
  Node* prev = old->prev;
  prev->next = next;
  next->prev = prev;
  list->length--;
  free(old);
  return value;
}

int find(List* list, int value) {
  if(list == NULL)
    return -1;
  Node* current = list->first;
  int i=0;
  while(i<list->length) {
    if(current->value == value)
      return i;
    current = current->next;
    i++;
  }
}

Node* getNodeAt(List* list, int position) {
  if(list == NULL)
    return NULL;
  if(position <= 0) {
    return list->first;
  }
  if(position >= list->length) {
    return list->last;
  }
  Node* current = list->first;
  int i=1;
  while(i<position+1) {
    current = current->next;
    i++;
  }
  return current;
}

int getValueAt(List* list, int position) {
  return getNodeAt(list, position)->value;
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
  
