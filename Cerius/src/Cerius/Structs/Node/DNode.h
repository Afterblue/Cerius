#pragma once
#if !defined(_INC_DNODE)
#define _INC_DNODE
#if !defined(_INC_CORE_STRCTS)
#include "../Core-Structs.h"
#endif // _INC_CORE_STRCTS
typedef struct DNode DNode;
CERIUS_API DNode* new_dnode(void*);
CERIUS_API void* dnode_get_data(DNode*);
CERIUS_API bool dnode_set_data(DNode*, void*);
CERIUS_API DNode* dnode_get_next(DNode*);
CERIUS_API bool dnode_set_next(DNode*);
CERIUS_API DNode* dnode_get_prev(DNode*);
CERIUS_API bool dnode_set_prev(DNode*);
CERIUS_API int free_dnode(DNode*);
#endif