/**
*
* Header file for parser
*
**/

#ifndef Parser_h
#define Parser_h

#include "AbstractSyntaxTree.h"

class Parser
{
private:
  AbstractSyntaxTree ast;
  int setup();
public:
  int start();
}

int setup()
{
  ast.start();
}

int start()
{
  setup();
}

#endif /* !Parser_h */
