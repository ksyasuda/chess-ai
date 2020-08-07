#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <vector>

class Player {
public:
	std::vector<std::vector<char>> pieces;
	unsigned player_color;
	unsigned remaining_pieces = 16;

	Player(const unsigned color, const unsigned num);
};


#endif