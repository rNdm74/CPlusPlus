#include "StdAfx.h"
#include "Game.h"

Game::Game(Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush, Sound^ sound)
{
	graphics = dbGraphics;
	font = gameFont;
	brush = fontBrush;
	gSound = sound;
	background = Image::FromFile("background5.jpg");
}

EGameState Game::input(KeyEventArgs^  e)
{
	return MENU;
}

void Game::update()
{
}

void Game::render()
{
}


