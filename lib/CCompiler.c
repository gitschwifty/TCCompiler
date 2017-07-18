/*
*
* CCompiler.c: definition of functions for C Compiler
*
*/

#include "../include/CCompiler.h"
#include "Parser.c"
#include "CodeGenerator.c"

int file_read(CCompiler *cc, char filename[])
{
  FILE *f = fopen(filename, "r");
  char buff[256];
  while(fgets(buff, sizeof(buff), f))
  {
    printf("%s", buff);
  }
  fclose(f);
  return 0;
}

int comp_run(CCompiler *cc, char filename[])
{
  printf("Compiler: %s\n", filename);
  par_start(cc->p, cc->ast, filename);
  cg_start(cc->cg, cc->assLib, filename);
  file_read(cc, filename);
  return 0;
}

int comp_setup()
{
  return 0;
}

int comp_start(CCompiler *cc, Parser *pa, CodeGenerator *c, AbstractSyntaxTree *a, AssemblyLib *al)
{
  cc->p = pa;
  cc->cg = c;
  cc->ast = a;
  cc->assLib = al;
  return 0;
}
