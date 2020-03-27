#pragma once
#include "DNode.h"
struct DNode {
	void* data;
	DNode* next;
	DNode* prev;
};
DNode* new_dnode(void* data) {
	DNode* this;
	this = new(DNode);
	this->data = new(void*);
	copy(this->data, data);
	this->next = NULL;
	this->prev = NULL;
	return this;
}
void* dnode_get_data(DNode* this) {
	return this ? this->data : NULL;
}
bool dnode_set_data(DNode* this, void* data) {
	if (this) {
		copy(this->data, data);
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
int delete_dnode(DNode* this) {
	delete(this->data);
	delete(this);
	return sizeof(DNode);
}
int free_dnode(DNode* this) {
	delete(this->data);
	delete(this);
	return sizeof(void*) + sizeof(DNode);
}