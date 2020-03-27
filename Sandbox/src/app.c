#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Cerius/Structs/List.h>
int print_int(void*);
int cmp_int(void*, void*);
int main() {
	// Write your code below
	int num, i, size;
	List* list;
	srand((unsigned)time(NULL));
	list = new_list();
	for (i = 0, size = rand() % 5 + 3; i < size; i++) {
		num = rand() % 10 + i;
		list_append(list, &num);
	}
	puts("Before list_sort:");
	list_print(list, print_int);
	list_sort(list, cmp_int);
	puts("After list_sort:");
	list_print(list, print_int);
}
int print_int(void* data) {
	return data ? printf("%d->", *(int*)data) : puts("NULL");
}
int cmp_int(void* data1, void* data2) {
	return *(int*)data1 - *(int*)data2;
}