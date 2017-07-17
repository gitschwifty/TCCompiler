/**
*
* Header file for parser
*
**/

#ifndef Parser_h
#define Parser_h

#include "AbstractSyntaxTree.h"
#include <stdlib.h>

typedef struct
{
  AbstractSyntaxTree *ast;
} Parser;

int par_setup();
int par_start(Parser *p, char filename[], AbstractSyntaxTree *astptr);

#endif /* !Parser_h */
