#include "StdAfx.h"
#include "GameOver.h"

GameOver::GameOver(ResourceManager^ rm, Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush, Sound^ sound)
		 : Game(rm, dbGraphics, screenBounds, gameFont, fontBrush, sound)
{	
	// Default
}

EGameState GameOver::input(KeyEventArgs^  e)
{
	// If enter is pressed return menu state else return current state
	if(e->KeyData == Keys::Enter)
	{
		gSound->play("SFX_PieceHold");
		return MENU;
	}

	// If space is pressed the game will start
	if(e->KeyData == Keys::Space)
	{
		gSound->play("SFX_PieceHold");
		return PLAY;
	}

	// Exit application if escape is pressed
	if(e->KeyData == Keys::Escape)
	{
		Application::Exit();
	}

	return OVER;
}

void GameOver::update()
{
	// Default
}

void GameOver::render()
{	
	graphics->DrawImage(background, 0, 0);

	graphics->DrawString
	(			 
		"\t\t GAMEOVER"+
		"\n\n\n\n",	
		font, 
		brush, 
		220, 
		270
	);

	graphics->DrawString
	(
		"ENTER\t: MENU"+
		"\n\n"+
		"SPACE\t: RESTART"+
		"\n\n"+
		"Q\t: QUIT",		
		font, 
		brush, 
		100, 
		500
	);

	if(gameOver)
	{	
		gameOver = false;
	}
}


