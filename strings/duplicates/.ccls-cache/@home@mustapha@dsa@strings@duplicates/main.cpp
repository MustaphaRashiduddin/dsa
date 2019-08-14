#include <iostream>
#include <setjmp.h>
#include <bitset>

using std::string;
using std::cout;
using std::endl;
using std::bitset;

bool contains_duplicate(const string &s);
bool contains_duplicate_sorted(const string &s);
bool chk_duplicates_ms(string s);
bool chk_duplicates_hash(const string &s);

bool mergesort(string &s);
void mergesort(string &s, int l, int r, jmp_buf env);
void sort(string &s, int l, int m, int r, jmp_buf env);

bool chk_duplicates_bit(const string &s);

int main(int argc, char **argv)
{
	string s = "finding";
	cout << chk_duplicates_bit(s) << endl;
}

bool chk_duplicates_bit(const string &s)
{
	int A = 0;
	for (unsigned i=0; i<s.size(); i++) {
		int H = 1;
		H = H << ((int)s[i]-97);
		if (A & H) 
			return true;
		A = A | H;
	}
	return false;
}

bool chk_duplicates_hash(const string &s)
{
	int *A = new int[26];

	for (unsigned i=0; i<26; i++)
		A[i] = 0;

	for (unsigned i=0; i<s.size(); i++) {
		if (A[(int)s[i]-97] != 0) {
			delete [] A;
			return true;
		}
		A[(int)s[i]-97]++;
	}

	delete [] A;
	return false;
}

bool chk_duplicates_ms(string s)
{
	jmp_buf env;
	if (!setjmp(env)) {
		mergesort(s, 0, s.size()-1, env);
	} else {
		return true;
	}
	return false;
}

void mergesort(string &s, int l, int r, jmp_buf env)
{
	if (l>=r)
		return;

	int m = l+(r-l)/2;
	mergesort(s, l, m, env);
	mergesort(s, m+1, r, env);
	sort(s, l, m, r, env);
}

void sort(string &s, int l, int m, int r, jmp_buf env)
{
	string L;
	for (int i=l; i<=m; i++)
		L.push_back(s[i]);

	string R;
	for (int i=m+1; i<=r; i++)
		R.push_back(s[i]);


	unsigned i=0;
	unsigned j=0;
	while (i<L.size() && j<R.size()) {
		if (L[i] < R[j]) {
			s[l+i+j] = L[i];
			i++;
		} else if (L[i] > R[j]) {
			s[l+i+j] = R[j];
			j++;
		} else {
			longjmp(env, 1);
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
	for (unsigned i=0; i<s.size()-1; i++)
		if (s[i] == s[i+1])
			return true;
	return false;
}

bool contains_duplicate(const string &s)
{
	for (unsigned i=0; i<s.size()-1; i++)
		for (unsigned j=i+1; j<s.size(); j++)
			if (s[i] == s[j])
				return true;
	return false;
}
