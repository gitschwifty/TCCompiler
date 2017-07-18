/**
*
* CodeGenerator.c: function definition for CodeGenerator.h
*
**/

#include "../include/CodeGenerator.h"
#include "AssemblyLib.c"

int cg_start(CodeGenerator *cg, AssemblyLib *al, char filename[])
{
  cg->assLib = malloc(sizeof(AssemblyLib) * 4);
  cg->assLib = al;
  printf("CodeGenerator: %s\n", filename);
  ass_start(cg->assLib, filename);
  return 0;
}
