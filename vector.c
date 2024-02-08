#include"vector.h"
#include<stdlib.h>
#include <stdio.h>

void init_vector(vector **arr_ptr, int size) {
    vector *array;
    array = (vector *) malloc(sizeof(vector));
    if (!array) {
        printf("Memory allocation failed :(\n");
        exit(0);
    }
    array->size = 0;
    array->capacity = size;
    array->array = (int *) calloc(array->capacity, sizeof(int));
    if (!array->array) {
        printf("Memory allocation failed :(\n");
        exit(0);
    }
    *arr_ptr = array;
}

void print_vector(vector *array) {
    for (int i = 0; i < array->size; ++i) {
        printf("%d ", array->array[i]);
    }
    printf("\n");
}

void pushback(vector *array, int value) {
    if (array->size == array->capacity) {
        array->capacity <<= 1;
        int *temp = (int *) realloc(array->array, sizeof(int) * (array->capacity));
        if (!temp) {
            printf("Memory allocation failed :(\n");
            array->array = temp;
            return;
        }
        array->array = temp;
    }
    array->array[array->size++] = value;
}

void free_vector(vector *array) {
    free(array->array);
    free(array);
}

void get_item(vector *array, int index) {
    if (index >= array->size || index < 0) {
        printf("Index out of range silly goose\n");
        return;
    }
    printf("%d\n", array->array[index]);
}

void insert(vector *array, int value, int index) {
    if (index > array->size || index < 0) {
        printf("Index out of range silly goose\n");
        return;
    }
    if (array->size == array->capacity) {
        array->capacity <<= 1;
        int *temp = (int *) realloc(array->array, sizeof(int) * (array->capacity));
        if (!temp) {
            printf("Memory allocation failed :(\n");
            array->array = temp;
            return;
        }
    }
    for (int i = (int) array->size; i > index; --i) {
        array->array[i] = array->array[i - 1];
    }
    array->array[index] = value;
    array->size++;
}

void replace(vector *array, int value, int index) {
    if (index >= array->size || index < 0) {
        printf("Index out of range silly goose\n");
        return;
    }
    int *temp = array->array;
    for (int i = 0; i < array->size + 1; ++i) {
        if (index == i) {
            array->array[i] = value;
        }
        array->array[i] = temp[i];
    }
}

void delete_item(vector *array, int index) {
    if (index > array->size || index < 0) {
        printf("Index out of range silly goose\n");
        return;
    }
    for (int i = index; i < array->size-1; ++i) {
            array->array[i] = array->array[i + 1];
    }
    array->size--;
}
