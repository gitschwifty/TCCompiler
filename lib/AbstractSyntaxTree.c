/**
*
* AbstractSyntaxTree.c: function definitions for AbstractSyntaxTree.h
*
**/

#include "../include/AbstractSyntaxTree.h"

void insertInt(struct Node *current, enum type_token tok, int *data, int p)
{
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->token = tok;
  temp->parent = current;
  temp->left = NULL;
  temp->right = NULL;
  temp->vect = 0;
  temp->v = NULL;
  if(p == 0)
  {
    current->left = temp;
  }
  else
  {
    current->right = temp;
  }
}

void insertOp(struct Node *current, enum type_token tok, char data[], int p)
{
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->token = tok;
  temp->parent = current;
  temp->left = NULL;
  temp->right = NULL;
  temp->vect = 0;
  temp->v = NULL;
  if(p == 0)
  {
    current->left = temp;
  }
  else
  {
    current->right = temp;
  }
}

int addBinOp(int *iOne, int *iTwo, char op[], struct Node *current)
{
  /*printf("1\n");
  struct Node nTwo = {NULL, NULL, NULL, INT_TYPE, 0, &iOne, NULL};
  printf("2\n");
  struct Node nThree = {NULL, NULL, NULL, INT_TYPE, 0, &iTwo, NULL};
  printf("3\n");
  struct Node nOne = {current, &nOne, &nTwo, OP_TYPE, 0, op, NULL};
  printf("4\n");
  current->left = &nOne;
  printf("5\n");
  nTwo.parent = &nOne;
  printf("6\n");
  nThree.parent = &nOne;
  printf("7\n");*/
  insertOp(current, OP_TYPE, "add", 0);
  insertInt(current->left, INT_TYPE, iOne, 0);
  insertInt(current->left, INT_TYPE, iTwo, 1);

  return 0;
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
  int iOne = 3;
  int iTwo = 5;
  int *ipO, *ipT;
  ipO = &iOne;
  ipT = &iTwo;
  addBinOp(ipO, ipT, "add", current);
  printf("op node: %s\n", (char*)current->left->data);
  printf("op node left: %d\n", *(int*)current->left->left->data);
  printf("op node right: %d\n", *(int*)current->left->right->data);
  return 0;
}
