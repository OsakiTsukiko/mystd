#include "vector.h"

vector* new_vector() {
    vector* res = (vector *)malloc(sizeof(vector));
    res->len = 0;
    res->array = NULL;
}

int vector_size(vector* vec) { return vec->len; }


void vector_push_front(vector* vec, void* element) {
    vec->len += 1;
    void** arr = malloc(sizeof(void *) * vec->len);
    if (vec->array != NULL) { // or rather len != 1 (vec was empty)
        memcpy(arr + 1, vec->array, sizeof(void *) * (vec->len - 1));
        free(vec->array);
    }
    arr[0] = element;
    vec->array = arr;
}

void vector_push_back(vector* vec, void* element) {
    vec->len += 1;
    void** arr = malloc(sizeof(void *) * vec->len);
    if (vec->array != NULL) { // or rather len != 1 (vec was empty)
        memcpy(arr, vec->array, sizeof(void *) * (vec->len - 1));
        free(vec->array);
    }
    arr[vec->len - 1] = element;
    vec->array = arr;
}

void* vector_pop_front(vector* vec) {
    if (vec->len == 0) {
        return 0;
    }
    void* res;
    vec->len -= 1;
    res = vec->array[0];
    if (vec->len == 0) {
        free(vec->array);
    } else {
        void** arr = malloc(sizeof(void *) * vec->len);
        memcpy(arr, vec->array + 1, sizeof(void *) * vec->len);
        free(vec->array);
        vec->array = arr;
    }
    return res;
}

void* vector_pop_back(vector* vec) {
    if (vec->len == 0) {
        return 0;
    }
    void* res;
    vec->len -= 1;
    res = vec->array[vec->len];
    if (vec->len == 0) {
        free(vec->array);
    } else {
        void** arr = malloc(sizeof(void *) * vec->len);
        memcpy(arr, vec->array, sizeof(void *) * vec->len);
        free(vec->array);
        vec->array = arr;
    }
    return res;
}

void* vector_remove(vector* vec, unsigned int index) {
    if (index >= vec->len) {
        return 0;
    }
    void* res;
    vec->len -= 1;
    res = vec->array[index];
    if (vec->len > 0) {
        void** arr = malloc(sizeof(void *) * vec->len);
        if (index > 0) {
            memcpy(arr, vec->array, sizeof(void *) * index);
        }
        if (index < vec->len) {
            memcpy(arr + index, vec->array + index + 1, sizeof(void *) * (vec->len - index));
        }
        free(vec->array);
        vec->array = arr;
    } else {
        free(vec->array);
    }
    return res;
}