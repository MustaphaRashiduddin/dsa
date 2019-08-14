#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void parr(int *a, int l, int r)
{
	for (int i=l; i<=r; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void sort(int *a, int l, int m, int r)
{
	int *L = malloc(sizeof(int)*(m-l+1));
	memcpy(&L[0], &a[l], sizeof(int)*(m-l+1));
	int *R = malloc(sizeof(int)*(r-m));
	memcpy(&R[0], &a[m+1], sizeof(int)*(r-m));

	int i=0;
	int j=0;
	while (i <= m-l && j <= r-m-1) {
		if (L[i] < R[j]) {
			a[l+i+j] = L[i];
			i++;
		} else {
			a[l+i+j] = R[j];
			j++;
		}
	}

	memcpy(&a[l+i+j], &L[i], sizeof(int)*(m-l+1-i));
	memcpy(&a[l+i+j], &R[j], sizeof(int)*(r-m-j));

	free(L);
	free(R);
}

void mergesort(int *a, int l, int r)
{
	if (l<r) {
		int m = l+(r-l)/2;
		mergesort(a, l, m);
		mergesort(a, m+1, r);
		sort(a, l, m, r);
	}
}

int main(int argc, char **argv)
{
	int a[] = {38, 27, 43, 3, 9, 82, 10};
	int sz = sizeof(a)/sizeof(*a);
	mergesort(a, 0, sz-1);
	parr(a, 0, sz-1);
}
