#include "StdAfx.h"
#include "Game.h"

Game::Game(Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush)
{
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


