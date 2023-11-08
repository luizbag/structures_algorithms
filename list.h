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

List* createList(); //done
void destroyList(List **list); //done
Node* createNode(int value); //done
void addFirst(List* list, int value); //done
void addLast(List* list, int value); //done
void addAt(List* list, int position, int value); //done
int removeFirst(List* list); //done
int removeLast(List* list); //done
int removeAt(List* list, int position); //done
int find(List* list, int value); //done
Node* getNodeAt(List* list, int position); //done
int getValueAt(List* list, int position); //done
void printList(List* list); //done
