#include "StdAfx.h"
#include "Pellet.h"

Pellet::Pellet()
	{		
	}

Pellet::Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen)
	{
		xPos = startXPos;
		yPos = startYPos;

		yVel = 1;

		diameter = PELLET_DIAMETER;
		canvas = startCanvas;

		rGen = startRGen;

		int r = rGen->Next(255);
		int g = rGen->Next(255);
		int b = rGen->Next(255);

		pelletColour = Color::FromArgb(r, g, b);
	
		brush = gcnew SolidBrush(pelletColour);
	}

void Pellet::draw()
	{
		canvas->FillEllipse(brush, xPos, yPos, PELLET_DIAMETER, PELLET_DIAMETER);
	}

void Pellet::update()
	{
		yPos -= yVel * PELLET_SPEED;
	}
