/*
*
* assemblyLib.h : header file for x86_64 translations from ast
*
*/

#ifndef AssemblyLib_h
#define AssemblyLib_h

typedef struct
{
} AssemblyLib;

int ass_setup()
{
  return 0;
}

int ass_start()
{
  ass_setup();
  return 0;
}

#endif /* AssemblyLib_h */
