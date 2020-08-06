#ifndef BOARD_H
#define BOARD_H

#include <vector>
// #include <string>

class Board {
public:
	std::vector<std::vector<char>> board;

	void initBoard();

	void printBoard();
};

#endif