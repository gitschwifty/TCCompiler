/**
* ParseTable.h: header file for parse table, including symbols
* rules and first/follow sets, this will make the parse table.
* this will eventually hold the semantics once figured out
**/

#ifndef ParseTable_h
#define ParseTable_h

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Set Set;

typedef struct Symbol
{
  int isTerm;
  int hasEmpty;
  int valSize;
  char value[1024];
  void *semantics;
  struct Set *fi, *fo;
} Symbol;

typedef struct Set
{
  struct Symbol *set[64];
  int isFirst;
  int curr;
} Set;

typedef struct Rule
{
  struct Symbol *left;
  struct Symbol *rights[64][64];
  int ruleSizes[64];
  int rules;
} Rule;

typedef struct Table
{
  struct Symbol *sym[1024];
  struct Rule *rules[1024];
  int ruleSize;
  int symSize;
} Table;

int isInSet(struct Set *s, struct Symbol *x);
int addAllFromSet(struct Set *addTo, struct Set *addFrom);
int parseFirst(struct Rule *x, int i, int j);
int parseFollow(struct Rule *x, int i, int j);
int firstCalc(struct Rule *x);
int followCalc(struct Rule *x);
struct Symbol* findSymbol(char val[], struct Table *x);
int makeSymbol(char val[], struct Table *x, int term);
int parseCommas(struct Table *x, char *in);
int parseRule(struct Table *x, char rul[]);
int makeTable(struct Table *x);

#endif /**ParseTable_h**/
