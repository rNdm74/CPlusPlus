#include "StdAfx.h"
#include "GameBoard.h"

GameBoard::GameBoard(Point startLocation, Rectangle startClient, Graphics^ startCanvas)
	{	
		location = startLocation;
		client = startClient;
		canvas = startCanvas;

		board = gcnew GameObjectList();

		addObject();
	}

void GameBoard::addObject()
	{
		board->addGameObject
		(
			gcnew GameObject
			(
				location,
				Size(CELL_SIZE, CELL_SIZE),
				client, 
				canvas,
				Color::WhiteSmoke
			)
		);
	}

void GameBoard::input(KeyEventArgs^  e)
	{
		board->inputGameObjects(e);
	}

void GameBoard::update()
	{
		board->updateGameObjects();
	}	

void GameBoard::render()
	{
		board->renderGameObjects();	
	}
