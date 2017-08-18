/**
*
* AbstractSyntaxTree.h : Header file for c to ast translations
*
**/

#ifndef AbstractSyntaxTree_h
#define AbstractSyntaxTree_h

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

typedef struct
{
  char name[30];
} Head;

typedef struct
{
  char val[256];
} String;

typedef struct
{
  char val;
} Character;

typedef struct
{
  int val;
} Integer;

typedef struct
{
  char op[20];
  void *ptrOne;
} UnaryOp;

typedef struct
{
  char *op;
  Integer *ptrOne, *ptrTwo;
} BinaryOp;

typedef struct
{
  char op[20];
  void *ptrOne, *ptrTwo, *ptrThree;
} TernaryOp;

typedef struct
{
  char func_name[50];
  void *operands[];
} Function;

typedef struct
{
  struct Node *head, *current;
} AbstractSyntaxTree;

int ast_setup();
int ast_start(AbstractSyntaxTree *ast, char filename[]);
void insertBinaryOp(struct Node *current, char data[], int p);
void insertInt(struct Node *current, int *data, int p);
void insertUnaryOp(struct Node *current, char data[], int p);
void insertString(struct Node *current, char data[], int p);
void nextTest(AbstractSyntaxTree *ast);

#endif /* AbstractSyntaxTree_h */
