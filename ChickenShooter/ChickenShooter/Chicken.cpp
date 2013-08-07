#include "StdAfx.h"
#include "Chicken.h"

Chicken::Chicken(int startX, int startY, Graphics^ g)
	{
		speed = 1;
		direction = 0;

		xPos = startX;
		yPos = startY;

		image = Image::FromFile("chicken.gif");

		canvas = g;

		rGen = gcnew Random();

		pellets = gcnew PelletList();

		font = gcnew Font("Microsoft Sans Serif",16);
		
	}

void Chicken::draw()
	{	
		pellets->renderPellets();

		canvas->DrawImage(image, Point(xPos,yPos));

		canvas->DrawString(pellets->countPellets().ToString(), font, Brushes::WhiteSmoke, 20, 20);
	}

void Chicken::update()
	{
		pellets->updatePellets();

		xPos += speed * direction;
	}

void Chicken::shoot()
	{
		Pellet^ p = gcnew Pellet(xPos, yPos, canvas, rGen);
		pellets->addPellet(p);
	}