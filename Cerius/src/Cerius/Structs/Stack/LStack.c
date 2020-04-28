#pragma once
#include "LStack.h"
struct LStack {
	List* list;
};
LStack* new_lstack() {
	LStack* this = malloc(sizeof(LStack));
	this->list = new_list();
	return this;
}
bool lstack_push(LStack* this, void* obj) {
	return this ? list_prepend(this->list, obj) : false;
}
bool lstack_insert_bottom(LStack* this, void* obj) {
	return this ? list_append(this->list, obj) : false;
}
void* lstack_pop(LStack* this) {
	return this && this->list ? list_pop(this) : NULL;
}
void* lstack_top(LStack* this) {
	return this && this->list ? list_get(this, 0) : NULL;
}
void* lstack_bottom(LStack* this) {
	return this && this->list ? list_get(this, list_size(this->list) - 1) : NULL;
}
int lstack_size(LStack* this) {
	return this && this->list ? list_size(this->list) : -1;
}
bool lstack_is_empty(LStack* this) {

}
int free_lstack(LStack* this) {

}