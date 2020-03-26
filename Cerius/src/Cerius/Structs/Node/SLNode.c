#pragma once
#include "SLNode.h"
typedef struct SLNode {
	void* data;
	SLNode* next;
}SLNode;
SLNode* new_slnode(void* data) {
	SLNode* this;
	this = new(SLNode);
	this->data = new(void*);
	copy(this->data, data);
	this->next = NULL;
	return this;
}
void* slnode_get_data(SLNode* this) {
	return this ? this->data : NULL;
}
bool slnode_set_data(SLNode* this, void* data) {
	if (this) {
		copy(this->data, data);
		return true;
	}
	return false;
}
SLNode* slnode_get_next(SLNode* this) {
	return this ? this->next : NULL;
}
bool slnode_set_next(SLNode* this, SLNode* next) {
	if (this) {
		this->next = next;
		return true;
	}
	return false;
}
int delete_slnode(SLNode* this) {
	delete(this->data);
	delete(this);
	return sizeof(SLNode);
}