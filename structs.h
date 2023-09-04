typedef struct node {
  int value;
  struct node* next;
  struct node* prev;
} Node;

typedef struct header {
  Node* first;
  Node* last;
  int length;
} List;

List* createList();
void destroyList(List *list);
Node* createNode(int value);
void addFirst(List* list, int value);
void addLast(List* list, int value);
void addAt(List* list, int position, int value);
int removeFirst(List* list);
int removeLast(List* list);
int removeAt(List* list, int position);
int find(List* list, int value);
void printList(List* list);
