#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Cerius/Structs/List/List.h>
#include <Cerius/Structs/List/LinkedList.h>
#include <Cerius/Structs/Dynamic/Array.h>
int list_print_int(void*);
int linked_list_print_int(void*);
int array_print_int(void*);
int print_int(void*);
int cmp_int(void*, void*);
void build_list(List*);
void build_linked_list(LinkedList*);
void build_array(Array*);
void list_test();
void linked_list_test();
void array_test();
void init_random();
int main() {
	// Write your code below
	array_test();
		
}
void array_test() {
	int num, i, size;
	Array* arr;
	arr = new_array();

	build_array(arr);

	array_sort(arr, cmp_int);
	puts("After array_sort:");
	array_print(arr, array_print_int);

	num = 999;
	array_prepend(arr, &num);
	puts("After array_prepend for value 999:");
	array_print(arr, array_print_int);

	array_remove(arr, 0);
	puts("After array_remove for first element (removed 999)");
	array_print(arr, array_print_int);

	num = *(int*)array_get(arr, 0);
	printf("After array_get (got %d)\n", num);
	array_print(arr, array_print_int);

	free_array(arr);
	array_print(arr, print_int);

}
void linked_list_test() {
	int num, i, size;
	LinkedList* list;
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
	int num;
	List* list;
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
void build_array(Array* this) {
	int i, size, num;
	init_random();
	puts("Before array_append:");
	array_print(this, print_int);
	for (i = 1, size = rand() % 5 + 5; i <= size; i++) {
		num = rand() % 10 + i;
		array_append(this, &num);
	}

	puts("After array_append:");
	array_print(this, array_print_int);
}
void build_linked_list(LinkedList* this) {
	int i, size, num;
	init_random();
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
	init_random();
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
int array_print_int(void* data) {
	return data ? printf("%d", *(int*)data) : printf("NULL");
}
int print_int(void* data) {
	return data ? printf("%d", *(int*)data) : 0;
}
int cmp_int(void* data1, void* data2) {
	return *(int*)data1 - *(int*)data2;
}
void init_random() {
	srand((unsigned)time(NULL));
}