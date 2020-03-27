#pragma once
#include "List.h"
struct List {
	Node* head;
	Node* tail;
	int size;
};
List* new_list() {
	List* this = new(List);
	this->head = this->tail = NULL;
	this->size = 0;
	return this;
}
bool list_append(List* this, void* obj) {
	Node* node;
	if (this)
		if (node = new_node(obj)) {
			if (!this->head && !this->tail)
				this->head = this->tail = node;
			else {
				node_set_next(this->tail, node);
				this->tail = node;
			}
			this->size++;
			return true;
		}
	return false;
}
bool list_prepend(List* this, void* obj) {
	Node* node;
	if (this)
		if (node = new_node(obj)) {
			if (!this->head && !this->tail)
				this->head = this->tail = node;
			else {
				node_set_next(node, this->head);
				this->head = node;
			}
			this->size++;
			return true;
		}
	return false;
}
bool list_add(List* this, int index, void* obj) {
	Node* node;
	Node* pos;
	if (this && index > -1) {
		if (!index)
			return list_prepend(this, obj);
		if (this->size > index) {
			if (index == this->size - 1)
				return list_append(this, obj);
			if (node = new_node(obj)) {
				for (pos = this->head; index; pos = node_get_next(pos), index--);
				node_set_next(node, node_get_next(pos));
				node_set_next(pos, node);
				this->size++;
				return true;
			}
		}
	}
	return false;
}
void* list_pop_first(List* this) {
	void* data;
	Node* node;
	if (this && this->head && this->tail) {
		node = this->head;
		this->head = node_get_next(this->head);
		if (!this->head)
			this->tail = NULL;
		data = new(void*);
		copy(data, node_get_data(node));
		delete_node(node);
		this->size--;
		return data;
	}
	return NULL;
}
void* list_pop_at(List* this, int index) {
	void* data;
	Node* pos;
	Node* prev;
	if (this && this->head && this->tail && index > -1) {
		if (!index)
			return list_pop_first(this);
		if (this->size > index) {
			if (index == this->size - 1)
				return list_pop(this);
			for (pos = this->head; index; index--, prev = pos, pos = node_get_next(pos));
			node_set_next(prev, node_get_next(pos));
			data = new(void*);
			copy(data, node_get_data(pos));
			delete_node(pos);
			this->size--;
			return data;
		}
	}
	return NULL;
}
void* list_pop(List* this) {
	void* data;
	Node* pos;
	Node* next;
	if (this && this->head && this->tail) {
		pos = this->head;
		next = node_get_next(pos);
		while (next != this->tail) {
			pos = next;
			next = node_get_next(pos);
		}
		data = new(void*);
		copy(data, node_get_data(this->tail));
		node_set_next(pos, NULL);
		delete_node(this->tail);
		this->tail = pos;
		this->size--;
		return data;
	}
	return NULL;
}
void* list_pop_element(List* this, void* obj, int (*cmp)(void*, void*)) {
	void* data;
	Node* pos;
	Node* prev;
	if (this && this->head && this->tail) {
		prev = this->head;
		pos = node_get_next(prev);
		while (pos) {
			prev = pos;
			pos = node_get_next(pos);
		}
		if (pos) {
			node_set_next(prev, node_get_next(pos));
			data = new(void*);
			copy(data, node_get_data(pos));
			delete_node(pos);
			this->size--;
			return data;
		}
	}
	return NULL;
}
bool list_remove_first(List* this) {
	void* data;
	if (data = list_pop_first(this)) {
		delete(data);
		return true;
	}
	return false;
}
bool list_remove_at(List* this, int index) {
	void* data;
	if (data = list_pop_at(this, index)) {
		delete(data);
		return true;
	}
	return false;
}
bool list_remove_last(List* this) {
	void* data;
	if (data = list_pop(this)) {
		delete(data);
		return true;
	}
	return false;
}
bool list_remove(List* this, void* obj, int (*cmp)(void*, void*)) {
	void* data;
	if (data = list_pop_element(this, obj, cmp)) {
		delete(data);
		return true;
	}
	return false;
}
void* list_get(List* this, int index) {
	Node* pos;
	for (pos = this->head; pos && index; index--, pos = node_get_next(pos));
	if (pos)
		return node_get_data(pos);
	return NULL;
}
int list_find(List* this, void* obj, int (*cmp)(void*, void*)) {
	int index;
	Node* pos;
	for (index = 0, pos = this->head; pos; index++, pos = node_get_next(pos))
		if (!cmp(node_get_data(pos), obj))
			return index;
	return -1;
}
bool list_sort(List* this, int (*cmp)(void*, void*)) {
	void* data;
	void* data1;
	void* data2;
	Node* temp1;
	Node* temp2;
	data = new(void*);
	for (temp1 = this->head; temp1; temp1 = node_get_next(temp1)) {
		for (temp2 = node_get_next(temp1); temp2; temp2 = node_get_next(temp2)) {
			data1 = node_get_data(temp1);
			data2 = node_get_data(temp2);
			if (cmp(data1, data2) > 0) {
				copy(data, data1);
				node_set_data(temp1, data2);
				node_set_data(temp2, data);
			}
		}
	}
	return true;
}
int list_print(List* this, int (*print)(void*)) {
	int bytes;
	Node* pos;
	for (bytes = 0, pos = this->head; pos; pos = node_get_next(pos))
		bytes += print(node_get_data(pos));
	return bytes + print(NULL);
}
bool list_equals(List* this, List* other, int (*cmp)(void*, void*)) {
	Node* pos1, * pos2;
	for (pos1 = this->head, pos2 = other->head; pos1 && pos2; pos1 = node_get_next(pos1), pos2 = node_get_next(pos2))
		if (cmp(node_get_data(pos1), node_get_data(pos2)))
			return false;
	return !pos1 && !pos2;
}
List* list_clone(List* this) {
	Node* pos;
	List* clone;
	for (pos = this->head, clone = new_list(); pos; pos = node_get_next(pos))
		list_append(clone, node_get_data(pos));
	return clone;
}
char* list_to_str(List* this, char* (*obj_to_str)(void*)) {
	char* str;
	Node* pos;
	for (str = "", pos = this->head; pos; pos = node_get_next(pos))
		strcat(str, obj_to_str(node_get_data(pos)));
	return str;
}

int free_list(List* this, int (*destroy)(void*)) {
	int bytes;
	Node* pos;
	for (bytes = 0, pos = this->head; pos; pos = node_get_next(pos))
		bytes += destroy(node_get_data(pos));
	return bytes;
}