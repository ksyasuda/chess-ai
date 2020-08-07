#ifndef BOARD_H
#define BOARD_H

#include <vector>
// #include <string>

constexpr auto RED = "\033[31m";
constexpr auto GREEN = "\033[32m";
constexpr auto YELLOW = "\033[33m";
constexpr auto BLUE = "\033[34m";
constexpr auto WHITE = "\033[90m"; //! 8
constexpr auto ORANGE = "\033[96m";
constexpr auto BLACK = "\033[93m"; //! 7
constexpr auto PURPLE = "\033[95m";
constexpr auto CYAN = "\033[36m";
constexpr auto RESET = "\033[0m";



class Board {
public:
	std::vector<std::vector<std::pair<char, char>>> board;
	const char* colors[11] = {RED, ORANGE, YELLOW, GREEN, BLUE, CYAN, PURPLE, BLACK, WHITE, RESET };

	void initBoard();

	void printBoard();
};

#endif