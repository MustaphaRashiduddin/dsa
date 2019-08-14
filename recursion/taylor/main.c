#include <stdio.h>

double e(int x, int n)
{
	static double p = 1;
	static double f = 1;

	if (n>0) {
		double r = e(x, n-1);
		p *= x;
		f *= n;
		return r + p/f;
	}

	return 1;
}

int main(int argc, char **argv)
{
	double r = e(4, 15);
	printf("%lf\n", r);
	return 0;
}
