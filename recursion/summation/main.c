#include <stdio.h>

int summation(int n)
{
	if (n>0)
		return n + summation(n-1);
	return 0;
}

int isum(int n)
{
	int sum = 0;
	for (int i=0; i<n; i++)
	{
		sum += i;
	}
	return sum;
}

int main(int argc, char **argv)
{
	int n = 55555;
	printf("rec: %d\n", summation(n));
	printf("it: %d\n", summation(n));
	return 0;
}
