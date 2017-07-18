/**
*
* Main file for C compiler.
*
**/

#include "../lib/CCompiler.c"

int main(int argc, char *argv[])
{
  CCompiler ccomp,*cptr;
  cptr = malloc(sizeof(CCompiler) * 4);
  cptr = &ccomp;
  comp_start(cptr);
  comp_run(cptr, "test.c");
  return 0;
}
