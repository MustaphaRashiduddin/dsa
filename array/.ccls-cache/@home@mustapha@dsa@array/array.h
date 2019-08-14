#ifndef ARRAY_H
#define ARRAY_H

struct array {
	int *a;
	int length;
	int size;
};

void display(struct array *arr);
struct array *init_array(int *a, int ln, int sz);
void kill_array(struct array *arr);
void append(struct array *arr, int x);
void insert(struct array *arr, int index, int n);
void rem(struct array *arr, int index);
int lin_search(struct array *arr, int x);
int bin_search(struct array *arr, int n);
int bin_rec_search_stupid(struct array *arr, int n);
int bin_rec_search(struct array *arr, int n);
int *merge_arrays(int *A, int sz_a, int *B, int sz_b);

#endif
