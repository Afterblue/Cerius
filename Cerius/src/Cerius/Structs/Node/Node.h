#pragma once
#if !defined(_INC_NODE)
#define _INC_NODE
#if !defined(_INC_CORE_STRCTS)
#include "../Core-Structs.h"
#endif // _INC_CORE_STRCTS
typedef struct Node Node;
CERIUS_API Node* new_node(void*);
CERIUS_API void* node_get_data(Node*);
CERIUS_API bool node_set_data(Node*, void*);
CERIUS_API Node* node_get_next(Node*);
CERIUS_API bool node_set_next(Node*, Node*);
CERIUS_API int delete_node(Node*);
#endif // _INC_SNODE