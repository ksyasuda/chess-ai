#include "../headers/board.h"
#include <iostream>
#include <vector>
#include <string>
#include <functional>



std::vector<std::pair<char, char>> Bpieces; //= {'R', 'k', 'B', 'K', 'Q', 'B', 'k', 'R', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};
std::vector<std::pair<char, char>> Wpieces; //= {'R', 'k', 'B', 'Q', 'K', 'B', 'k', 'R', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};

std::vector<char> Bpieces2 = {'R', 'k', 'B', 'K', 'Q', 'B', 'k', 'R', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};
std::vector<char> Wpieces2 = {'R', 'k', 'B', 'Q', 'K', 'B', 'k', 'R', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};


static void make_pairs() {
	unsigned count = 0;
	Bpieces.reserve(16);
	Bpieces2.reserve(16);
	for(auto i : Bpieces2) {
		auto temp = std::make_pair(i, 'b');
		auto temp2 = std::make_pair(Wpieces2[count++], 'w');
		Bpieces.push_back(temp);
		Wpieces.push_back(temp2);
	}
}


//* initialize the vector to an 8x8 board
void Board::initBoard() {
	const int size = 8;
	make_pairs();
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
			board[i][j].first = ' ';
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

static void blankLine() {
	for(auto i = 0; i < 8; ++i) {
		if(i == 0)
			std::cout << "|       |";
		else if(i == 7)
			std::cout << "       |\n";
		else
			std::cout << "       |";
	}
	// std::cout << "\n";
}

void Board::printBoard() {
	auto size = board.size();
	char letter = 'A';
	topbottom();
	for(long unsigned i = 0; i < size; ++i) {
		blankLine();
		for(long unsigned j = 0; j < size; ++j) {
			if (j == 0) {
				if(board[i][j].second == 'w')
					std::cout << "|   " << colors[8] << board[i][j].first << colors[9] << "   |";
				else if(board[i][j].second == 'b')
					std::cout << "|   " << colors[7] << board[i][j].first << colors[9] << "   |";
				else
					std::cout << "|   " << board[i][j].first << "   |";
			}
			else if (j == size - 1){
				if(board[i][j].second == 'w')
					std::cout << "   " << colors[8] << board[i][j].first << colors[9] << "   |";
				else if(board[i][j].second == 'b')
					std::cout << "   " << colors[7] << board[i][j].first << colors[9] << "   |";
				else
					std::cout << "   " << board[i][j].first << "   |";
				std::cout << "   " << letter++ << "\n";
			}
			else {
				if(board[i][j].second == 'w')
					std::cout << "   " << colors[8] << board[i][j].first << colors[9] << "   |";
				else if(board[i][j].second == 'b')
					std::cout << "   " << colors[7] << board[i][j].first << colors[9] << "   |";
				else
					std::cout << "   " << board[i][j].first << "   |";
			}
		}
		blankLine();
		inbetween(i, size);
	}
	topbottom();
	auto num = 1;
	for(auto i = 0; i < 8; ++i) {
		std::cout << "    " << num++ << "   ";
	}
	std::cout << "\n";
}
