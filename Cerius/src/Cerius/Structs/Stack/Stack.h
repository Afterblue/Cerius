#pragma once
#if !defined(_INC_STACK)
#define _INC_STACK
#if !defined(_INC_CORE_STRCTS)
#include "../Core-Structs.h"
#endif // _INC_CORE_STRCTS
#if !defined(_INC_ARRAY)
#include "../Dynamic/Array.h"
#endif
typedef struct Stack Stack;
CERIUS_API Stack* new_stack();
CERIUS_API bool stack_push(Stack*, void*);
CERIUS_API bool stack_insert_bottom(Stack*, void*);
CERIUS_API void* stack_pop(Stack*);
CERIUS_API void* stack_top(Stack*);
CERIUS_API void* stack_bottom(Stack*);
CERIUS_API int stack_size(Stack*);
CERIUS_API bool is_empty(Stack*);
CERIUS_API bool free_stack(Stack*);
#endif // _INC_STACK