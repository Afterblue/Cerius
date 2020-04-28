#pragma once
#include "Stack.h"
struct Stack {
	Array* arr;
};
Stack* new_stack() {
	Stack* this = malloc(sizeof(Stack));
	this->arr = new_array();
	return this;
}
bool stack_push(Stack* this, void* obj) {
	array_prepend(this->arr, obj);
}
void* stack_pop(Stack* this) {

}
void* stack_top(Stack* this) {

}
bool is_empty(Stack* this) {
	return (bool)(this->arr || !array_size(this->arr));
}
bool free_stack(Stack* this) {
	free_array(this->arr);
	this->arr = NULL;
}