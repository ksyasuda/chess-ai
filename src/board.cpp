#include "../headers/board.h"
#include <iostream>
#include <vector>
#include <string>

//* 
std::vector<char> Bpieces = {'R', 'k', 'B', 'K', 'Q', 'B', 'k', 'R', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};
std::vector<char> Wpieces = {'R', 'k', 'B', 'Q', 'K', 'B', 'k', 'R', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};


//* initialize the vector to an 8x8 board
void Board::initBoard() {
	const int size = 8;
	board.resize(size);
	for(int i = 0; i < size; ++i) {
		board[i].resize(size);
	}
	int counter = 0;
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < size; ++j) {
			board[i][j] = Bpieces[counter];
			board[size-i-1][j] = Wpieces[counter++];
		}
	}
	for(int i = 2; i <= 5; ++i) {
		for(int j = 0; j < 8; ++j) {
			board[i][j] = ' ';
		}
	}
}

static void topbottom() {
	for(int a = 0; a < 8; ++a) {
		if(a == 0) std::cout << "+-------+";
		else std::cout << "-------+";
	}
	std::cout << "\n";
}

static void inbetween(unsigned long i, size_t size) {
	if(i != size-1) {
		for(int b = 0; b < 8; ++b) {
			if(b == 7) std::cout << "+-------+";
			else std::cout << "+-------";
		}
		std::cout << "\n";
	}
}

void Board::printBoard() {
	auto size = board.size();
	bool needSpace = true;
	topbottom();
	for(long unsigned i = 0; i < size; ++i) {
		for(long unsigned j = 0; j < size; ++j) {
			if(board[i][j] != ' ') needSpace = false;
			if(!needSpace) {
				if(j == 0) std::cout << "|   " << board[i][j] << "   |";
				else if(j == size-1) std::cout << "   " << board[i][j] << "   |\n";
				else std::cout << "   " << board[i][j] << "   |";
			}
			else {
				if(j == 0) std::cout << "|     " << board[i][j] << "     |";	
				else if(j == size-1) std::cout << "     " << board[i][j] << "     |\n";
				else std::cout << "     " << board[i][j] << "     |";
			}
		}
		inbetween(i, size);
	}
	topbottom();
}
