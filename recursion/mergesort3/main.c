#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

static int counter = 0;

void parr(int *A, int l, int r)
{
	printf("%d - %d: ", l, r);
	for (int i=l; i<=r; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void merge3(int *A, int l, int m1, int m2, int r)
{
	printf("merge3 ");
	parr(A, l, r);
}

void mergesort(int *A, int l, int r);
void merge(int *A, int l, int m, int r);
void mergesort3(int *A, int l, int r)
{
	if (r-l < 6) {
		int m = l+(r-l)/2;
		mergesort(A, l, r);
	} else {
		int m1 = l+(r-l)/3;
		int m2 = l+2*((r-l)/3)+1;
		mergesort3(A, l, m1);
		mergesort3(A, m1+1, m2);
		mergesort3(A, m2+1, r);
		merge3(A, l, m1, m2, r);
	}
}

void merge(int *A, int l, int m, int r)
{
	printf("merge: ");
	parr(A, l, r);
}

void mergesort(int *A, int l, int r)
{
	if (l>=r)
		return;
	int m = l+(r-l)/2;
	mergesort(A, l, m);
	mergesort(A, m+1, r);
	merge(A, l, m, r);
	counter++;
}

void mergesort3_gkg(int *A, int l, int r)
{
	if (r-l < 2)
		return;
	int m1 = l + ((r-l)/3);
	int m2 = l + 2 * ((r-l)/3) + 1;

	mergesort3_gkg(A, l, m1);
	mergesort3_gkg(A, m1, m2);
	mergesort3_gkg(A, m2, r);
	merge3(A, l, m1, m2, r);
}

int main(int argc, char **argv)
{
	/* int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50}; */
	int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sz = sizeof(A)/sizeof(*A);
	mergesort(A, 0, sz-1);
	printf("%d steps\n", counter);
}
