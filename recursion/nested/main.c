#include <stdio.h>

int foo(int n)
{
	if (n>100)
		return n-10;
	else
		return foo(foo(n+11));
}

int main(int argc, char **argv)
{
	fprintf(stderr, "%d\n", foo(95));
}
