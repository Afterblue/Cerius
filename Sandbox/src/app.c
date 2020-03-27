#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Cerius/Structs.h>
int print_int(void*);
int cmp_int(void*, void*);
void build_list(List*);
int main() {
	// Write your code below
	int num, i, size;
	List* list;
	srand((unsigned)time(NULL));
	list = new_list();

	build_list(list);

	list_sort(list, cmp_int);
	puts("After list_sort:");
	list_print(list, print_int);

	num = 111;
	list_prepend(list, &num);
	puts("After list_prepend for value 111:");
	list_print(list, print_int);

	num = 22;
	list_add(list, 3, &num);
	puts("After list_add for value 22:");
	list_print(list, print_int);

	list_remove_first(list);
	puts("After list_remove_first (removed 111)");
	list_print(list, print_int);

	num = *(int*)list_pop_first(list);
	printf("After list_pop_first (popped %d)\n", num);
	list_print(list, print_int);

	free_list(list);
}
void build_list(List* this) {
	int i, size, num;
	puts("Before list_append:");
	list_print(this, print_int);
	for (i = 1, size = rand() % 5 + 5; i <= size; i++) {
		num = rand() % 10 + i;
		list_append(this, &num);
	}

	puts("After list_append:");
	list_print(this, print_int);
}
int print_int(void* data) {
	return data ? printf("%d->", *(int*)data) : puts("NULL");
}
int cmp_int(void* data1, void* data2) {
	return *(int*)data1 - *(int*)data2;
}