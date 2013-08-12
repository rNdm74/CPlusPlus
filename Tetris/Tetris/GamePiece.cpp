#include "StdAfx.h"
#include "GamePiece.h"

GamePiece::GamePiece(Point startLocation, Rectangle startClient, Graphics^ startCanvas)
	{	
		location = startLocation;
		client = startClient;
		canvas = startCanvas;

		piece = gcnew GameObjectList();

		addObject(Point(location.X + CELL_SIZE, location.Y));
		addObject(location);
		addObject(Point(location.X + (CELL_SIZE * 2), location.Y));
	}

void GamePiece::addObject(Point p)
	{
		piece->addGameObject
		(
			gcnew GameObject
			(
				p,
				Size(CELL_SIZE, CELL_SIZE),
				client, 
				canvas,
				Color::White
			)
		);
	}

void GamePiece::input(KeyEventArgs^  e)
	{
		piece->inputGameObjects(e);
	}

void GamePiece::update()
	{
		piece->updateGameObjects();
	}	

void GamePiece::render()
	{
		piece->renderGameObjects();	
	}
