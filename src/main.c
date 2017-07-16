/**
*
* Main file for C compiler.
*
**/

#include "../include/CCompiler.h"

int main(int argv, char **argv)
{
  CCompiler c;
  c.run("test.c");
  return 0;
}
