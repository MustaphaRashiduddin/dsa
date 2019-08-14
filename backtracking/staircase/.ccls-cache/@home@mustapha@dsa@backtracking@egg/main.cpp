#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;

void stairs(int n)
{
	if (n<1)
		return;

	stairs(n-2);
	stairs(n-1);
}

int main(int argc, char **argv)
{
	stairs(2);
}

