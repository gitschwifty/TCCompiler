/**
*
* AbstractSyntaxTree.h : Header file for c to ast translations
*
**/

#ifndef AbstractSyntaxTree_h
#define AbstractSyntaxTree_h

#include <stdio.h>

typedef struct
{
} AbstractSyntaxTree;

int ast_setup();
int ast_start(AbstractSyntaxTree *ast, char filename[]);

#endif /* AbstractSyntaxTree_h */
