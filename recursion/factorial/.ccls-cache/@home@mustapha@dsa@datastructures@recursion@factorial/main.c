#include <stdio.h>
#include <assert.h>

int factorial(int n)
{
	assert(n > -1);
	
	if (n>1)
		return n * factorial(n-1);
	return 1;
}

int facti(int n)
{
	int s = 1;
	for (int i=1; i<=n; i++)
		s*=i;
	return s;
}

int main(int argc, char **argv)
{
	printf("recursive %d\n", factorial(3));
	printf("iterative %d\n", facti(3));
	return 0;
}
