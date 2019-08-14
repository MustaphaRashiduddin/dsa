#include <stdio.h>
#include <stdlib.h>

int pow_1(int m, int n)
{
	if (n>0)
		return m * pow_1(m, n-1);
	return 1;
}

int pow_2(int m, int n)
{
	if (n==0)
		return 1;
	if (n%2==0)
		return pow_2(m*m, n/2);
	else
		return m*pow_2(m*m, (n-1)/2);

}

int powi(int m, int n)
{
	return n;
}

int main(int argc, char **argv)
{
	printf("%d\n", pow_2(9, 3));
	return 0;
}
