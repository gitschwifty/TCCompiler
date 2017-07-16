/**
*
* Header file for code generator
*
**/

#ifndef CodeGenerator_h
#define CodeGenerator_h

#include "AssemblyLib.h"

typedef struct
{
  AssemblyLib assLib;
} CodeGenerator;

int cg_setup()
{
  ass_start();
  return 0;
}

int cg_start()
{
  cg_setup();
  return 0;
}

#endif /* CodeGenerator_h */
