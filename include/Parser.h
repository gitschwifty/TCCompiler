/**
*
* Header file for parser
*
**/

#ifndef Parser_h
#define Parser_h

#include "AbstractSyntaxTree.h"
#include <string.h>

typedef struct
{
  AbstractSyntaxTree *ast;
  FILE *newf;
} Parser;

int par_setup();
int par_start(Parser *p, AbstractSyntaxTree *astptr, char filename[]);
int file_parse(Parser *p, char filename[]);
int p_file_write(Parser *p, char linetowrite[]);

#endif /* !Parser_h */
