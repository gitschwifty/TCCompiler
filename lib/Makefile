CCompiler.o: CCompiler.c ../include/CCompiler.h CodeGenerator.o Parser.o
	gcc -c CCompiler.c

AbstractSyntaxTree.o: AbstractSyntaxTree.c ../include/AbstractSyntaxTree.h
	gcc -c AbstractSyntaxTree.c

ParseTable.o: ParseTable.c ../include/ParseTable.h
	gcc -c ParseTable.c

Parser.o: Parser.c ../include/Parser.h AbstractSyntaxTree.o ParseTable.o
	gcc -c Parser.c

AssemblyLib.o: AssemblyLib.c ../include/AssemblyLib.h
	gcc -c AssemblyLib.c

CodeGenerator.o: CodeGenerator.c ../include/CodeGenerator.h AssemblyLib.o
	gcc -c CodeGenerator.c

.PHONY: all clean
all: CCompiler.o

clean:
	rm -f *.o
