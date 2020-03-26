#pragma once
#include "SLList.h"
struct SLList {
	SLNode* head;
	SLNode* tail;
	int size;
};
SLList* new_list() {
	SLList* this = new(SLList);
	this->head = this->tail = NULL;
	this->size = 0;
	return this;
}
bool list_append(SLList* this, void* obj) {
	SLNode* node;
	if (this)
		if (node = new_slnode(obj)) {
			if (!this->head && !this->tail)
				this->head = this->tail = node;
			else {
				slnode_set_next(this->tail, node);
				this->tail = node;
			}
			this->size++;
			return true;
		}
	return false;
}
bool list_prepend(SLList* this, void* obj) {
	SLNode* node;
	if (this)
		if (node = new_slnode(obj)) {
			if (!this->head && !this->tail)
				this->head = this->tail = node;
			else {
				slnode_set_next(node, this->head);
				this->head = node;
			}
			this->size++;
			return true;
		}
	return false;
}
bool list_add(SLList* this, void* obj, int index) {
	SLNode* node;
	SLNode* pos;
	if (this && index > -1) {
		if (!index)
			return list_prepend(this, obj);
		if (this->size > index) {
			if (index == this->size - 1)
				return list_append(this, obj);
			if (node = new_slnode(obj)) {
				for (pos = this->head; index; pos = slnode_get_next(pos), index--);
				slnode_set_next(node, slnode_get_next(pos));
				slnode_set_next(pos, node);
				this->size++;
				return true;
			}
		}
	}
	return false;
}
void* list_pop_first(SLList* this) {
	void* data;
	SLNode* node;
	if (this && this->head && this->tail) {
		node = this->head;
		this->head = slnode_get_next(this->head);
		if (!this->head)
			this->tail = NULL;
		data = new(void*);
		copy(data, slnode_get_data(node));
		delete_slnode(node);
		this->size--;
		return data;
	}
	return NULL;
}
void* list_pop_at(SLList* this, int index) {
	void* data;
	SLNode* pos;
	SLNode* prev;
	if (this && this->head && this->tail && index > -1) {
		if (!index)
			return list_pop_first(this);
		if (this->size > index) {
			if (index == this->size - 1)
				return list_pop(this);
			for (pos = this->head; index; prev = pos, pos = slnode_get_next(pos), index--);
			slnode_set_next(prev, slnode_get_next(pos));
			data = new(void*);
			copy(data, slnode_get_data(pos));
			delete_slnode(pos);
			this->size--;
			return data;
		}
	}
	return NULL;
}
void* list_pop(SLList* this) {
	void* data;
	SLNode* pos;
	SLNode* next;
	if (this && this->head && this->tail) {
		pos = this->head;
		next = slnode_get_next(pos);
		while (next != this->tail) {
			pos = next;
			next = slnode_get_next(pos);
		}
		data = new(void*);
		copy(data, slnode_get_data(this->tail));
		slnode_set_next(pos, NULL);
		delete_slnode(this->tail);
		this->tail = pos;
		this->size--;
		return data;
	}
	return NULL;
}
void* list_pop_element(SLList* this, void* obj, int (*cmp)(void*, void*)) {
	void* data;
	SLNode* pos;
	SLNode* prev;
	if (this && this->head && this->tail) {
		prev = this->head;
		pos = slnode_get_next(prev);
		while (pos) {
			prev = pos;
			pos = slnode_get_next(pos);
		}
		if (pos) {
			slnode_set_next(prev, slnode_get_next(pos));
			data = new(void*);
			copy(data, slnode_get_data(pos));
			delete_slnode(pos);
			this->size--;
			return data;
		}
	}
	return NULL;
}
bool list_remove_first(SLList* this) {
	void* data;
	if (data = list_pop_first(this)) {
		delete(data);
		return true;
	}
	return false;
}
bool list_remove_at(SLList* this, int index) {
	return (bool)list_pop_at(this, index);
}
bool list_remove_last(SLList* this) {
	void* data;
	if (data = list_pop(this)) {
		delete(data);
		return true;
	}
	return false;
}
bool list_remove(SLList* this, void* obj, bool (*equals)(void*, void*)) {
	SLNode* pos;
	for (pos = this->head; pos && !equals(obj, slnode_get_data(pos)); pos = slnode_get_next(pos));
	if (pos) {

		return true;
	}
	return false;
}
void* list_get(SLList* this, int index) {
	/*
		WIP
	*/
	return NULL;
}
int list_find(SLList* this, void* obj, bool (*equals)(void*, void*)) {
	int index;
	SLNode* pos;
	for (index = 0, pos = this->head; pos; index++, pos = slnode_get_next(pos))
		if (equals(slnode_get_data(pos), obj))
			return index;
	return -1;
}
bool list_sort(SLList* this, void (*cmp)(void*, void*)) {
	/*
		WIP
	*/
	return false;
}
int list_print(SLList* this, int (*print)(void*)) {
	int bytes;
	SLNode* pos;
	for (bytes = 0, pos = this->head; pos; pos = slnode_get_next(pos))
		bytes += print(slnode_get_data(pos));
	return bytes + print(NULL);
}
bool list_equals(SLList* this, SLList* other, bool (*equals)(void*, void*)) {
	SLNode* pos1, * pos2;
	for (pos1 = this->head, pos2 = other->head; pos1 && pos2; pos1 = slnode_get_next(pos1), pos2 = slnode_get_next(pos2))
		if (equals(slnode_get_data(pos1), slnode_get_data(pos2)))
			return false;
	return !pos1 && !pos2;
}
SLList* list_clone(SLList* this) {
	SLNode* pos;
	SLList* clone;
	for (pos = this->head, clone = new_list(); pos; pos = slnode_get_next(pos))
		list_append(clone, slnode_get_data(pos));
	return clone;
}
char* list_to_str(SLList* this, char* (*obj_to_str)(void*)) {
	char* str;
	SLNode* pos;
	for (str = "", pos = this->head; pos; pos = slnode_get_next(pos))
		strcat(str, obj_to_str(slnode_get_data(pos)));
	return str;
}

int delete_list(SLList* this, int (*destroy)(void*)) {
	int bytes;
	SLNode* pos;
	for (bytes = 0, pos = this->head; pos; pos = slnode_get_next(pos))
		bytes += destroy(slnode_get_data(pos));
	return bytes;
}