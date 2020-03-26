#pragma once
#include "SLList.h"
struct SLList {
	SLNode* head;
	SLNode* tail;
	int size;
};
SLList* new_sllist() {
	SLList* list = new(SLList);
	list->head = list->tail = NULL;
	list->size = 0;
}
bool list_append(SLList* list, void* obj) {
	SLNode* node;
	if (list)
		if (node = new_slnode(obj)) {
			if (!list->head && !list->tail)
				list->head = list->tail = node;
			else {
				slnode_set_next(list->tail, node);
				list->tail = node;
			}
			list->size++;
			return true;
		}
	return false;
}
bool list_prepend(SLList* list, void* obj) {
	SLNode* node;
	if (list)
		if (node = new_slnode(obj)) {
			if (!list->head && !list->tail)
				list->head = list->tail = node;
			else {
				slnode_set_next(node, list->head);
				list->head = node;
			}
			list->size++;
			return true;
		}
	return false;
}
bool list_add(SLList* list, void* obj, int index) {
	SLNode* node;
	SLNode* pos;
	if (list && index > -1) {
		if (!index)
			return list_prepend(list, obj);
		if (list->size > index) {
			if (index == list->size - 1)
				return list_append(list, obj);
			if (node = new_slnode(obj)) {
				for (pos = list->head; index; pos = slnode_get_next(pos), index--);
				slnode_set_next(node, slnode_get_next(pos));
				slnode_set_next(pos, node);
				list->size++;
				return true;
			}
		}
	}
	return false;
}
void* list_pop_first(SLList* list) {
	void* data;
	SLNode* node;
	if (list && list->head && list->tail) {
		node = list->head;
		list->head = slnode_get_next(list->head);
		if (!list->head)
			list->tail = NULL;
		data = new(void*);
		copy(data, snode_get_data(node));
		delete_slnode(node);
		list->size--;
		return data;
	}
	return NULL;
}
void* list_pop_at(SLList* list, int index) {
	void* data;
	SLNode* pos;
	SLNode* prev;
	if (list && list->head && list->tail && index > -1) {
		if (!index)
			return list_pop_first(list);
		if (list->size > index) {
			if (index == list->size - 1)
				return list_pop(list);
			for (pos = list->head; index; prev = pos, pos = slnode_get_next(pos), index--);
			slnode_set_next(prev, slnode_get_next(pos));
			data = new(void*);
			copy(data, snode_get_data(pos));
			delete_slnode(pos);
			list->size--;
			return data;
		}
	}
	return NULL;
}
void* list_pop(SLList* list) {
	void* data;
	SLNode* pos;
	SLNode* next;
	if (list && list->head && list->tail) {
		pos = list->head;
		next = slnode_get_next(pos);
		while (next != list->tail) {
			pos = next;
			next = snode_get_next(pos);
		}
		data = new(void*);
		copy(data, snode_get_data(list->tail));
		slnode_set_next(pos, NULL);
		delete_slnode(list->tail);
		list->tail = pos;
		list->size--;
		return data;
	}
	return NULL;
}
void* list_pop_element(SLList* list, void* obj, int (*cmp)(void*, void*)) {
	void* data;
	SLNode* pos;
	SLNode* prev;
	if (list && list->head && list->tail) {
		prev = list->head;
		pos = slnode_get_next(prev);
		while (pos) {
			prev = pos;
			pos = slnode_get_next(pos);
		}
		if (pos) {
			slnode_set_next(prev, slnode_get_next(pos));
			data = new(void*);
			copy(data, snode_get_data(pos));
			delete_slnode(pos);
			list->size--;
			return data;
		}
	}
	return NULL;
}
bool list_remove_first(SLList* list) {
	void* data;
	if (data = list_pop_first(list)) {
		delete(data);
		return true;
	}
	return false;
}
bool list_remove_at(SLList* list, int index) {
	return (bool)list_pop_at(list, index);
}
bool list_remove_last(SLList* list) {
	void* data;
	if (data = list_pop(list)) {
		delete(data);
		return true;
	}
	return false;
}
bool list_remove(SLList* list, void* obj, bool (*equals)(void*, void*)) {
	SLNode* pos;
	for (pos = list->head; pos && !equals(obj, slnode_get_data(pos)); pos = slnode_get_next(pos));
	if (pos) {

		return true;
	}
	return false;
}
void* list_get(SLList* list, int index) {

}
int list_find(SLList* list, void* obj, bool (*equals)(void*, void*)) {
	int index;
	SLNode* pos;
	for (index = 0, pos = list->head; pos; index++, pos = slnode_get_next(pos))
		if (equals(slnode_get_data(pos), obj))
			return index;
	return -1;
}
bool list_sort(SLList* list, void (*cmp)(void*, void*)) {

}
int list_print(SLList* list, int (*print)(void*)) {
	int bytes;
	SLNode* pos;
	for (bytes = 0, pos = list->head; pos; pos = slnode_get_next(pos))
		bytes += print(slnode_get_data(pos));
	return bytes + print(NULL);
}
bool list_equals(SLList* list, SLList* other, bool (*equals)(void*, void*)) {
	SLNode* pos1, * pos2;
	for (pos1 = list->head, pos2 = other->head; pos1 && pos2; pos1 = slnode_get_next(pos1), pos2 = slnode_get_next(pos2))
		if (equals(slnode_get_data(pos1), slnode_get_data(pos2)))
			return false;
	return !pos1 && !pos2;
}
SLList* list_clone(SLList* list) {
	SLNode* pos;
	SLList* clone;
	for (pos = list->head, clone = new_list(); pos; pos = slnode_get_next(pos))
		list_append(clone, slnode_get_data(pos));
	return clone;
}
char* list_to_str(SLList* list, char* (*obj_to_str)(void*)) {
	char* str;
	SLNode* pos;
	for (str = "", pos = list->head; pos; pos = slnode_get_next(pos))
		strcat(str, obj_to_str(slnode_get_data(pos)));
	return str;
}

int delete_list(SLList* list, int (*destroy)(void*)) {
	int bytes;
	SLNode* pos;
	for (bytes = 0, pos = list->head; pos; pos = slnode_get_next(pos))
		bytes += destroy(slnode_get_data(pos));
	return bytes;
}