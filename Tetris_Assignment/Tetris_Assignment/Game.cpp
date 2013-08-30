#include "StdAfx.h"
#include "Game.h"

Game::Game(ResourceManager^ rm, Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush, Sound^ sound)
{
	graphics = dbGraphics;
	font = gameFont;
	brush = fontBrush;
	gSound = sound;
	rManager = rm;
	//background = Image::FromStream(assembly->GetManifestResourceStream("background.png"));
    background = (Image^)rManager->GetObject("background");//Image::FromFile("background.jpg");
}

EGameState Game::input(KeyEventArgs^  e)
{	
	return MENU;
}

void Game::update()
{
	// Overridden
}

void Game::render()
{
	// Overridden
}


