/**
*
* Header file for parser
*
**/

#ifndef Parser_h
#define Parser_h

#include "AbstractSyntaxTree.h"

typedef struct
{
  AbstractSyntaxTree ast;
} Parser;

int par_setup()
{
  ast_start();
  return 0;
}

int par_start()
{
  par_setup();
  return 0;
}

#endif /* !Parser_h */
