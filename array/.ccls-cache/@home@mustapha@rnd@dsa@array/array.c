#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>

void display(struct array *arr)
{
	for (int i=0; i<arr->length; i++)
		printf("%d ", arr->a[i]);
	printf("\n");
}

struct array *init_array(int *a, int ln, int sz)
{
	assert(sz >= ln);

	struct array *arr = malloc(sizeof(struct array));
	arr->a = malloc(sizeof(int)*sz);
	arr->length = ln;
	arr->size = sz;
	memcpy(arr->a, a, sizeof(int)*ln);
	return arr;
}

void kill_array(struct array *arr)
{
	free(arr->a);
	free(arr);
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

int lin_search(struct array *arr, int x)
{
	for (int i=0; i<arr->length; i++)
		if (x == arr->a[i])
			return i;
	return -1;
}

int bin_search(struct array *arr, int n)
{
	int l = 0;
	int r = arr->length-1;
	int m;
	int *a = arr->a;

	while (l<=r) {
		m = l+(r-l)/2;
		if (a[m] > n)
			r = m-1;
		else if (a[m] < n)
			l = m+1;
		else
			return m;
	}
	return -1;
}

int bin_rec_search1(struct array *arr, int n, int l, int r);
int bin_rec_search(struct array *arr, int n)
{
	return bin_rec_search1(arr, n, 0, arr->length-1);
}
int bin_rec_search1(struct array *arr, int n, int l, int r)
{
	if (l<=r) {
		int m = l+(r-l)/2;
		if (arr->a[m] > n)
			return bin_rec_search1(arr, n, l, m-1);
		else if (arr->a[m] < n)
			return bin_rec_search1(arr, n, m+1, r);
		else
			return m;
	}
	return -1;
}

int *merge_arrays(int *A, int sz_a, int *B, int sz_b)
{
	int *RES = malloc(sizeof(int)*(sz_a+sz_b));

	int i=0;
	int j=0;
	while (i<sz_a && j<sz_b) {
		if (A[i] < B[j]) {
			RES[i+j] = A[i];
			i++;
		} else {
			RES[i+j] = B[j];
			j++;
		}
	}

	memcpy(RES+i+j, A+i, sizeof(int)*(sz_a-i));
	memcpy(RES+i+j, B+j, sizeof(int)*(sz_b-j));

	return RES;
}
