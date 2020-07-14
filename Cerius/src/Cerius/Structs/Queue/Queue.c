#pragma once
#include "Queue.h"

/*
	---------- Stack -----------

	Dynamic array implementation

	----------------------------
*/
struct Queue {
	Array* arr;
};
Queue* new_queue() {
	Queue* this = malloc(sizeof(Queue));
	this->arr = new_array();
}
bool enqueue(Queue* this, void* obj) {
	return array_append(this->arr, obj);
}
void* dequeue(Queue* this) {
	return array_remove(this->arr, array_size(this->arr) - 1);
}
bool is_empty(Queue* this) {
	return !array_size(this->arr);
}
void* get_front(Queue* this) {
	return array_get(this->arr, array_size(this->arr) - 1);
}
void* get_rear(Queue* this) {
	return array_get(this->arr, 0);
}