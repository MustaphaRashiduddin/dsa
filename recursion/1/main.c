#include <stdio.h>

void cal(int n)
{
	if (n>0) {
		fprintf(stderr, "%d ", n);
		cal(n-1);
	}
}

void ret(int n)
{
	if (n>0) {
		ret(n-1);
		fprintf(stderr, "%d ", n);
	}
}

int main(int argc, char **argv)
{
	int n = 3;
	fprintf(stderr, "process on call\n");
	cal(n);
	printf("\n");
	fprintf(stderr, "process on return\n");
	ret(n);
	printf("\n");
	return 0;
}
