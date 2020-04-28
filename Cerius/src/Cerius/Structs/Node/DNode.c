#pragma once
#include "DNode.h"
struct DNode {
	void* data;
	DNode* next;
	DNode* prev;
};
DNode* new_dnode(void* data) {
	DNode* this;
	this = malloc(sizeof(DNode));
	this->data = malloc(sizeof(void*));
	memcpy(this->data, data, sizeof(void*));
	this->next = NULL;
	this->prev = NULL;
	return this;
}
void* dnode_get_data(DNode* this) {
	return this ? this->data : NULL;
}
bool dnode_set_data(DNode* this, void* data) {
	if (this) {
		memcpy(this->data, data, sizeof(void*));
		return true;
	}
	return false;
}
DNode* dnode_get_next(DNode* this) {
	return this ? this->next : NULL;
}
bool dnode_set_next(DNode* this, DNode* next) {
	if (this) {
		this->next = next;
		return true;
	}
	return false;
}
DNode* dnode_get_prev(DNode* this) {
	return this ? this->prev : NULL;
}
bool dnode_set_prev(DNode* this, DNode* prev) {
	if (this) {
		this->prev = prev;
		return true;
	}
	return false;
}
int free_dnode(DNode* this) {
	free(this->data);
	free(this);
	return sizeof(void*) + sizeof(DNode);
}