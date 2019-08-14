#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>

struct array {
	int *a;
	int length;
	int size;
};

void display(struct array *arr);
struct array *init_array(int ln, int sz);
void kill_array(struct array *arr);
void populate_array(struct array *arr);
void append(struct array *arr, int x);
void insert(struct array *arr, int index, int n);
void rem(struct array *arr, int index);
bool search(struct array *arr, int x);

#endif
