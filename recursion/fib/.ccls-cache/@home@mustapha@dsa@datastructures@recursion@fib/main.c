#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

int fibm_1(int n, int *cache)
{
	if (n>2) {
		if (cache[n-1] != 0)
			return cache[n-1];
		cache[n-1] = fibm_1(n-1, cache) + fibm_1(n-2, cache);
		return cache[n-1];
	}
	return 1;
}
int fibm(int n)
{
	assert(n>0);
	int *cache = malloc(n*sizeof(int));

	for (int i=0; i<n; i++) 
		cache[i] = 0;

	int r = fibm_1(n, cache);
	free(cache);
	return r;
}

int fibr(int n)
{
	assert(n>0);
	if (n>2)
		return fibr(n-1) + fibr(n-2);
	return 1;
}

int fibi(int n)
{
	assert(n>0);

	if (n==1 || n==2) return 1;

	int t1 = 1;
	int t2 = 1;
	int s = 0;

	for (int i=2; i<n; i++)
	{
		s = t1 + t2;
		t1 = t2;
		t2 = s;
	}

	return s;
}

int main(int argc, char **argv)
{
	assert(argc == 2); // one digit needed as argument
	assert(isdigit(argv[1][0])); // checkin if you providing a digit 

	int n = atoi(argv[1]);
	int rm = fibm(n);
	printf("memoization: %d\n", rm);
	int rr = fibr(n);
	printf("simple recursion: %d\n", rr);
	int ri = fibi(n);
	printf("iteration: %d\n", ri);
	return 0;
}
