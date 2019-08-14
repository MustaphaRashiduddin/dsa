#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void display(struct array *arr)
{
	for (int i=0; i<arr->length; i++)
		printf("%d ", arr->a[i]);
	printf("\n");
}

struct array *init_array(int ln, int sz)
{
	assert(sz >= ln);

	struct array *arr = malloc(sizeof(struct array));
	arr->a = malloc(sizeof(int)*sz);
	arr->length = ln;
	arr->size = sz;
	populate_array(arr);
	return arr;
}

void kill_array(struct array *arr)
{
	free(arr->a);
	free(arr);
}

void populate_array(struct array *arr)
{
	int n = 2;
	for (int i=0; i<arr->length; i++)
		arr->a[i] = n++;
}

void append(struct array *arr, int x)
{
	assert(arr->length < arr->size);
	arr->a[arr->length++] = x; 
}

void insert(struct array *arr, int index, int n)
{
	assert(arr->length < arr->size);
	assert(arr->length >= index);

	for (int i=arr->length; i>index; i--)
		arr->a[i] = arr->a[i-1];
	arr->a[index] = n;
	arr->length++;
}

void rem(struct array *arr, int index)
{
	assert(arr->length > index);
	assert(arr->length >= 0);

	for (int i=index; i<arr->length; i++) {
		arr->a[i] = arr->a[i+1];
	}
	arr->length--;
}

bool search(struct array *arr, int x)
{
	for (int i=0; i<arr->length; i++)
		if (x == arr->a[i]) 
			return true;
	return false;
}
