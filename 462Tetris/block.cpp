#include "block.h"
#include <random>
#include <iostream>
#include <conio.h>
using namespace std;



bool Block::CreateBlock(Board &boardobj, Game &gameobj)
{
	// reeset coordinates to starting position
	x = 4;
	y = 0;

	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(0, 6); // define the range

	// Create one of the 7 blocktypes randomly
	bType = distr(eng);


	// iterate through a 4x4 matrix to create a block using the randomly chosen blocktype integer
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			// reset the block index to be 0 first
			block[i][j] = 0;
			block[i][j] = block_list[bType][i][j];
		}
	}


	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			//Move the generated block to the starting position on the board
			boardobj.board[i][j + 4] = boardobj.stage[i][j + 4] + block[i][j];
			//if the starting position is blocked, its a gameover
			if (boardobj.board[i][j + 4] > 1)
			{
				gameobj.gameover = true;
				return true;
			}
		}
	}
	return false;

}

//Update the current block position during gameplay
//Also call CreateBlock when a block has been placed
void Block :: SpawnBlock(Board &boardobj, Game &gameobj)
{
	//if there is no collision, update block to new coordinates
	if (!Collide(boardobj, x, y + 1))
	{
		MoveBlock(gameobj, boardobj, x, y + 1);
	}
	//if a block has been placed, increase the score, update collision map, and create a new block
	else
	{
		// 25 points per block
		gameobj.nScore += 25;

		UpdateCollision(boardobj);
		CreateBlock(boardobj, gameobj);
		boardobj.DisplayBoard(gameobj);
	}



}

//Checks to see if the current piece will collide with anything
bool Block::Collide(Board &boardobj, int bx, int by)
{
	//check the block's 4x4 matrix
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			//if there is an overlap, the block collided 
			if (block[i][j] && boardobj.stage[by + i][bx + j] != 0)
			{
				return true;
			}
		}
	}
	return false;

}

//Store blocks that have been placed on the stage. This function updates the collision map
void Block::UpdateCollision(Board &boardobj) {
	for (size_t i = 0; i < (BOARD_HEIGHT+1); i++)
	{
		for (size_t j = 0; j < (BOARD_WIDTH+2); j++)
		{
			boardobj.stage[i][j] = boardobj.board[i][j];
		}
	}
}

void Block::PlayerInput(Game &gameobj, Board &boardobj)
{
	char key;
	bool bRotateHold = false;

	//get the key that was pressed
	#ifdef _WIN32
	key = _getch();
	#endif

	//first checks if the block collided with anything, if it didn't, the block will move according to the key pressed
	switch (key)
	{
	case 'd': //right
		if (!Collide(boardobj, x + 1, y))
		{
			MoveBlock(gameobj, boardobj, x + 1, y);
		}
		break;
	case 'a': //left
		if (!Collide(boardobj, x - 1, y))
		{
			MoveBlock(gameobj, boardobj, x - 1, y);
		}
		break;
	case 's': //down
		if (!Collide(boardobj, x, y + 1))
		{
			MoveBlock(gameobj, boardobj, x, y + 1);
		}
		break;
	case ' ': //spacebar
		if (!Collide(boardobj, x, y) && (!bRotateHold))
		{
			RotateBlock(boardobj, gameobj);
			bRotateHold = true;
		}
		else
			bRotateHold = false;
	}

}

void Block::MoveBlock(Game &gameobj, Board &boardobj, int bx, int by)
{
	//Remove block
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			boardobj.board[y + i][x + j] -= block[i][j];
		}
	}

	//Update coordinates
	x = bx;
	y = by;

	// assign a block with the updated value
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			boardobj.board[y + i][x + j] += block[i][j];
		}
	}
	//redisplay the block in its new position 
	boardobj.DisplayBoard(gameobj);

}

bool Block::RotateBlock(Board &boardobj, Game &gameobj)
{
	//create 4x4 array to store the current block
	int tmp[4][4];

	for (size_t i = 0; i < 4; i++)
	{ //Save temporary block
		for (size_t j = 0; j < 4; j++)
		{
			tmp[i][j] = block[i][j];
		}
	}

	for (size_t i = 0; i < 4; i++)
	{ //Rotate 90 degrees
		for (size_t j = 0; j < 4; j++)
		{
			block[i][j] = tmp[3 - j][i];
		}
	}

	if (Collide(boardobj, x, y))
	{ // Revert the rotation if it would cause a collision
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				block[i][j] = tmp[i][j];
			}
		}
		return true;
	}

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			//remove the temporary block and put the new rotated block on the field
			boardobj.board[y + i][x + j] -= tmp[i][j];
			boardobj.board[y + i][x + j] += block[i][j];
		}
	}

	boardobj.DisplayBoard(gameobj);

	return false;
}