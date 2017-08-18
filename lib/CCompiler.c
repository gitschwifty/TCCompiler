/*
*
* CCompiler.c: definition of functions for C Compiler
*
*/

#include "../include/CCompiler.h"
#include "Parser.c"
#include "CodeGenerator.c"

/**
* file_read: Takes parameters CCompiler pointer cc, and filename
* array. Passes to parser to read line by line.
**/
int file_read(CCompiler *cc, char filename[])
{
  file_parse(cc->p, filename);
  return 0;
}

/**
* comp_run: takes parameters CCompiler pointer cc and filename array
* starts parser and code generator, then calls file_read
**/
int comp_run(CCompiler *cc, char filename[])
{
  printf("Compiler: %s\n", filename);
  par_start(cc->p, cc->ast, cc->ptable, filename);
  cg_start(cc->cg, cc->assLib, filename);
  file_read(cc, filename);
  return 0;
}

/**
* comp_setup: idk placeholder
**/
int comp_setup()
{
  return 0;
}

/**
* comp_start: takes parameter CCompiler pointer cc, and assigns
* all its pointers to the correct part of the compiler
**/
int comp_start(CCompiler *cc)
{
  cc->cg = &cc->c;
  cc->p = &cc->pars;
  cc->ast = &cc->a;
  cc->assLib = &cc->assem;
  cc->ptable = &cc->tab;
  return 0;
}
