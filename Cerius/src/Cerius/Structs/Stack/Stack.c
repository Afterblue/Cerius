#pragma once
#include "Stack.h"

/*
	---------- Stack -----------

	Dynamic array implementation

	----------------------------
*/

struct Stack {
	Array* arr;
};
Stack* new_stack() {
	Stack* this = malloc(sizeof(Stack));
	this->arr = new_array();
	return this;
}
bool stack_push(Stack* this, void* obj) {
	if (this) {
		array_prepend(this->arr, obj);
	}
}
bool stack_insert_bottom(Stack* this, void* obj) {
	if (this) {
		array_append(this->arr, obj);
	}
}
void* stack_pop(Stack* this) {
	if (this) {
		void* obj = array_get(this->arr, 0);
		array_remove(this->arr, 0);
		return obj;
	}
}

void* stack_top(Stack* this) {
	return this ? array_get(this->arr, 0) : NULL;
}

void* stack_bottom(Stack* this) {
	return this ? array_get(this->arr, array_size(this->arr) - 1) : NULL;
}

int stack_size(Stack* this) {
	return array_size(this->arr);
}

bool is_empty(Stack* this) {
	return (bool)(this->arr || !array_size(this->arr));
}
bool free_stack(Stack** this) {
	if (this && *this) {
		free_array((*this)->arr);
		free(*this);
		*this = NULL;
	}
}