/**
*
* Parser.c: Function definitions for Parser.h
*
**/

#include "../include/Parser.h"
#include "AbstractSyntaxTree.c"
#include "ParseTable.c"

/**
* par_start: takes parameters parser pointer and ast pointer, and filename
* char array. sets parser's ast pointer to ast, then starts ast.
**/
int par_start(Parser *p, AbstractSyntaxTree *astptr, Table *tptr, char filename[])
{
  printf("Parser: %s\n", filename);
  p->ast = astptr;
  ast_start(p->ast, filename);
  //nextTest(p->ast);
  char newfilename[strlen(filename) + 1];
  strncpy(newfilename, filename, strlen(filename) - 2);
  newfilename[strlen(filename) - 2] = '.';
  newfilename[strlen(filename) - 1] = 'a';
  newfilename[strlen(filename)] = '\0';
  p->newf = fopen(newfilename, "w");
  parse_line(p, "int main()");
  p->table = tptr;
  makeTable(p->table);
  return 0;
}

/**
* getNextIndex: returns the index of the next non-alpha char
* assumes char[0] is alpha and looking for word from char[0]
* to char[return val]
**/
int getNextIndex(char line[])
{
  int i = 0;
  while(isalpha(line[i]))
  {
    i++;
  }
  return i;
}

/**
* parse_word: takes word, adds to AST, checks tokens after word
**/
int parse_word(Parser *p, char word[])
{
  printf("%s\n", word);
  return 0;
}

/**
* parse_line: takes parser and line, parses the line and adds
* each part to the AST
**/
int parse_line(Parser *p, char line[])
{
  if(isalpha(line[0]))
  {
    int j = getNextIndex(line);
    char word[j];
    strncpy(word, line, j);
    word[j] = '\0';
    parse_word(p, word);
    line = &line[j + 1];
    if(!strncmp(word, "int", 3) || !strncmp(word, "char", 4))
    {
      if(isalpha(line[0]))
      {
        j = getNextIndex(line);
        char wordTwo[j];
        strncpy(wordTwo, line, j);
        wordTwo[j] = '\0';
        parse_word(p, wordTwo);
        if(line[j] == '(' && line[j + 1] == ')')
        {
          //add in structure function with return type token word to ast

        }
        else if(line[j] == ';')
        {
          //add in structure variable with type token word to ast
        }
      }
    }
  }
  return 1;
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
