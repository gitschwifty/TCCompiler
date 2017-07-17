/*
*
* CCompiler.c: definition of functions for C Compiler
*
*/

#include "../include/CCompiler.h"
#include "Parser.c"

int comp_run(CCompiler *cc, char filename[])
{
  printf("%s\n", filename);
  par_start(cc->p, filename, cc->ast);
  return 0;
}

int comp_setup()
{
  return 0;
}

int comp_start(CCompiler *cc, Parser *pa, CodeGenerator *c, AbstractSyntaxTree *a)
{
  cc->p = malloc(sizeof(Parser) * 4);
  cc->p = pa;
  cc->cg = malloc(sizeof(CodeGenerator) * 4);
  cc->cg = c;
  cc->ast = malloc(sizeof(AbstractSyntaxTree) * 4);
  cc->ast = a;
  return 0;
}
