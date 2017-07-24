/**
*
* Parser.c: Function definitions for Parser.h
*
**/

#include "../include/Parser.h"
#include "AbstractSyntaxTree.c"

/**
* par_start: takes parameters parser pointer and ast pointer, and filename
* char array. sets parser's ast pointer to ast, then starts ast.
**/
int par_start(Parser *p, AbstractSyntaxTree *astptr, char filename[])
{
  printf("Parser: %s\n", filename);
  p->ast = astptr;
  ast_start(p->ast, filename);
  //vectorTest(p->ast); replace with nextTest
  nextTest(p->ast);
  char newfilename[strlen(filename) + 1];
  strncpy(newfilename, filename, strlen(filename) - 2);
  newfilename[strlen(filename) - 2] = '.';
  newfilename[strlen(filename) - 1] = 'a';
  newfilename[strlen(filename)] = '\0';
  p->newf = fopen(newfilename, "w");
  return 0;
}

/**
* file_parse: takes parameters parser pointer and filename array. reads
* file line by line and parses c to ast.
**/
int file_parse(Parser *p, char filename[])
{
  FILE *f = fopen(filename, "r");
  char buff[256];
  while(fgets(buff, sizeof(buff), f))
  {
    if(buff[0] == '/' || buff[0] == '*' || (buff[0] == '/' && buff[1] == '/'))
    {
      printf("Comment: ");
    }
    else
    {
      printf("Code: ");
      p_file_write(p, buff);
    }
    printf("%s", buff);
  }
  fclose(f);
  return 0;
}

/**
* p_file_write: takes parameters parser pointer and linetowrite char array.
* writes linetowrite to next line in parser's file pointer.
* returns 0 if correct write, -1 if write incorrect.
**/
int p_file_write(Parser *p, char linetowrite[])
{
  size_t c = fwrite(linetowrite, 1, strlen(linetowrite), p->newf);
  if(c == strlen(linetowrite))
  {
    return 0;
  }
  else
  {
    return -1;
  }
}
