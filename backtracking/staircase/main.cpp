#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::vector;

int stairs(int n);
int stairs(int n, int *M);

int main(int argc, char **argv)
{
	cout << stairs(75) << endl;
}

int stairs(int n)
{
	int *M = new int[n+1];
	for (int i=0; i<=n; i++)
		M[i] = -1;
	int res = stairs(n, M);
	delete [] M;
	return res;
}
int stairs(int n, int *M)
{

	if (n==0)
		return 1;
	if (n<0)
		return 0;

	if (M[n] < 0)
		M[n] = stairs(n-1, M)+stairs(n-2, M);
	return M[n];
}
