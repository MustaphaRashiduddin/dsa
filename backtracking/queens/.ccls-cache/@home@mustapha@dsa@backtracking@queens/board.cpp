#include "board.hpp"

using std::endl;
using std::ostream;

board::board(int n)
{
	this->n = n;
	bd = new char*[n];
	for (int i=0; i<n; i++)
		bd[i] = new char[n];

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			bd[i][j] = '0';

	queens = new int[n];

	// testing
	bd[1][3] = 'X';
	bd[2][0] = 'X';
	bd[3][2] = 'X';

	queens[1] = 3;
	queens[2] = 0;
	queens[3] = 2;
}

board::~board()
{
	for (int i=0; i<n; i++)
		delete [] bd[i];
	delete [] bd;
	delete [] queens;
}

ostream& operator<<(ostream& os, const board& _board)
{
	for (int i=0; i<_board.n; i++) {
		for (int j=0; j<_board.n; j++)
			os << _board.bd[i][j] << " ";
			// os << "(" << i << "," << j << ")";
		os << endl;
	}
	return os;
}

void board::pop_queens(int l)
{
	for (int i=l; i<n; i++) {
		// pop_queens(l+1);
		chk();
	}
}

void board::chk()
{
	for (int i=1; i<n; i++) {
		// std::cout << queens[i];
		if (i ==ZZi 
	}
}
