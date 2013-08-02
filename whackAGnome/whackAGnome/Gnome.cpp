#include "StdAfx.h"
#include "Gnome.h"

Gnome::Gnome(Graphics^ g, Point p)
	{
		canvas = g;
		location = p;
		hamster = false;
		image = Image::FromFile("gnome.jpg");
	}
void Gnome::draw()
	{
		canvas->DrawImage(image, location.X, location.Y, image->Width, image->Height);		
	}
void Gnome::erase()
	{
	}
void Gnome::changeImage()
	{
		image = Image::FromFile("hamster.jpg");
	}
void Gnome::isHit(Point p)
	{	
		if(Rectangle(location, image->Size).Contains(p)){			
			setHit(true);
			changeImage();
		}
	}
void Gnome::isAHamster()
	{
	}
