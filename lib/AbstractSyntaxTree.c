/**
*
* AbstractSyntaxTree.c: function definitions for AbstractSyntaxTree.h
*
**/

#include "../include/AbstractSyntaxTree.h"

int ast_start(AbstractSyntaxTree *ast, char filename[])
{
  printf("AST: %s\n", filename);
  return 0;
}
