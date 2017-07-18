/**
*
* CodeGenerator.c: function definition for CodeGenerator.h
*
**/

#include "../include/CodeGenerator.h"
#include "AssemblyLib.c"

/**
* cg_start: takes parameters codegenerator pointer and assembly lib pointer.
* and filename array. sets cg asslib pointer to current asslib, and starts
* the assembly library.
**/
int cg_start(CodeGenerator *cg, AssemblyLib *al, char filename[])
{
  cg->assLib = al;
  printf("CodeGenerator: %s\n", filename);
  ass_start(cg->assLib, filename);
  return 0;
}
