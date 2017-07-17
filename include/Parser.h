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

int par_setup();
int par_start();

#endif /* !Parser_h */
