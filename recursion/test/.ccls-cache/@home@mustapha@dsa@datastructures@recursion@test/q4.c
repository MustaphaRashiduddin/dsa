#include <stdio.h>

int fun(int n)
{
	int x=1; 
	int k;
	if (n==1)
		return x;
	for (k=1; k<n; ++k)
		x = x+fun(k)*fun(n-k);
	return x;

}

int main(int argc, char **argv)
{
	printf("%d\n", fun(5));
}
