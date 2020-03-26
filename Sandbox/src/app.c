#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Cerius/Structs/SLList.h>
int print_int(void*);
int main() {
	// Write your code below
	int num, i, size;
	SLList* list;
	srand((unsigned)time(NULL));
	list = new_list();
	for (i = 0, size = rand() % 5 + 3; i < size; i++) {
		num = rand() % 10 + i;
		list_append(list, &num);
	}
	list_print(list, print_int);
}
int print_int(void* data) {
	return data ? printf("%d->", *(int*)data) : puts("NULL");
}