#include <iostream>
#include <string>
#include <bitset>

using std::cout;
using std::endl;
using std::string;
using std::bitset;

bool is_anagram_bit(string &s1, string &s2);
bool is_anagram_hsh(string &s1, string &s2);

int main(int argc, char **argv)
{
	string s1 = "decimal";
	string s2 = "medical";
	cout << is_anagram_hsh(s1, s2) << endl;
	cout << is_anagram_bit(s1, s2) << endl;
}

bool is_anagram_hsh(string &s1, string &s2)
{
	if (s1.size() != s2.size())
		return false;

	int *A = new int[26];
	for (unsigned i=0; i<26; i++)
		A[i] = 0;

	for (unsigned i=0; i<s1.size(); i++)
		A[s1[i]-97] = 1;

	for (unsigned i=0; i<s2.size(); i++)
		if ((A[s2[i]-97]) == 0) {
			delete [] A;
			return false;
		}

	delete [] A;
	return true;
}

bool is_anagram_bit(string &s1, string &s2)
{
	if (s1.size() != s2.size())
		return false;

	int A = 0;
	for (unsigned i=0; i<s1.size(); i++) {
		int H = 1;
		H = H << (int(s1[i]-97));
		A = A | H;
	}

	for (unsigned i=0; i<s2.size(); i++) {
		int H = 1;
		H = H << (int(s2[i]-97));
		A = A ^ H;
	}

	return !A;
}
