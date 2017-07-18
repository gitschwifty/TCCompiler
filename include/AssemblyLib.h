/*
*
* assemblyLib.h : header file for x86_64 translations from ast
*
*/

#ifndef AssemblyLib_h
#define AssemblyLib_h

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
} AssemblyLib;

int ass_setup();
int ass_start(AssemblyLib *al, char filename[]);

#endif /* AssemblyLib_h */
