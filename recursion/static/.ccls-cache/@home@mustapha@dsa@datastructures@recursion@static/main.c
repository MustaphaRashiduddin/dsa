#include <stdio.h>

int foo(int n)
{
	static int x = 0;
	if (n>0) {
		x++;
		return foo(n-1) + x;
	}
	return 0;
}

int main(int argc, char **argv)
{
	fprintf(stderr, "%d\n", foo(5));
	return 0;
}
