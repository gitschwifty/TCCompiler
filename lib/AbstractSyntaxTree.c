/**
*
* AbstractSyntaxTree.c: function definitions for AbstractSyntaxTree.h
*
**/

#include "../include/AbstractSyntaxTree.h"

//p 0 is left, p 1 is right, p 2 is next
void insertString(struct Node *current, char data[], int p)
{
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->token = STRING;
  temp->parent = current;
  temp->left = NULL;
  temp->right = NULL;
  temp->next = NULL;
  temp->hasNext = 0;
  if(p == 0)
  {
    current->left = temp;
  }
  else if(p == 1)
  {
    current->right = temp;
  }
  else if(p == 2)
  {
    addNext(current, temp);
    if(current->right == NULL && current->left != temp)
    {
      current->right = temp;
    }
  }
}

void insertInt(struct Node *current, int *data, int p)
{
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->token = INT;
  temp->parent = current;
  temp->left = NULL;
  temp->right = NULL;
  temp->next = NULL;
  temp->hasNext = 0;
  if(p == 0)
  {
    current->left = temp;
  }
  else if(p == 1)
  {
    current->right = temp;
  }
  else if(p == 2)
  {
    addNext(current, temp);
    if(current->right == NULL && current->left != temp)
    {
      current->right = temp;
    }
  }
}

void insertUnaryOp(struct Node *current, char data[], int p)
{
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->token = UNARY_OP;
  temp->parent = current;
  temp->left = NULL;
  temp->right = NULL;
  temp->next = NULL;
  temp->hasNext = 0;
  if(p == 0)
  {
    current->left = temp;
  }
  else if(p == 1)
  {
    current->right = temp;
  }
  else if(p == 2)
  {
    addNext(current, temp);
    if(current->right == NULL && current->left != temp)
    {
      current->right = temp;
    }
  }
}

void insertBinaryOp(struct Node *current, char data[], int p)
{
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->token = BINARY_OP;
  temp->parent = current;
  temp->left = NULL;
  temp->right = NULL;
  temp->next = NULL;
  temp->hasNext = 0;
  if(p == 0)
  {
    current->left = temp;
  }
  else if(p == 1)
  {
    current->right = temp;
  }
  else if(p == 2)
  {
    addNext(current, temp);
    if(current->right == NULL && current->left != temp)
    {
      current->right = temp;
    }
  }
}

/**
* ast_start: takes parameters ast pointer and filename array. starts
* the ast.
**/
int ast_start(AbstractSyntaxTree *ast, char filename[])
{
  printf("AST: %s\n", filename);
  struct Node h;
  struct Node *current;
  ast->head = &h;
  current = &h;
  current->hasNext = 0;
  int iOne = 3;
  int iTwo = 5;
  int iThree = 0;
  int *ipO, *ipT;
  ipO = &iOne;
  ipT = &iTwo;
  insertBinaryOp(current, "add", 0);
  insertInt(current->left, ipO, 0);
  insertInt(current->left, ipT, 1);
  insertUnaryOp(current, "printf", 1);
  char t[] = "hello world";
  insertString(current->right, t, 0);
  printf("op node 1: %s\n", (char*)current->left->data);
  printf("op node left: %d\n", *(int*)current->left->left->data);
  printf("op node right: %d\n", *(int*)current->left->right->data);
  printf("op node 2: %s\n", (char*)current->right->data);
  printf("op node 2 val: %s\n", (char*)current->right->left->data);
  return 0;
}

/**
* nextTest: takes param ast, tests next node structure
**/
void nextTest(AbstractSyntaxTree *ast)
{
  struct Node h;
  struct Node *current;
  ast->head = &h;
  current = &h;
  insertUnaryOp(current, "add", 0);
  current = current->left;
  int iOne, iTwo, iThree, iFour, iFive;
  int *ipt;
  iOne = 0;
  iTwo = 1;
  iThree = 2;
  iFour = 3;
  iFive = 4;
  ipt = &iOne;
  insertInt(current, ipt, 2);
  ipt = &iTwo;
  insertInt(current, ipt, 2);
  ipt = &iThree;
  insertInt(current, ipt, 2);
  ipt = &iFour;
  insertInt(current, ipt, 2);
  ipt = &iFive;
  insertInt(current, ipt, 2);
  traverseNext(current->left);
}
