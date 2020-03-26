#pragma once
#if !defined(_INC_SLLIST)
#define _INC_SLLIST
#if !defined(_INC_STRCTS_CORE)
#include "../Core-Structs.h"
#endif
#if !defined(_INC_SLNODE)
#include "../SLNode.h"
#endif
typedef struct SLList SLList;
CERIUS_API SLList* new_list();
CERIUS_API bool list_append(SLList*, void*);
CERIUS_API bool list_prepend(SLList*, void*);
CERIUS_API bool list_add(SLList*, void*, int);
CERIUS_API bool list_remove_first(SLList*);
CERIUS_API bool list_remove_last(SLList*);
CERIUS_API bool list_remove_at(SLList*, int);
CERIUS_API bool list_remove(SLList*, void*, bool (*)(void*, void*));
CERIUS_API void* list_pop_element(SLList*, void*, int (*)(void*, void*));
CERIUS_API void* list_pop(SLList*);
CERIUS_API void* list_pop_at(SLList*, int);
CERIUS_API void* list_pop_first(SLList*);
CERIUS_API void* list_get(SLList*, int);
CERIUS_API int list_find(SLList*, void*, bool (*)(void*, void*));
CERIUS_API bool list_sort(SLList*, void (*)(void*, void*));
CERIUS_API int list_print(SLList*, int (*)(void*));
CERIUS_API bool list_equals(SLList*, SLList*, bool (*)(void*, void*));
CERIUS_API SLList* list_clone(SLList*);
CERIUS_API char* list_to_str(SLList*, char* (*)(void*));
CERIUS_API int delete_list(SLList*, int(*)(void*));
#endif