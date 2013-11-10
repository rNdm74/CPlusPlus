#pragma once

using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

ref class Item
{
private:
	PictureBox^ item;

	Image^ itemImage;
	
	Graphics^ dbGraphics;

	Point location;
	double radiansAngle;
	double xVel;
	double yVel;

	Rectangle destRectangle;
	Rectangle srcRectangle;

	bool collected;

public:
	Item(Graphics^ startCanvas, PictureBox^ startItem);
	void Draw();
	void Move();

	void showInventoryItem()	{ item->Visible = true; }
	String^ getName()			{ return item->Name; } 
	bool isOffScreen()			{ return destRectangle.X < 0 || destRectangle.Y > 768; }
	Point getLocation() { return Point(destRectangle.X, destRectangle.Y); }
	int getWidth()				{ return item->Bounds.Width; }
	bool canPickup(int x, int y){ return (x > location.X && x < location.X + item->Bounds.Width); }
	bool isCollected()			{ return collected; }
	void setCollected(bool c)	{ collected = c; }
};
