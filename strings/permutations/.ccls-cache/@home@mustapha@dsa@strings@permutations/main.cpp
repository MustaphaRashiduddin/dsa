#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::swap;
using std::string;

void perm(string &s, string &s_cpy, int l, int h);

int main(int argc, char **argv)
{
	string s = "abc";
	string s_cpy;
	perm(s, s_cpy, 0, s.size()-1);
}

void perm(string &s, string &s_cpy, int l, int h)
{
	if (l == h)
		cout << s << endl;

	for (int i=l; i<=h; i++) {
		swap(s[l], s[i]);
		perm(s, s_cpy, l+1, h);
		swap(s[l], s[i]);
	}
}
