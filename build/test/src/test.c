#include <vector/vector.h>
#include <stdlib.h>
#include <stdio.h>

void print_vec(vector* vec) {
    for (int i = 0; i < vec->len; i += 1) {
        int *j = (int *)(vec->array[i]);
        printf("%d ", *j);
    }
    printf("\n");
}

int main () {
    vector* vec = new_vector();
    int* a1 = (int*)malloc(sizeof(int));
    *a1 = 10;
    int a2 = 10;
    vector_push_back(vec, a1);
    vector_push_back(vec, a1);
    vector_push_back(vec, a1);
    vector_push_back(vec, &a2);
    print_vec(vec);
    int* b = a1; 
    vector_pop_back(vec);
    print_vec(vec);
    printf("%d %d\n", *b, *a1);
    *b += 1;
    printf("%d %d\n", *b, *a1);
    printf("%d %p %p\n", vector_size(vec), (int*)(vec->array[0]), a1);
    return 0;
}