#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef VECTOR_H
#define VECTOR_H

/*
VERY PRIMITIVE VECTOR..
*/

typedef struct _vector
{
    int len;
    int* array;
} vector;

vector* new_vector();

int vector_size(vector* vec);

void vector_push_front(vector* vec, int element);
void vector_push_back(vector* vec, int element);
int vector_pop_front(vector* vec);
int vector_pop_back(vector* vec);

int vector_remove(vector* vec, unsigned int index);

void vector_print(vector* vec, char* terminator);

#endif