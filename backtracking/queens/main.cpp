#include <iostream>
#include "board.hpp"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	board _board(4);
	_board.pop_queens(3);
}
