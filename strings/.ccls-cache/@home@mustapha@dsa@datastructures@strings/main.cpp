#include <iostream>
#include <string>

using namespace std;

void swp(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(int argc, char **argv)
{
	string s = "Welcome";
	cout << s << endl;
	for (int i=0; i<s.size()/2; i++) {
		swp(&s[i], &s[s.size()-i-1]);
	}
	cout << s << endl;
}
