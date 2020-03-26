#if !defined(_INC_ARRAY)
#define _INC_ARRAY
typedef struct Array Array;
bool array_init(Array**);
bool array_insert(Array*, void*);
bool array_remove(Array*, void*);
void* array_get(Array*, int);

#endif