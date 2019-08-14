#include <stdio.h>

void foo(int n)
{
	if (n>0)
	{
		fprintf(stderr, "%d ", n);
		foo(n-1);
		foo(n-1);
	}
}

int main(int argc, char **argv)
{
	foo(3);
	return 0;
}
