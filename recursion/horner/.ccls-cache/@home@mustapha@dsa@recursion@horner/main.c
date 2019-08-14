#include <stdio.h>

double e(double x, double n)
{
	double r = 1 + x/n;

	for (int i=n-1; i>0; i--)
		r = 1 + x/i * r;

	return r;
}

double er(double x, double n)
{
	static double r = 1;
	if (n > 0) {
		r = 1 + x/n * r;
		return er(x, n-1);
	}
	return r;
}

int main(int argc, char **argv)
{
	double r = e(3, 10);
	printf("e: %lf\n", r);
	double rr = er(3, 10);
	printf("er: %lf\n", rr);
	return 0;
}
