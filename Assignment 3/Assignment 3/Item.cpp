#include "StdAfx.h"
#include "Item.h"

Item::Item(Graphics^ startCanvas, PictureBox^ startItem)
{
	dbGraphics = startCanvas;
	item = startItem;
	itemImage = startItem->Image;
	location.X = 1024 - 200;
	location.Y = 700 - 310; 

	destRectangle = Rectangle(location.X, location.Y, item->Bounds.Width*0.85, item->Bounds.Height*0.85);
	srcRectangle = Rectangle(0,0, itemImage->Width, itemImage->Height);

	// Angle player flys when killed
	Random^ rGen = gcnew Random();

	radiansAngle = rGen->Next(240, 260) * 0.01745;

	// Sets angle and power
	xVel = Math::Cos(radiansAngle) * rGen->Next(20, 30);
	yVel = Math::Sin(radiansAngle) * rGen->Next(30, 40);
}

void Item::Draw()
{
	if(collected == false)
		dbGraphics->DrawImage(itemImage, destRectangle, srcRectangle, GraphicsUnit::Pixel);
}

void Item::Move()
{
	if(destRectangle.Y < 700 - 230)
	{
		destRectangle.X += xVel;
		destRectangle.Y += yVel;
		yVel += GRAVITY;
	}	

	if(destRectangle.Y > 700 - 230)
		destRectangle.Y = 700 - 230;
}
