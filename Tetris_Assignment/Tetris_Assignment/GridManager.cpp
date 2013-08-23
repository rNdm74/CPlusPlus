#include "StdAfx.h"
#include "GridManager.h"

GridManager::GridManager(Graphics^ dbGraphics)
{
	rGen = gcnew Random();

	grid = gcnew Grid(Point(30,60), dbGraphics);

	blocks = gcnew array<Block^>(100);

	for(int b = 0; b < blocks->Length; b++)
		blocks[b] = getGameBlock();
		
	blockInPlay = 0;
}

void GridManager::moveLeft()
{
	blocks[blockInPlay]->moveLeft();
}

void GridManager::moveRight()
{
	blocks[blockInPlay]->moveRight();
}

void GridManager::moveDown()
{
	blocks[blockInPlay]->moveDown();
}

void GridManager::moveRotate()
{
	blocks[blockInPlay]->moveRotate();	
}



void GridManager::update()
{
	if(blocks[blockInPlay]->isPlaced())
		blockInPlay++;

	if(time > 150)
	{
		blocks[blockInPlay]->moveDown();

		time = 0;
	}

	time++;	
}

void GridManager::render()
{
	grid->draw();
	blocks[blockInPlay]->draw();
}

Block^ GridManager::getGameBlock()
{
	int startX = 5;
	switch(rGen->Next(7))
	{
		case 0:
			return gcnew I(startX, Color::Green, grid);
		case 1:
			return gcnew J(startX, Color::Green, grid);
		case 2:
			return gcnew L(startX, Color::Green, grid);
		case 3:
			return gcnew O(startX, Color::Green, grid);
		case 4:
			return gcnew S(startX, Color::Green, grid);
		case 5:
			return gcnew T(startX, Color::Green, grid);
		case 6:
			return gcnew Z(startX, Color::Green, grid);
		default:
			return nullptr;
	}
}