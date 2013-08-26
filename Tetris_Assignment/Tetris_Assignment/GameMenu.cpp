#include "StdAfx.h"
#include "GameMenu.h"

GameMenu::GameMenu(Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush, Sound^ sound)
		 : Game(dbGraphics, screenBounds, gameFont, fontBrush, sound)
{	
	
	logo = Image::FromFile("logo.png");
	
	gSound->play("SFX_SpecialTetris.wav");

	label = "Press Enter To Start";

	xPos = background->Width / 2 - logo->Width / 2;
	yPos = background->Height / 2 - logo->Height / 2;

	vel = 1;
}

EGameState GameMenu::input(KeyEventArgs^  e)
{	
	if(e->KeyData == Keys::Enter)
	{
		gSound->play("SFX_PieceHold.wav");
		return PLAY;
	}

	return MENU;
}

void GameMenu::update()
{
	if(vel > 5) vel *= DIRECTION;
	if(vel < -5) vel *= -DIRECTION;

	vel += 0.15;

	yPos += 0.1 * vel;
}

void GameMenu::render()
{
	graphics->DrawImage(background, 0, 0);
	graphics->DrawImage(logo, xPos, yPos);
	graphics->DrawString(label, font, brush, 300, 600);
}


