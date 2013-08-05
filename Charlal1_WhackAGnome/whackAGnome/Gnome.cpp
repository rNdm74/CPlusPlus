#include "StdAfx.h"
#include "Gnome.h"

Gnome::Gnome(Graphics^ g, Point p)
	{
		canvas = g;
		location = p;
		image = Image::FromFile("gnome.jpg");
	}

void Gnome::draw()
	{
		// Draw
		canvas->DrawImage(image, location.X, location.Y, image->Width, image->Height);		
	}

void Gnome::changeImage()
	{
		// Load hamster image
		image = Image::FromFile("hamster.jpg");
	}

void Gnome::isHit(Point p)
	{	
		// Check if Rectangle contains point
		if(Rectangle(location, image->Size).Contains(p)){
			changeImage();
			setHit(true);
		}
	}
