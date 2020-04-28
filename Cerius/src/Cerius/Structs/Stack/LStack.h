#pragma once
#if !defined(_INC_LSTACK)
#define _INC_LSTACK
#if !defined(_INC_CORE_STRCTS)
#include "../Core-Structs.h"
#endif // _INC_CORE_STRCTS
#if !defined(_INC_LIST)
#include "../List/List.h"
#endif
typedef struct LStack LStack;
CERIUS_API LStack* new_lstack();
CERIUS_API bool lstack_push(LStack*, void*);
CERIUS_API bool lstack_insert_bottom(LStack*, void*);
CERIUS_API void* lstack_pop(LStack*, void*);
CERIUS_API void* lstack_top(LStack*, void*);
CERIUS_API void* lstack_bottom(LStack*, void*);
CERIUS_API int lstack_size(LStack*);
CERIUS_API bool lstack_is_empty(LStack*, void*);
CERIUS_API int free_lstack(LStack*, void*);
#endif