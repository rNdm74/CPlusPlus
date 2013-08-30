#include "StdAfx.h"
#include "GameMenu.h"

GameMenu::GameMenu(ResourceManager^ rm, Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush, Sound^ sound)
		 : Game(rm, dbGraphics, screenBounds, gameFont, fontBrush, sound)
{	
	// Loads image from file
	logo = (Image^)rManager->GetObject("logo");//Image::FromFile("logo.png");
	
	// Plays intro sound
	gSound->play("SFX_SpecialTetris");

	// Text label to start game
	label = "New Game Press Enter";

	// Sets logos position on screen
	xPos = background->Width / 2 - logo->Width / 2;
	yPos = background->Height / 8 ;//- logo->Height / 2;

	// Sets logo movement velocity
	vel = 1;
}

EGameState GameMenu::input(KeyEventArgs^  e)
{	
	// If enter is pressed return play state else return current state
	if(e->KeyData == Keys::Enter)
	{
		gSound->play("SFX_PieceHold");
		return PLAY;
	}

	if(e->KeyData == Keys::Escape)
	{
		return PLAY;
	}

	// Exit application if escape is pressed
	if(e->KeyData == Keys::Q)
	{
		Application::Exit();
	}

	return MENU;
}

void GameMenu::update()
{
	// Change vel direction
	if(vel > 5) vel *= DIRECTION;
	if(vel < -5) vel *= -DIRECTION;

	// Increase vel
	vel += 0.15;

	// Change yPos by vel
	yPos += 0.1 * vel;
}

void GameMenu::render()
{
	// Draw to screen
	graphics->DrawImage(background, 0, 0);
	graphics->DrawImage(logo, xPos, yPos);
	graphics->DrawString
	(
		"ENTER\t: PLAY"+
		"\n\n"+
		"ESCAPE\t: RESUME"+
		"\n\n"+
		"Q\t\t: QUIT", 
		font, 
		brush, 
		100, 
		500
	);
}


