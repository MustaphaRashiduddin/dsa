#include <stdio.h>

void count(int n)
{
	static int d = 1;
	printf("%d", n);
	printf("%d", d);
	d++;
	if (n>1)
		count(n-1);
	printf("%d", d);
}

int main(int argc, char **argv)
{
	count(3);
}
