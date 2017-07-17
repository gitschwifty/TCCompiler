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

int cg_setup();
int cg_start();

#endif /* CodeGenerator_h */
