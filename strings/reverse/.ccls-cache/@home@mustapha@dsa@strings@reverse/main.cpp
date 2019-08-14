#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	string s = "Welcome";
	cout << s << endl;
	for (int i=0; i<s.size()/2; i++) {
		swap(s[i], s[s.size()-i-1]);
	}
	cout << s << endl;
}
