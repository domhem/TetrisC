#pragma once
#include <vector>
using namespace std;

#define BOARD_WIDTH 10				// Board width in blocks 
#define BOARD_HEIGHT 20				// Board height in blocks

class Game;

class Board
{
public:
	
	void CreateBoard(Game &obj);
	void DisplayBoard(Game &obj);
	int DisplayGameOver(Game obj);

	//+2 and +3 to account for the border
	//This multidimensional array is used to help manipulate the blocks
	int stage[BOARD_HEIGHT + 2][BOARD_WIDTH + 3];
	//This multidimensional array is used to create the board
	int board[BOARD_HEIGHT + 2][BOARD_WIDTH + 3];

};