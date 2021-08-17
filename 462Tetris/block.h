#pragma once
#include "board.h"
#include "game.h"

class Block
{
public:
	//creates a new block
	bool CreateBlock(Board &obj, Game &obj2);

	//Checks for collison, calls CreateBlock after a previous block has been placed
	void SpawnBlock(Board &obj, Game &obj2);

	bool Collide(Board &obj, int, int);
	void UpdateCollision(Board &obj);
	void PlayerInput(Game &obj2, Board &obj);
	void MoveBlock(Game &obj2, Board &obj, int, int);
	bool RotateBlock(Board &obj, Game &obj2);

	// The starting position coordinates for the blocks
	int x = 4;
	int y = 0;

	// Keep track of block type from the block_list
	int bType = 0;


	//Block definition is a 4x4 matrix
	int block[4][4] =
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	// Multidimensional array holding all the 7 blocks 
	int block_list[7][4][4]=
	{
		{	//Block 0
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 }
		},
		{	//Block 1
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 }
		},
		{	//Block 2
			{ 0, 0, 1, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{	//Block 3
			{ 0, 1, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{	//Block 4
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 1, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{	//Block 5
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{	//Block 6
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 }
		}
	};

};


