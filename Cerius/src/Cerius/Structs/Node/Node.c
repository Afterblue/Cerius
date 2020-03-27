#pragma once
#include "Node.h"
struct Node {
	void* data;
	Node* next;
};
Node* new_node(void* data) {
	Node* this;
	this = new(Node);
	this->data = new(void*);
	copy(this->data, data);
	this->next = NULL;
	return this;
}
void* node_get_data(Node* this) {
	return this ? this->data : NULL;
}
bool node_set_data(Node* this, void* data) {
	if (this) {
		copy(this->data, data);
		return true;
	}
	return false;
}
Node* node_get_next(Node* this) {
	return this ? this->next : NULL;
}
bool node_set_next(Node* this, Node* next) {
	if (this) {
		this->next = next;
		return true;
	}
	return false;
}
int delete_node(Node* this) {
	delete(this->data);
	delete(this);
	return sizeof(Node);
}