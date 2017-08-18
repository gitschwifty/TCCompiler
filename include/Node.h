/**
*
* Node.h: defines node structure and helper functions
*
**/

#ifndef Node_h
#define Node_h

enum struct_token {VARIABLE, FUNCTION, POINTER, NODE};
enum type_token {INT, DOUBLE, CHAR, STRING, BOOL, UNARY_OP, BINARY_OP, TERN_OP};

struct Node
{
  struct Node *parent;
  struct Node *left;
  struct Node *right;
  struct Node *next;
  struct Node *val;
  enum type_token type;
  enum struct_token structure;
  int hasNext;
  void *data;
};

void addNext(struct Node *current, struct Node *t)
{
  if(current->left == NULL)
  {
    current->left = t;
  }
  else
  {
    current = current->left;
    while(current->next != NULL)
    {
      current = current->next;
    }
    current->next = t;
    current->hasNext = 1;
  }
}

void traverseNext(struct Node *left)
{
  struct Node *t;
  if(left->hasNext)
  {
    t = left;
  }
  while(t->next != NULL)
  {
    printf("%d\n", *(int*)t->data);
    t = t->next;
  }
  printf("%d\n", *(int*)t->data);
}

#endif /** Node_h **/
