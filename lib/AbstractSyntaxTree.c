/**
*
* AbstractSyntaxTree.c: function definitions for AbstractSyntaxTree.h
*
**/

#include "../include/AbstractSyntaxTree.h"

/**
* ast_start: takes parameters ast pointer and filename array. starts
* the ast.
**/
int ast_start(AbstractSyntaxTree *ast, char filename[])
{
  printf("AST: %s\n", filename);
  return 0;
}
