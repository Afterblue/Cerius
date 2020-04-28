#pragma once
#include "LinkedList.h"
struct LinkedList {
	int size;
	DNode* head;
	DNode* tail;
};
LinkedList* new_linked_list() {
	LinkedList* this;
	this = malloc(sizeof(LinkedList));
	this->head = this->tail = NULL;
	this->size = 0;
	return this;
}
bool linked_list_append(LinkedList* this, void* obj) {
	DNode* node;
	if (this)
		if (node = new_dnode(obj)) {
			if (!this->head && !this->tail)
				this->head = this->tail = node;
			else {
				dnode_set_next(this->tail, node);
				dnode_set_prev(node, this->tail);
				this->tail = node;
			}
			this->size++;
			return true;
		}
	return false;
}
bool linked_list_prepend(LinkedList* this, void* obj) {
	DNode* node;
	if (this)
		if (node = new_dnode(obj)) {
			if (!this->head && !this->tail)
				this->head = this->tail = node;
			else {
				dnode_set_next(node, this->head);
				dnode_set_prev(this->head, node);
				this->head = node;
			}
			this->size++;
			return true;
		}
	return false;
}
bool linked_list_add(LinkedList* this, int index, void* obj) {
	DNode* node;
	DNode* pos;
	if (this && index > -1) {
		if (!index)
			return linked_list_prepend(this, obj);
		if (this->size > index) {
			if (index == this->size - 1)
				return linked_list_append(this, obj);
			if (node = new_dnode(obj)) {
				for (pos = this->head; index; pos = dnode_get_next(pos), index--);
				dnode_set_next(node, dnode_get_next(pos));
				dnode_set_prev(dnode_get_next(pos), node);
				dnode_set_next(pos, node);
				dnode_set_prev(node, pos);
				this->size++;
				return true;
			}
		}
	}
	return false;
}
void* linked_list_pop_first(LinkedList* this) {
	void* data;
	DNode* node;
	if (this && this->head && this->tail) {
		node = this->head;
		this->head = dnode_get_next(this->head);
		if (!this->head)
			this->tail = NULL;
		data = malloc(sizeof(void*));
		memcpy(data, dnode_get_data(node), sizeof(void*));
		free_dnode(node);
		this->size--;
		return data;
	}
	return NULL;
}
// come back here
void* linked_list_pop_at(LinkedList* this, int index) {
	void* data;
	DNode* pos;
	DNode* prev;
	DNode* next;
	if (this && this->head && this->tail && index > -1) {
		if (!index)
			return linked_list_pop_first(this);
		if (this->size > index) {
			if (index == this->size - 1)
				return linked_list_pop(this);
			for (pos = this->head; index; index--, prev = pos, pos = dnode_get_next(pos));
			next = dnode_get_next(pos);
			dnode_set_next(prev, next);
			dnode_set_prev(next, prev);
			data = malloc(sizeof(void*));
			memcpy(data, dnode_get_data(pos), sizeof(void*));
			free_dnode(pos);
			this->size--;
			return data;
		}
	}
	return NULL;
}
void* linked_list_pop(LinkedList* this) {
	void* data;
	DNode* node;
	if (this && this->head && this->tail) {
		node = dnode_get_prev(this->tail);
		data = malloc(sizeof(void*));
		memcpy(data, dnode_get_data(this->tail), sizeof(void*));
		dnode_set_next(node, NULL);
		free_dnode(this->tail);
		this->tail = node;
		this->size--;
		return data;
	}
	return NULL;
}
void* linked_list_pop_element(LinkedList* this, void* obj, int (*cmp)(void*, void*)) {
	void* data;
	DNode* pos;
	DNode* prev;
	DNode* next;
	if (this && this->head && this->tail) {
		prev = this->head;
		pos = dnode_get_next(prev);
		while (pos) {
			prev = pos;
			pos = dnode_get_next(pos);
		}
		if (pos) {
			next = dnode_get_next(pos);
			dnode_set_next(prev, next);
			dnode_set_prev(next, prev);
			data = malloc(sizeof(void*));
			memcpy(data, dnode_get_data(pos), sizeof(void*));
			free_dnode(pos);
			this->size--;
			return data;
		}
	}
	return NULL;
}
bool linked_list_remove_first(LinkedList* this) {
	void* data;
	if (data = linked_list_pop_first(this)) {
		free(data);
		return true;
	}
	return false;
}
bool linked_list_remove_at(LinkedList* this, int index) {
	void* data;
	if (data = linked_list_pop_at(this, index)) {
		free(data);
		return true;
	}
	return false;
}
bool linked_list_remove_last(LinkedList* this) {
	void* data;
	if (data = linked_list_pop(this)) {
		free(data);
		return true;
	}
	return false;
}
bool linked_list_remove(LinkedList* this, void* obj, int (*cmp)(void*, void*)) {
	void* data;
	if (data = linked_list_pop_element(this, obj, cmp)) {
		free(data);
		return true;
	}
	return false;
}
void* linked_list_get(LinkedList* this, int index) {
	DNode* pos;
	for (pos = this->head; pos && index; index--, pos = dnode_get_next(pos));
	if (pos)
		return dnode_get_data(pos);
	return NULL;
}
int linked_list_find(LinkedList* this, void* obj, int (*cmp)(void*, void*)) {
	int index;
	DNode* pos;
	for (index = 0, pos = this->head; pos; index++, pos = dnode_get_next(pos))
		if (!cmp(dnode_get_data(pos), obj))
			return index;
	return -1;
}
bool linked_list_sort(LinkedList* this, int (*cmp)(void*, void*)) {
	void* data;
	void* data1;
	void* data2;
	DNode* temp1;
	DNode* temp2;
	data = malloc(sizeof(void*));
	for (temp1 = this->head; temp1; temp1 = dnode_get_next(temp1)) {
		for (temp2 = dnode_get_next(temp1); temp2; temp2 = dnode_get_next(temp2)) {
			data1 = dnode_get_data(temp1);
			data2 = dnode_get_data(temp2);
			if (cmp(data1, data2) > 0) {
				memcpy(data, data1, sizeof(void*));
				dnode_set_data(temp1, data2);
				dnode_set_data(temp2, data);
			}
		}
	}
	return true;
}
int linked_list_print(LinkedList* this, int (*print)(void*)) {
	int bytes;
	DNode* pos;
	for (bytes = 0, pos = this->head; pos; pos = dnode_get_next(pos))
		bytes += print(dnode_get_data(pos));
	return bytes + print(NULL);
}
bool linked_list_equals(LinkedList* this, LinkedList* other, int (*cmp)(void*, void*)) {
	DNode* pos1, * pos2;
	for (pos1 = this->head, pos2 = other->head; pos1 && pos2; pos1 = dnode_get_next(pos1), pos2 = dnode_get_next(pos2))
		if (cmp(dnode_get_data(pos1), dnode_get_data(pos2)))
			return false;
	return !pos1 && !pos2;
}
LinkedList* linked_list_clone(LinkedList* this) {
	DNode* pos;
	LinkedList* clone;
	for (pos = this->head, clone = new_linked_list(); pos; pos = dnode_get_next(pos))
		linked_list_append(clone, dnode_get_data(pos));
	return clone;
}
char* linked_list_to_str(LinkedList* this, char* (*obj_to_str)(void*)) {
	char* str;
	DNode* pos;
	for (str = "", pos = this->head; pos; pos = dnode_get_next(pos))
		strcat(str, obj_to_str(dnode_get_data(pos)));
	return str;
}

int linked_list_size(LinkedList* this) {
	return this ? this->size : -1;
}

int free_linked_list(LinkedList* this) {
	int bytes;
	DNode* node;
	bytes = this->size;
	while (this->head) {
		node = this->head;
		this->head = dnode_get_next(this->head);
		free_dnode(node);
	}
	free(this);
	return bytes;
}