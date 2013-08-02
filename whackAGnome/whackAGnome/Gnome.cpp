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
	}
void Gnome::isHit()
	{
	}
void Gnome::isAHamster()
	{
	}
