#pragma once
#if !defined(_INC_LIST)
#define _INC_LIST
#if !defined(_INC_STRCTS_CORE)
#include "../Core-Structs.h"
#endif
#if !defined(_INC_NODE)
#include "../Node.h"
#endif
typedef struct List List;
CERIUS_API List* new_list();
CERIUS_API bool list_append(List*, void*);
CERIUS_API bool list_prepend(List*, void*);
CERIUS_API bool list_add(List*, void*, int);
CERIUS_API bool list_remove_first(List*);
CERIUS_API bool list_remove_last(List*);
CERIUS_API bool list_remove_at(List*, int);
CERIUS_API bool list_remove(List*, void*, bool (*)(void*, void*));
CERIUS_API void* list_pop_element(List*, void*, int (*)(void*, void*));
CERIUS_API void* list_pop(List*);
CERIUS_API void* list_pop_at(List*, int);
CERIUS_API void* list_pop_first(List*);
CERIUS_API void* list_get(List*, int);
CERIUS_API int list_find(List*, void*, bool (*)(void*, void*));
CERIUS_API bool list_sort(List*, void (*)(void*, void*));
CERIUS_API int list_print(List*, int (*)(void*));
CERIUS_API bool list_equals(List*, List*, bool (*)(void*, void*));
CERIUS_API List* list_clone(List*);
CERIUS_API char* list_to_str(List*, char* (*)(void*));
CERIUS_API int delete_list(List*, int(*)(void*));
#endif