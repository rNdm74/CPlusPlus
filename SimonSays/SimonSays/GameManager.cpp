#include "StdAfx.h"
#include "GameManager.h"

GameManager::GameManager(Graphics^ g, Size s)
	{
		canvas = g;
		size = s;

		rectArray = gcnew array<RectangleShape^, 2>(2,2);

		for(int col = 0; col < 2; col++)
			for(int row = 0; row < 2; row++)
			rectArray[col, row] = gcnew RectangleShape
			(
				(size.Width / 2) * col,
				(size.Height / 2) * row,
				size.Width / 2,
				size.Height / 2,
				canvas				
			);				
	}

void GameManager::mouseMove(MouseEventArgs^  e)
	{
		for(int col = 0; col < 2; col++)
			for(int row = 0; row < 2; row++)
				{
					RectangleShape^ rect = rectArray[col, row];

					Point p = e->Location;

					rect->setColor((rect->getBounds().Contains(p)) ? Color::Aqua : Color::White);
				}
				
	}

void GameManager::mouseDown(MouseEventArgs^  e)
	{
		for(int col = 0; col < 2; col++)
			for(int row = 0; row < 2; row++)
				{
					RectangleShape^ rect = rectArray[col, row];

					//if(rect->getBounds().Contains(e->Location))
						
				}
				
	}

void GameManager::mouseUp(MouseEventArgs^  e)
	{
		for(int col = 0; col < 2; col++)
			for(int row = 0; row < 2; row++)
				{
					
				}
				
	}

void GameManager::update()
	{
		for(int col = 0; col < 2; col++)
			for(int row = 0; row < 2; row++)
				rectArray[col, row]->update();		
	}

void GameManager::render()
	{
		for(int col = 0; col < 2; col++)
			for(int row = 0; row < 2; row++)
			rectArray[col, row]->render();
	}
