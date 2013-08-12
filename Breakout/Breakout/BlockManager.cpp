#include "StdAfx.h"
#include "BlockManager.h"

#define BLOCK_WIDTH 60
#define BLOCK_HEIGHT 25

BlockManager::BlockManager(Graphics^ g, Size s)
	{
		columns = (s.Width / BLOCK_WIDTH);
		rows = 4;

		blocks = gcnew array<Shape^,2>(columns,rows);
		
		for(int x = 0; x < columns; x++)
			for(int y = 0; y < rows; y++)
				blocks[x, y] = gcnew RectangleShape
				(
					12 + BLOCK_WIDTH * x,			// xPos
					BLOCK_HEIGHT * y,				// yPos				
					BLOCK_WIDTH,					// width
					BLOCK_HEIGHT,					// height
					g,								// graphics
					0,								// xVel
					0,								// yVel
					Color::Green					// color
				);
	}

void BlockManager::input()
	{
	}

void BlockManager::update()
	{
	}

void BlockManager::render()
	{
		for(int x = 0; x < columns; x++)
			for(int y = 0; y < rows; y++)
				blocks[x, y]->draw();
	}
