#include "array.h"
#include "stdio.h"
#include "stdlib.h"

void parr(int *a, int l, int r)
{
	for (int i=l; i<=r; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	int a[] = {4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43};
	int sz = sizeof(a)/sizeof(*a);
	struct array *arr = init_array(a, sz, sz);
	display(arr);
	printf("index: %d\n", bin_rec_search(arr, 24));
	kill_array(arr);

	int A[] = {3, 8, 16, 20, 25};
	int B[] = {4, 10, 22, 23};
	int sz_a = sizeof(A)/sizeof(*A);
	int sz_b = sizeof(B)/sizeof(*B);
	int *C = merge_arrays(A, sz_a, B, sz_b);

	printf("--------------\n");
	parr(A, 0, sz_a-1);
	parr(B, 0, sz_b-1);
	parr(C, 0, sz_a+sz_b-1);
	free(C);
}
