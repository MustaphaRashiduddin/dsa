#include <iostream>
#include <sstream>
#include "assert.h"

using std::cout;
using std::endl;
using std::istringstream;

int fib(int n);
int fib(int n, int *M);

int main(int argc, char **argv)
{
	assert(argc == 2 && "must have 1 arg");
	int n;
	istringstream iss(argv[1]);
	iss >> n;
	assert(iss.fail() == false && "arg must be a number");
	cout << fib(n) << endl;
}

int fib(int n)
{
	int *M = new int[n+1];
	for (int i=0; i<=n; i++)
		M[i] = -1;
	int res = fib(n, M);
	delete [] M;
	return res;
}

int fib(int n, int *M)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;

	if (M[n]<0)
		M[n] = fib(n-1, M) + fib(n-2, M);
	return M[n];
}
