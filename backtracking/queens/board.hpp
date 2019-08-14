#ifndef _BOARD_HPP
#define _BOARD_HPP

#include <iostream>

class board
{
	private:
	int n;
	char **bd;
	int *queens;

	public:
	board(int n);
	~board();

	friend std::ostream& operator<<(std::ostream& os, const board& _board);
	void pop_queens(int l);
	void chk();
};

#endif
