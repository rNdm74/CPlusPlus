#include "StdAfx.h"
#include "GameBoard.h"

GameBoard::GameBoard(Rectangle client, Graphics^ canvas)
	{		
		board = gcnew GameObjectList();

		board->addGameObject
		(
			gcnew GameObject
			(
				Point(230, 0),
				Size(CELL_SIZE, CELL_SIZE),
				client, 
				canvas,
				Color::WhiteSmoke
			)
		);
	}

void GameBoard::update()
	{
		board->updateGameObjects();
	}	

void GameBoard::render()
	{
		board->renderGameObjects();	
	}
