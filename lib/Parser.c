/**
*
* Parser.c: Function definitions for Parser.h
*
**/

#include "../include/Parser.h"
#include "AbstractSyntaxTree.c"

int par_start(Parser *p, AbstractSyntaxTree *astptr, char filename[])
{
  printf("Parser: %s\n", filename);
  p->ast = malloc(sizeof(AbstractSyntaxTree) * 4);
  p->ast = astptr;
  ast_start(p->ast, filename);
  return 0;
}
