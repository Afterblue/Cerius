#pragma once
#if !defined(_INC_QUEUE)
#define _INC_QUEUE
#if !defined(_INC_CORE_STRCTS)
#include "../Core-Structs.h"
#endif // _INC_CORE_STRCTS
#if !defined(_INC_ARRAY)
#include "../Dynamic/Array.h"
#endif
typedef struct Queue Queue;
CERIUS_API Queue* new_queue();
CERIUS_API bool enqueue(Queue*, void*);
CERIUS_API void* dequeue(void*);
CERIUS_API bool is_empty(Queue*);
CERIUS_API void* get_front(Queue*);
CERIUS_API void* get_rear(Queue*);
#endif