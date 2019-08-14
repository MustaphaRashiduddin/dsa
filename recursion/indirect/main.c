#include <stdio.h>

void fun2(int n);
void fun1(int n)
{
	if (n>0) {
		fprintf(stderr, "%d ", n);
		fun2(n-1);
	}
}

void fun2(int n)
{
	if (n>1) {
		fprintf(stderr, "%d ", n);
		fun1(n/2);
	}
}

int main(int argc, char **argv)
{
	fun1(20);
	return 0;
}
