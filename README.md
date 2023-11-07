# MySTD
### Idiomatic C STD lib for UNI  

### How to Build!
```bash
mkdir build
cd build
cmake .. [-DLIBTYPE=static/shared]
make
```

### Table of Contents
- [Vector: an idiomatic dynamic array implementation](#vector)
  
  
### Vector
```c
vector* new_vector();
/*
    Creates a vector, returns the pointer to the vector struct.
*/

int vector_size(vector* vec);
/*
    Returns the size of the vector.
*/

void vector_push_front(vector* vec, void* element);
/*
    Pushes a value to the front (start) of a vector.
*/

void vector_push_back(vector* vec, void* element);
/*
    Pushes a value to the back (end) of a vector.
*/

void* vector_pop_front(vector* vec);
/*
    Pops (removes) a value from the front (start) of the vector and returns it.
*/

void* vector_pop_back(vector* vec)
/*
    Pops (removes) a value from the back (end) of the vector and returns it.
*/

void* vector_remove(vector* vec, unsigned int index);
/*
    Removes a value from the vector at a given index and returns it.
*/
```

#### How to use Vector
```cpp
// yea, yea, ik, kinda ugly .. at least for now
// wrappers would be nice.. (open to pull requests 😅)
vector* vec = new_vector();
vector_push_back(vec, malloc(sizeof(int) * 1));
*((int *)vec->array[0]) = 5;
vector_push_back(vec, malloc(sizeof(int) * 1));
*((int *)vec->array[1]) = 10;
int* a = (int *)vector_pop_back(vec);
printf("%d\n", *a);
printf("%d %d\n", vector_size(vec), *((int *)vec->array[0]));
free(a);
```