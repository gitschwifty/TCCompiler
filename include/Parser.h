/**
*
* Header file for parser
*
**/

#ifndef Parser_h
#define Parser_h

#include "AbstractSyntaxTree.h"
#include "ParseTable.h"
#include <ctype.h>

typedef struct
{
  AbstractSyntaxTree *ast;
  FILE *newf;
  Table *table;
} Parser;

int par_setup();
int par_start(Parser *p, AbstractSyntaxTree *astptr, Table *tptr, char filename[]);
int file_parse(Parser *p, char filename[]);
int p_file_write(Parser *p, char linetowrite[]);
int parse_line(Parser *p, char line[]);
int parse_word(Parser *p, char word[]);
int parse_token(Parser *p, char token);
int getNextIndex(char line[]);


#endif /* !Parser_h */
