/**
* ParseTable.c: main file for parse table, including all functions
* meant to create the parse table from a set of rules in specific
* formatting
**/

#include "../include/ParseTable.h"

/**
* isInSet: takes set pointer s and symbol pointer x, and checks
* the set to see if x is already in the set. returns 1 if true
* 0 if false
**/
int isInSet(struct Set *s, struct Symbol *x)
{
  for(int i = 0; i < s->curr; i++)
  {
    if(strcmp(x->value, s->set[i]->value) == 0)
    {
      return 1;
    }
  }
  return 0;
}

/**
* addAllFromSet: takes set pointers addTo and addFrom, adds
* all symbols from addFrom to addTo. returns 1 if changes, 0
* if none
**/
int addAllFromSet(struct Set *addTo, struct Set *addFrom)
{
  int z = 0;
  for(int i = 0; i < addFrom->curr; i++)
  {
    if(!isInSet(addTo, addFrom->set[i]))
    {
      addTo->set[addTo->curr++] = addFrom->set[i];
      z = 1;
    }
  }
  return z;
}

/**
* parseFirst: takes pointer to current rule x, and the current spots
* in different right-sides for rules ints i and j. return 0 for no
* changes, 1 for changes
**/
int parseFirst(struct Rule *x, int i, int j)
{
  int z = 0;
  if(x->rights[i][j]->isTerm)
  {
    if(!isInSet(x->left->fi, x->rights[i][j]))
    {
      z = 1;
      x->left->fi->set[x->left->fi->curr++] = x->rights[i][j];
      if(strcmp(x->left->fi->set[x->left->fi->curr]->value, "_empty") == 0)
      {
        x->left->hasEmpty = 1;
      }
    }
  }
  else
  {
    z = addAllFromSet(x->left->fi, x->rights[i][j]->fi);
    if(x->rights[i][j]->hasEmpty)
    {
      return parseFirst(x, i, j + 1);
    }
  }
  return z;
}

/**
* parseFollow: takes pointer to current rule x, and ints i and j
* current position in rules and right hand side
**/
int parseFollow(struct Rule *x, int i, int j)
{
  int z = 0;
  if(!(x->rights[i][0]->isTerm) && x->rights[i][1]->isTerm)
  {
    if(!(isInSet(x->rights[i][0]->fo, x->rights[i][1])))
    {
      z = 1;
      x->rights[i][0]->fo->set[x->rights[i][0]->fo->curr++] = x->rights[i][1];
    }
  }
  else if(!(x->rights[i][0]->isTerm && x->rights[i][1]->isTerm))
  {
    z = addAllFromSet(x->rights[i][0]->fo, x->rights[i][0]->fi);
    if(x->rights[i][0]->hasEmpty)
    {
      int y = addAllFromSet(x->rights[0][1]->fo, x->left->fo);
      if(y)
      {
        z = 1;
      }
    }
  }
  return z;
}

/**
* firstCalc: takes pointer to current rule, parses the first
* set for left hand side of rule, return 0 no changes, 1 changes
**/
int firstCalc(struct Rule *x)
{
  int z = 0;
  int y = 0;
  for(int i = 0; i < x->rules; i++)
  {
    y = parseFirst(x, i, 0);
    if(y)
    {
      z = 1;
    }
  }
  return z;
}

/**
* followCalc: takes pointer to current rule, parses the follow
* set for non-terminals in right-sides of rules
**/
int followCalc(struct Rule *x)
{
  int z = 0;
  int y = 0;
  for(int i = 0; i < x->rules; i++)
  {
    y = parseFollow(x, i, 0);
    if(y)
    {
      z = 1;
    }
  }
  return z;
}

/**
* findSymbol: takes value of symbol and the table, returns
* a pointer to the symbol with value, throws error if not (?)
**/
struct Symbol* findSymbol(char val[], struct Table *x)
{
  for(int i = 0; i < x->symSize; i++)
  {
    if(strcmp(val, x->sym[i]->value) == 0)
    {
      return x->sym[i];
    }
  }
  return NULL;
}

/**
* makeSymbol: takes char val, table pointer
* adds symbol with val to table
**/
int makeSymbol(char val[], struct Table *x)
{
  x->sym[x->symSize] = malloc(sizeof(Symbol));
  if(strstr(val, "symbol") != NULL)
  {
    x->sym[x->symSize]->isTerm = 1;
  }
  else
  {
    x->sym[x->symSize]->isTerm = 0;
  }
  x->sym[x->symSize]->valSize = strlen(val) + 1;
  strncpy(x->sym[x->symSize]->value, val, x->sym[x->symSize]->valSize - 1);
  x->sym[x->symSize]->value[x->sym[x->symSize]->valSize - 1] = 0;
  x->symSize++;
  return 0;
}

/**
* parseCommas: takes rule r, table x, and char ptr in
* parses a single right side to the left side of said rule
* and adds to rule (only called on right sides with commas)
**/
int parseCommas(Table *x, char *in)
{
  char *p = in;
  char *sp = p;
  while(*p && *p != ';')
  {
    sp = p;
    while(*p && *p != ';' && *p!= ',')
    {
      p++;
      //printf("%c\n", *p);
    }

    char *outTwo = malloc(p - sp + 1);
    strncpy(outTwo, sp, p - sp);
    outTwo[p - sp] = 0;
    printf("Commas: %s\n", outTwo);
    x->rules[x->ruleSize]->rights[x->rules[x->ruleSize]->rules][x->rules[x->ruleSize]->ruleSizes[x->rules[x->ruleSize]->rules]] = findSymbol(outTwo, x);
    while((*p == ',' || *p == ' ') && *p)
    {
      p++;
      //printf("%c\n", *p);
    }
    free(outTwo);
    x->rules[x->ruleSize]->ruleSizes[x->rules[x->ruleSize]->rules]++;
  }
  x->rules[x->ruleSize]->rules++;
  return 0;
}

/**
* parseRule: takes table x and rul char array, adds new rule
* to table with the left side then parses the right side, commas in func
**/
int parseRule(struct Table *x, char rul[])
{
  x->rules[x->ruleSize]->rules = 0;
  for(int i = 0; i < 64; i++)
  {
    x->rules[x->ruleSize]->ruleSizes[i] = 0;
  }
  char *str = rul;
  char *p = rul;

  char *sp = p;
  //start pointer
  while(*p && *p != ':')
  {
    //iterate string to colon token
    p++;
  }

  char *out = malloc(p - sp + 1);
  //allocate out one
  strncpy(out, sp, p-sp);
  out[p - sp] = 0;
  printf("Left: %s\n", out);
  x->rules[x->ruleSize]->left = findSymbol(out, x);
  while(*p && (*p == ':' || *p == ' '))
  {
    //iterate to next non-token non-whitespace character
    p++;
  }
  free(out);


  while(*p && *p != '.')
  {
    char *outOne;
    sp = p;
    //change start pointer to current start

    while(*p != ';' && *p != '.' && *p)
    {
      p++;
      //iterate to next token
    }

    outOne = malloc(p - sp + 1);
    strncpy(outOne, sp, p - sp);
    outOne[p - sp] = 0;
    if(strchr(outOne, ',') != NULL)
    {
      parseCommas(x, outOne);
    }
    else
    {
      printf("No commas: %s\n", outOne);
      x->rules[x->ruleSize]->rights[x->rules[x->ruleSize]->rules][0] = findSymbol(outOne, x);
      x->rules[x->ruleSize]->ruleSizes[x->rules[x->ruleSize]->rules] = 1;
      x->rules[x->ruleSize]->rules++;
    }
    while(*p == ';' || *p == ' ')
    {
      p++;
    }
    free(outOne);
  }
  //x->rules[x->ruleSize] = &r;
  x->ruleSize++;
  return 0;
}

/**
* makeTable: takes table x and test basic functionality
**/
int makeTable(struct Table *x)
{
  x->ruleSize = 0;
  x->symSize = 0;
  makeSymbol("Sadatay", x);
  makeSymbol("my damie symbol", x);
  makeSymbol("three symbol", x);
  makeSymbol("Watata", x);
  char ruleOne[80] = "Watata: Sadatay, my damie symbol; three symbol, my damie symbol; Sadatay.";
  for(int i = 0; i < 4; i++)
  {
    printf("Sym %d is %d: %s\n", i + 1, x->sym[i]->isTerm, x->sym[i]->value);
  }
  parseRule(x, ruleOne);
  printf("Rule left: %s\n", x->rules[0]->left->value);
  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      printf("Rule right %d %d: %s\n", i + 1, j + 1, x->rules[0]->rights[i][j]->value);
    }
  }
  printf("Rule right 3 1: %s\n", x->rules[0]->rights[2][0]->value);
  return 0;
}
