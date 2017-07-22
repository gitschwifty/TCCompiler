/**
*
* Vector.h: defines dynamic node array for ast and node struct
*
**/

#ifndef Vector_h
#define Vector_h

#define VECTOR_INITIAL_CAPACITY 10
enum type_token {INT_TYPE, DOUBLE_TYPE, CHAR_TYPE, STRING_TYPE, BOOL_TYPE, OP_TYPE, FUNC_TYPE};



struct Node
{
  struct Node *parent;
  struct Node *left;
  struct Node *right;
  enum type_token token;
  int vect;
  void *data;
  struct Vector *v;
};

struct Vector {
  int size;
  int capacity;
  struct Node **data;
};

void vector_init(struct Vector *vector)
{
  vector->capacity = VECTOR_INITIAL_CAPACITY;
  vector->size = 0;
  vector->data = malloc(vector->capacity * sizeof(struct Node*));
}

void vector_double_capacity_if_full(struct Vector *vector)
{
  if(vector->size >= vector->capacity)
  {
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(struct Node*) * vector->capacity);
  }
}

void vector_append(struct Vector *vector, struct Node *n)
{
  vector_double_capacity_if_full(vector);
  vector->data[vector->size++] = n;
}

struct Node* vector_get(struct Vector *vector, int index)
{
  if(index >= vector->size || index < 0)
  {
    return NULL;
  }

  return vector->data[index];
}

#endif /** Vector_h **/
