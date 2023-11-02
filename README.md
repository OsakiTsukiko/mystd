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

void vector_push_front(vector* vec, int element);
/*
    Pushes a value to the front (start) of a vector.
*/

void vector_push_back(vector* vec, int element);
/*
    Pushes a value to the back (end) of a vector.
*/

int vector_pop_front(vector* vec);
/*
    Pops (removes) a value from the front (start) of the vector and returns it.
*/

int vector_pop_back(vector* vec)
/*
    Pops (removes) a value from the back (end) of the vector and returns it.
*/

int vector_remove(vector* vec, unsigned int index);
/*
    Removes a value from the vector at a given index and returns it.
*/

void vector_print(vector* vec, char* terminator);
/*
    Prints to the console the contents of the vector.(terminator should be null if not use, common use: \n)
*/
```


