#pragma once
#if !defined(_INC_SNODE)
#define _INC_SNODE
#if !defined(_INC_CORE_STRCTS)
#include "../Core-Structs.h"
#endif // _INC_CORE_STRCTS
typedef struct SLNode SLNode;
CERIUS_API SLNode* new_slnode(void*);
CERIUS_API void* slnode_get_data(SLNode*);
CERIUS_API bool slnode_set_data(SLNode*, void*);
CERIUS_API SLNode* slnode_get_next(SLNode*);
CERIUS_API bool slnode_set_next(SLNode*, SLNode*);
CERIUS_API int delete_slnode(SLNode*);
#endif // _INC_SNODE