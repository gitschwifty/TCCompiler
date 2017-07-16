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

class CCompiler
{
private:
  Parser p;
  CodeGenerator cg;
  AbstractSyntaxTree ast;
  int setup ();
public:
  int run(char filename[]);
  int start();
}

int run(char filename[])
{
  std::cout << filename << "\n";
}

int setup()
{
  p.start();
  cg.start();
}

int start()
{
  setup();
}

#endif /* !CCompiler_h */
