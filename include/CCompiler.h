/**
*
* Header file for C Compiler : basic rundown
* takes file in from main
* current: one file, has to be main.c
* passes main.c to parser (one line or all at once?)
* parser uses ast and turns main into ast
* ast is passed back to main
* main passes ast to the codegenerator
* code generator uses x86_64 header (not made yet) and turns ast into
* assembly
* assembly is passed back to main
* main finishes after saving the assembly as a .s file with same name
* bash outer shell links and compiles assembly
*
**/

#ifndef CCompiler_h
#define  CCompiler_h

#include "Parser.h"
#include "CodeGenerator.h"

typedef struct
{
  Parser pars, *p;
  CodeGenerator c, *cg;
  AbstractSyntaxTree a, *ast;
  AssemblyLib assem, *assLib;
} CCompiler;

int comp_run(CCompiler *cc, char filename[]);
int comp_setup();
int comp_start(CCompiler *cc);
int file_read(CCompiler *cc, char filename[]);

#endif /* !CCompiler_h */
