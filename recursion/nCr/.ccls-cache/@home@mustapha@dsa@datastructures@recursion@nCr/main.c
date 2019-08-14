#include <stdio.h>
#include <stdlib.h>

// via pascal's triangle
int nCr(int n, int r)
{
	if (r == 0 || r == n)
		return 1;
	return nCr(n-1, r-1) + nCr(n-1, r);
}

int nCrm1(int n, int r, int **cache)
{
	if (r == 0 || r == n)
		return 1;

	if (cache[n-1][r-1] != 0)
		return cache[n-1][r-1];

	cache[n-1][r-1] = nCrm1(n-1, r-1, cache) + nCrm1(n-1, r, cache);
	return cache[n-1][r-1];
}
int nCrm(int n, int r) // i guess space will end up n*r
{
	int **cache = malloc(sizeof(int*)*n);
	for (int i=0; i<n; i++) {
		cache[i] = malloc(sizeof(int)*r);
		for (int j=0; j<r; j++)
			cache[i][j] = 0;
	}
	int res = nCrm1(n, r, cache);
	for (int i=0; i<n; i++)
		free(cache[i]);
	free(cache);
	return res;
}

int main(int argc, char **argv)
{
	int t1 = 32;
	int t2 = 16;
	int r = nCr(t1, t2);
	printf("nCr: %d\n", r);
	int rm = nCrm(t1, t2);
	printf("nCrm: %d\n", rm);
	return 0;
}
