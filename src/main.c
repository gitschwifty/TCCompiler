/**
*
* Main file for C compiler.
*
**/

#include "../lib/CCompiler.c"

int main(int argc, char *argv[])
{
  CCompiler ccomp,*cptr;
  Parser p, *pptr;
  CodeGenerator cg, *cgptr;
  AbstractSyntaxTree ast, *astptr;
  AssemblyLib al, *alptr;
  cptr = malloc(sizeof(CCompiler) * 4);
  cptr = &ccomp;
  pptr = malloc(sizeof(Parser) * 4);
  pptr = &p;
  cgptr = malloc(sizeof(CodeGenerator) * 4);
  cgptr = &cg;
  astptr = malloc(sizeof(AbstractSyntaxTree) * 4);
  astptr = &ast;
  alptr = malloc(sizeof(AssemblyLib) * 4);
  alptr = &al;
  comp_start(cptr, pptr, cgptr, astptr, alptr);
  comp_run(cptr, "test.c");
  return 0;
}
