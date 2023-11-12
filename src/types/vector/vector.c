#include "vector.h"

vector *new_vector() {
    vector *res = (vector *)malloc(sizeof(vector));
    res->len = 0;
    res->array = NULL;
}

int vector_size(vector *vec) {
    return vec->len;
}

void vector_push_front(vector *vec, void *element) {
    vec->len += 1;
    void **new_arr = (void **)malloc(sizeof(void *) * vec->len);
    if (vec->len > 1 && vec->array != NULL) {
        memcpy(new_arr + 1, vec->array, sizeof(void *) * (vec->len - 1));
        free(vec->array);
    }
    new_arr[0] = element;
    vec->array = new_arr;
}

void vector_push_back(vector *vec, void *element) {
    vec->len += 1;
    void **new_arr = (void **)malloc(sizeof(void *) * vec->len);
    if (vec->len > 1 && vec->array != NULL) {
        memcpy(new_arr, vec->array, sizeof(void *) * (vec->len - 1));
        free(vec->array);
    }
    new_arr[vec->len - 1] = element;
    vec->array = new_arr;
}


void* vector_pop_front(vector *vec) {
    if (vec->len == 0) {
        return NULL;
    }

    vec->len -= 1;
    void *res = vec->array[0];
    if (vec->len == 0) {
        free(vec->array);
        return res;
    }
    void **new_arr = (void **)malloc(sizeof(void *) * vec->len);
    memcpy(new_arr, vec->array + 1, sizeof(void *) * vec->len);
    free(vec->array);
    vec->array = new_arr;
    return res;
}

void* vector_pop_back(vector *vec) {
    if (vec->len == 0) {
        return NULL;
    }

    vec->len -= 1;
    void *res = vec->array[vec->len];
    if (vec->len == 0) {
        free(vec->array);
        return res;
    }
    void **new_arr = (void **)malloc(sizeof(void *) * vec->len);
    memcpy(new_arr, vec->array, sizeof(void *) * vec->len);
    free(vec->array);
    vec->array = new_arr;
    return res;
}

void* vector_remove(vector *vec, unsigned int index) {
    if (vec->len == 0 || index >= vec->len) {
        return NULL;
    }

    vec->len -= 1;
    void *res = vec->array[index];
    
    if (vec->len == 0) {
        free(vec->array);
        return res;
    }

    void **new_arr = (void **)malloc(sizeof(void *) * vec->len);
    if (index > 0) {
        memcpy(new_arr, vec->array, sizeof(void *) * index);
    }
    if (index < vec->len) {
        memcpy(new_arr + index, vec->array + index + 1, sizeof(void *) * (vec->len - index));
    }
    free(vec->array);
    vec->array = new_arr;

    return res;
}