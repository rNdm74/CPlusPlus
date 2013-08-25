#include "StdAfx.h"
#include "GameMenu.h"

GameMenu::GameMenu(Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush)
		 : Game(dbGraphics, screenBounds, gameFont, fontBrush)
{
	graphics = dbGraphics;
	background = Image::FromFile("background5.jpg");
	logo = Image::FromFile("logo.png");
	font = gameFont;
	brush = fontBrush;
	gcnew PlaySound("SFX_SpecialTetris.wav");
	label = "Press Enter To Start";
}

EGameState GameMenu::input(KeyEventArgs^  e)
{
	gcnew PlaySound("SFX_PieceHold.wav");

	return PLAY;
}

void GameMenu::update()
{
}

void GameMenu::render()
{
	graphics->DrawImage(background, 0, 0);
	graphics->DrawImage(logo, background->Width / 2 - logo->Width / 2, background->Height / 2 - logo->Height / 2);
	graphics->DrawString(label, font, brush, 512, 600);
}


