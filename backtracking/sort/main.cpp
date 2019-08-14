#include <iostream>

using std::cout;
using std::endl;
using std::swap;

void sort(int *A, int l, int r);
void parr(int *A, int l, int r);

int main(int argc, char **argv)
{
	int A[] = {38, 27, 43, 3, 9, 82, 10};
	int sz = sizeof(A)/sizeof(*A);

	parr(A, 0, sz-1);
	sort(A, 0, sz-1);
	parr(A, 0, sz-1);
}

void sort(int *A, int l, int r)
{
	if (l > r)
		return;

	sort(A, l+1, r);
	for (int i=l; i<r; i++)
		if (A[i] > A[i+1])
			swap(A[i], A[i+1]);
}

void parr(int *A, int l, int r)
{
	for (int i=l; i<=r; i++)
		cout << A[i] << " ";
	cout << endl;
}
