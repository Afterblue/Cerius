#pragma once
#include "Array.h"
struct Array {
	void** head;
	int size;
};
Array* new_array() {
	Array* this;
	this = malloc(sizeof(Array));
	this->head = NULL;
	this->size = 0;
	return this;
}
bool array_append(Array* this, void* obj) {
	void** tmp;
	if (this) {
		if (tmp = realloc(this->head, sizeof(void*) * ++this->size)) {
			memcpy(tmp + this->size - 1, obj, sizeof(void*));
			this->head = tmp;
			return true;
		}
	}
	return false;
}
bool array_prepend(Array* this, void* obj) {
	void** tmp;
	if (this) {
		if (tmp = realloc(this->head, sizeof(void*) * (this->size + 1))) {
			if (this->head)
				memcpy(tmp + 1, this->head, sizeof(void*) * this->size);
			memcpy(tmp, obj, sizeof(void*));
			this->head = tmp;
			this->size++;
			return true;
		}
	}
	return false;
}
bool array_remove(Array* this, int index) {
	void** tmp;
	if (this) {
		if (tmp = malloc(sizeof(void*) * (this->size - 1))) {
			if (index != 0)
				memcpy(tmp, this->head, index * sizeof(void*));
			if (index != this->size - 1)
				memcpy(tmp + index, this->head + index + 1, sizeof(void*) * (this->size - index - 1));
			this->size--;
			free(this->head);
			this->head = tmp;
		}
	}
}
void* array_get(Array* this, int index) {
	if (this && index >= 0 && index < this->size)
		return this->head + index;
	return NULL;
}
bool array_set(Array* this, int index, void* obj) {
	if (this && index > 0 && index < this->size) {
		this->head[index] = obj;
		return true;
	}
	return false;
}
int array_find(Array* this, void* obj, int (*cmp)(void*, void*)) {
	int i;
	if (this && cmp) {
		for (i = 0; i < this->size; i++)
			if (!cmp(this->head[i], obj))
				return i;
	}
	return -1;
}
int array_size(Array* this) {
	return this->size;
}
bool array_sort(Array* this, int (*cmp)(void*, void*)) {
	int i;
	int j;
	void* tmp;
	if (this && cmp) {
		for (i = 0; i < this->size - 1; i++)
			for (int j = 0; j < this->size - i - 1; j++)
				if (cmp(this->head + j, this->head + j + 1) > 0) {
					tmp = *(this->head + j);
					*(this->head + j) = *(this->head + j + 1);
					*(this->head + j + 1) = tmp;
				}
		return true;
	}
	return false;
}
int array_print(Array* this, int(*print)(void*)) {
	int i;
	int bytes;
	bytes = printf("[ ");
	for (i = 0; i < this->size - 1; i++)
		bytes += print(this->head + i) + printf(", ");
	return bytes + print(this->head + i) + puts(" ]");
}
int free_array(Array** this) {
	int bytes;
	bytes = (*this)->size * sizeof(void*);
	free((*this)->head);
	free(*this);
	*this = NULL;
	return bytes;
	
}