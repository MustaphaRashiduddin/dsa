#include <stdio.h>

int i=0;
void toh(int n, char a, char b, char c)
{
	if (n>0)
	{
		toh(n-1, a, c, b);
		printf("%d: %c -> %c\n", ++i, a, c);
		toh(n-1, b, a, c);
	}
}

int main(int argc, char **argv)
{
	toh(3, 'a', 'b', 'c');
}
