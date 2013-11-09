#include "StdAfx.h"
#include "Item.h"

Item::Item(Graphics^ startCanvas, PictureBox^ startItem)
{
	dbGraphics = startCanvas;
	item = startItem;
	itemImage = startItem->Image;
	location.X = 100;
	location.Y = 568 - itemImage->Height; 
}

void Item::Draw()
{
	dbGraphics->DrawImage(itemImage, location);
}
