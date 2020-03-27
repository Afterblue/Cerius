#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Cerius/Structs.h>
int list_print_int(void*);
int linked_list_print_int(void*);
int cmp_int(void*, void*);
void build_list(List*);
void build_linked_list(LinkedList*);
void list_test();
void linked_list_test();
int main() {
	// Write your code below
	linked_list_test();
}
void linked_list_test() {
	int num, i, size;
	LinkedList* list;
	srand((unsigned)time(NULL));
	list = new_linked_list();

	build_linked_list(list);

	linked_list_sort(list, cmp_int);
	puts("After linked_list_sort:");
	linked_list_print(list, linked_list_print_int);

	num = 111;
	linked_list_prepend(list, &num);
	puts("After linked_list_prepend for value 111:");
	linked_list_print(list, linked_list_print_int);

	num = 22;
	linked_list_add(list, 3, &num);
	puts("After linked_list_add for value 22:");
	linked_list_print(list, linked_list_print_int);

	linked_list_remove_first(list);
	puts("After linked_list_remove_first (removed 111)");
	linked_list_print(list, linked_list_print_int);

	num = *(int*)linked_list_pop_first(list);
	printf("After linked_list_pop_first (popped %d)\n", num);
	linked_list_print(list, linked_list_print_int);

	free_linked_list(list);
}
void list_test() {
	int num, i, size;
	List* list;
	srand((unsigned)time(NULL));
	list = new_list();

	build_list(list);

	list_sort(list, cmp_int);
	puts("After list_sort:");
	list_print(list, list_print_int);

	num = 111;
	list_prepend(list, &num);
	puts("After list_prepend for value 111:");
	list_print(list, list_print_int);

	num = 22;
	list_add(list, 3, &num);
	puts("After list_add for value 22:");
	list_print(list, list_print_int);

	list_remove_first(list);
	puts("After list_remove_first (removed 111)");
	list_print(list, list_print_int);

	num = *(int*)list_pop_first(list);
	printf("After list_pop_first (popped %d)\n", num);
	list_print(list, list_print_int);

	free_list(list);
}
void build_linked_list(LinkedList* this) {
	int i, size, num;
	puts("Before list_append:");
	linked_list_print(this, linked_list_print_int);
	for (i = 1, size = rand() % 5 + 5; i <= size; i++) {
		num = rand() % 10 + i;
		linked_list_append(this, &num);
	}

	puts("After linked_list_append:");
	linked_list_print(this, linked_list_print_int);
}
void build_list(List* this) {
	int i, size, num;
	puts("Before list_append:");
	list_print(this, list_print_int);
	for (i = 1, size = rand() % 5 + 5; i <= size; i++) {
		num = rand() % 10 + i;
		list_append(this, &num);
	}

	puts("After list_append:");
	list_print(this, list_print_int);
}
int list_print_int(void* data) {
	return data ? printf("%d->", *(int*)data) : puts("NULL");
}
int linked_list_print_int(void* data) {
	return data ? printf("%d->", *(int*)data) : puts("NULL");
}
int cmp_int(void* data1, void* data2) {
	return *(int*)data1 - *(int*)data2;
}