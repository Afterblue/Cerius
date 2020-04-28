#pragma once
#include "Node.h"
struct Node {
	void* data;
	Node* next;
};
Node* new_node(void* data) {
	Node* this;
	this = malloc(sizeof(Node));
	this->data = malloc(sizeof(void*));
	memcpy(this->data, data, sizeof(void*));
	this->next = NULL;
	return this;
}
void* node_get_data(Node* this) {
	return this ? this->data : NULL;
}
bool node_set_data(Node* this, void* data) {
	if (this) {
		memcpy(this->data, data, sizeof(void*));
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
int free_node(Node* this) {
	free(this->data);
	free(this);
	return sizeof(void*) + sizeof(Node);
}