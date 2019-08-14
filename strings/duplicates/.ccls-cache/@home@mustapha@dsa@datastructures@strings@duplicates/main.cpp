#include <iostream>
#include <setjmp.h>

using std::string;
using std::cout;
using std::endl;

void mergesort(string &s, int l, int r);
void mergesort(string &s);
bool contains_duplicate(const string &s);
void sort(string &s, int l, int m, int r);
bool contains_duplicate_sorted(const string &s);

static jmp_buf buf;

int main(int argc, char **argv)
{
	string s = "Mustapha";
	cout << s << endl;
	mergesort(s);
	cout << s << endl;
}

void mergesort(string &s)
{
	mergesort(s, 0, s.size()-1);
}

void mergesort(string &s, int l, int r)
{
	if (l>=r)
		return;

	int m = l+(r-l)/2;
	mergesort(s, l, m);
	mergesort(s, m+1, r);
	sort(s, l, m, r);
}

void sort(string &s, int l, int m, int r)
{
	string L;
	for (int i=l; i<=m; i++)
		L.push_back(s[i]);

	string R;
	for (int i=m+1; i<=r; i++)
		R.push_back(s[i]);


	int i=0;
	int j=0;
	while (i<L.size() && j<R.size()) {
		if (L[i] < R[j]) {
			s[l+i+j] = L[i];
			i++;
		} else if (L[i] > R[j]) {
			s[l+i+j] = R[j];
			j++;
		} else {
			// jump out of function: longjmp setjmp
			s[l+i+j] = R[j];
			j++;
		}
	}

	while (i<L.size()) {
		s[l+i+j] = L[i];
		i++;
	}
	while (j<R.size()) {
		s[l+i+j] = R[j];
		j++;
	}
}

bool contains_duplicate_sorted(const string &s)
{
	for (int i=0; i<s.size()-1; i++)
		if (s[i] == s[i+1])
			return true;
	return false;
}

bool contains_duplicate(const string &s)
{
	for (int i=0; i<s.size()-1; i++)
		for (int j=i+1; j<s.size(); j++)
			if (s[i] == s[j])
				return true;
	return false;
}
