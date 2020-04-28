#pragma once
#if !defined(_INC_LINKEDLIST)
#define _INC_LINKEDLIST
#if !defined(_INC_CORE_STRCTS)
#include "../Core-Structs.h"
#endif // _INC_CORE_STRCTS
#if !defined(_INC_DNODE)
#include "../Node/DNode.h"
#endif // _INC_DNODE
typedef struct LinkedList LinkedList;
CERIUS_API LinkedList* new_linked_list();
CERIUS_API bool linked_list_append(LinkedList*, void*);
CERIUS_API bool linked_list_prepend(LinkedList*, void*);
CERIUS_API bool linked_list_add(LinkedList*, int, void*);
CERIUS_API void* linked_list_pop_first(LinkedList*);
CERIUS_API void* linked_list_pop_at(LinkedList*, int);
CERIUS_API void* linked_list_pop(LinkedList*);
CERIUS_API void* linked_list_pop_element(LinkedList*, void*, int (*)(void*, void*));
CERIUS_API bool linked_list_remove_first(LinkedList*);
CERIUS_API bool linked_list_remove_at(LinkedList*, int);
CERIUS_API bool linked_list_remove_last(LinkedList*);
CERIUS_API bool linked_list_remove(LinkedList*, void*, int (*)(void*, void*));
CERIUS_API void* linked_list_get(LinkedList*, int);
CERIUS_API int linked_list_find(LinkedList*, void*, int (*)(void*, void*));
CERIUS_API bool linked_list_sort(LinkedList*, int (*)(void*, void*));
CERIUS_API int linked_list_print(LinkedList*, int (*)(void*));
CERIUS_API bool linked_list_equals(LinkedList*, LinkedList*, int (*)(void*, void*));
CERIUS_API LinkedList* linked_list_clone(LinkedList*);
CERIUS_API char* linked_list_to_str(LinkedList*, char* (*)(void*));
CERIUS_API int linked_list_size(LinkedList*);
CERIUS_API int free_linked_list(LinkedList*);
#endif // _INC_LINKEDLIST