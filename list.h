typedef struct node {
  int value;
  struct node* next;
} Node;

typedef struct header {
  Node* first;
  Node* last;
} List;

List* createList();
Node* createNode();
void addValue(List* list, int value);
void removeValue(List* list, int value);
void printList(List* list);
