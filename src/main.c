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
  cptr = malloc(sizeof(CCompiler) * 4);
  cptr = &ccomp;
  pptr = malloc(sizeof(Parser) * 4);
  pptr = &p;
  cgptr = malloc(sizeof(CodeGenerator) * 4);
  cgptr = &cg;
  astptr = malloc(sizeof(AbstractSyntaxTree) * 4);
  astptr = &ast;
  comp_start(cptr, pptr, cgptr, astptr);
  comp_run(cptr, "test.c");
  return 0;
}
