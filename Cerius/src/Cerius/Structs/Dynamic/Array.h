#if !defined(_INC_ARRAY)
#define _INC_ARRAY
#if !defined(_INC_CORE_STRCTS)
#include "../Core-Structs.h"
#endif // _INC_CORE_STRCTS
typedef struct Array Array;
CERIUS_API Array* new_array();
CERIUS_API bool array_append(Array*, void*);
CERIUS_API bool array_prepend(Array*, void*);
CERIUS_API bool array_remove(Array*, int);
CERIUS_API void* array_get(Array*, int);
CERIUS_API bool array_set(Array*, int, void*);
CERIUS_API int array_find(Array*, void*, int (*)(void*, void*));
CERIUS_API int array_size(Array*);
CERIUS_API bool array_sort(Array*, int (*)(void*, void*));
CERIUS_API int array_print(Array*, int(*)(void*));
CERIUS_API int free_array(Array**);
#endif // _INC_ARRAY