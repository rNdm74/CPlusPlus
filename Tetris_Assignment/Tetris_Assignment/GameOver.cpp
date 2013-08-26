#include "StdAfx.h"
#include "GameOver.h"

GameOver::GameOver(Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush, Sound^ sound)
		 : Game(dbGraphics, screenBounds, gameFont, fontBrush, sound)
{
	
	
	
}

EGameState GameOver::input(KeyEventArgs^  e)
{
	return MENU;
}

void GameOver::update()
{
}

void GameOver::render()
{
	graphics->DrawImage(background, 0, 0);

	graphics->FillRectangle(gcnew SolidBrush(Color::FromArgb(99, Color::Black)), Rectangle(0, 0, 1024, 768));

	graphics->DrawString
	(			 
		"GAMEOVER",		
		font, 
		brush, 
		420, 
		270
	);

	if(gameOver)
	{	
		gameOver = false;
	}
}


