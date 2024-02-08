#include<stdint.h>

#ifndef DYNAMIC_ARRAY_VECTOR_H
#define DYNAMIC_ARRAY_VECTOR_H

typedef struct vector {
    size_t size;
    size_t capacity;
    int *array;
} vector;

void init_vector(vector **arr_ptr, int size);

void pushback(vector *array, int value);

void print_vector(vector *array);

void insert(vector *array, int value, int index);

void get_item(vector *array, int index);

void delete_item(vector* array, int index);

void free_vector(vector* array);

void replace(vector *array, int value, int index);

#endif //DYNAMIC_ARRAY_VECTOR_H
