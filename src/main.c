/**
*
* Main file for C compiler.
*
**/

#include "../include/CCompiler.h"

int main(int argc, char *argv[])
{
  CCompiler c;
  comp_run("test.c");
  return 0;
}
