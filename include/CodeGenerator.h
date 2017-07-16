/**
*
* Header file for code generator
*
**/

#ifndef CodeGenerator_h
#define CodeGenerator_h

#include "AssemblyLib.h"

class CodeGenerator
{
private:
  AssemblyLib assLib;
  int setup();
public:
  int start();
}

int setup()
{
  assLib.start();
}

int start()
{
  setup();
}

#endif /* CodeGenerator_h */
