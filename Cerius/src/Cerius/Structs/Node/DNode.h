#pragma once
#if !defined(_INC_DNODE)
#define _INC_DNODE
#if !defined(_INC_CORE_STRCTS)
#include "../Core-Structs.h"
#endif // _INC_CORE_STRCTS
typedef struct DNode DNode;
DNode* new_dnode(void*);
void* dnode_get_data(DNode*);
bool dnode_set_data(DNode*, void*);
DNode* dnode_get_next(DNode*);
bool dnode_set_next(DNode*);
DNode* dnode_get_prev(DNode*);
bool dnode_set_prev(DNode*);
#endif