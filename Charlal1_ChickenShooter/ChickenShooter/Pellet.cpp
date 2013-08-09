#include "StdAfx.h"
#include "Pellet.h"

Pellet::Pellet(Point startP, Graphics^ startCanvas, Random^ startRGen)
	{
		xPos = startP.X;
		yPos = startP.Y;

		init(startCanvas, startRGen);
	}

Pellet::Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen)
	{
		xPos = (float)startXPos;
		yPos = (float)startYPos;

		init(startCanvas, startRGen);
	}

void Pellet::init(Graphics^ startCanvas, Random^ startRGen)
	{
		// Set pellet diameter
		diameter = PELLET_DIAMETER;
	
		// Set graphics canvas
		canvas = startCanvas;

		// Set random
		rGen = startRGen;

		// Set pellet velocity
		yVel = rGen->NextDouble() + PELLET_MIN_VELOCITY;

		// Set color array
		colors = gcnew array<Color> { Color::Red, Color::Blue, Color::Green, Color::Yellow };

		// Set color
		pelletColour = colors[rGen->Next(colors->Length)];
	
		// Create brush
		brush = gcnew SolidBrush(pelletColour);
	}

void Pellet::draw()
	{
		// Draw pellet
		canvas->FillEllipse(brush, (int)xPos, (int)yPos, PELLET_DIAMETER, PELLET_DIAMETER);
	}

void Pellet::update()
	{
		// Add pellet gravity
		yVel -= GRAVITY;

		// Move pellet
		yPos -= yVel * PELLET_SPEED;
	}
