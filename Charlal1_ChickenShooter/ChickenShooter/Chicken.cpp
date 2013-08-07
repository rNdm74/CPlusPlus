#include "StdAfx.h"
#include "Chicken.h"

Chicken::Chicken(int startX, int startY, Graphics^ g)
	{
		image = Image::FromFile("chicken.gif");

		width = image->Width;
		height = image->Height;

		direction = 0;

		xPos = startX;
		yPos = startY;

		canvas = g;

		rGen = gcnew Random();

		pellets = gcnew PelletList();

		font = gcnew Font("Microsoft Sans Serif", FONT_SIZE);		
	}

void Chicken::draw()
	{	
		// Draw pellets
		pellets->renderPellets();

		// Draw chicken
		canvas->DrawImage(image, Point(xPos,yPos));

		// Draw pellet count
		canvas->DrawString(pellets->countPellets().ToString(), font, Brushes::WhiteSmoke, FONT_X, FONT_Y);
	}

void Chicken::update()
	{
		// Move pellets
		pellets->updatePellets();

		// Move chicken
		xPos += CHICKEN_SPEED * direction;
	}

void Chicken::shoot()
	{
		// Shoot pellet
		pellets->addPellet(gcnew Pellet(getCenter(), canvas, rGen));
	}