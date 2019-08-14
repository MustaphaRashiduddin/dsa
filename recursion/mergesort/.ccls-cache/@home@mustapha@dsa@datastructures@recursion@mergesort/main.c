#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void parr(int *a, unsigned l, unsigned r)
{
	for (int i=l; i<=r; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void sort(int *a, unsigned l, unsigned m, unsigned r)
{
	int i = 0;
	int j = 0;

	int *L = malloc(sizeof(int)*(m-l+1));
	memcpy(&L[0], &a[l], (m-l+1)*sizeof(int));
	int *R = malloc(sizeof(int)*(r-m));
	memcpy(&R[0], &a[m+1], (r-m)*sizeof(int));

	while (i <= m-l && j <= r-m-1) {
		if (L[i] < R[j]) {
			a[l+i+j] = L[i];
			i++;
		} else {
			a[l+i+j] = R[j];
			j++;
		}
	}

	memcpy(&a[l+i+j], &L[i], (m-l+1-i)*sizeof(int));
	memcpy(&a[l+i+j], &R[j], (r-m-j)*sizeof(int));

	free(L);
	free(R);
}

void mergesort(int *a, unsigned l, unsigned r)
{
	int m;
	if (l<r) {
		m = l+(r-l)/2;
		mergesort(a, l, m);
		mergesort(a, m+1, r);
		sort(a, l, m, r);
	}
}


int main(int argc, char **argv)
{
	int a[] = {38, 27, 43, 3, 9, 82, 10};
	int s = sizeof(a)/sizeof(*a);
	parr(a, 0, s-1);
	mergesort(a, 0, s-1);
	parr(a, 0, s-1);
}
