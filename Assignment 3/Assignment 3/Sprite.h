#pragma once

#include "Constants.h"

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

ref class Sprite
{
private:
	String^ fileName;
	String^ frameName;
	
	int currentFrame;
	int frameTime;
	int resetFrame;

	array<Point>^ spriteState;
	array<int, 3>^ spriteSheetData;
	ArrayList^ list;

	Rectangle spriteFrame;

	Graphics^ canvas;

	Bitmap^ spriteSheet;
	PixelFormat format;

	EPlayerAction state;

	int right;

	int xPos;
	int yPos;

	int xOFFSET;	 
	int yOFFSET;

	int scale;

	bool attack;

	bool finishedAction;

public:
	Sprite^ Next;

public:
	Sprite(Graphics^ startCanvas, String^ startFileName, array<Point>^ startSpriteState, int startX, int startY);
	
	void move(int direction);	
	void update();
	void draw(int newXPos, int newYPos);
	
	int getXPos()						{ return xPos; }
	int getYPos()						{ return yPos; }
	
	Rectangle getCollisionRectangle(int vx, int vy)	{ return Rectangle((xPos - xOFFSET) - vx, (yPos - yOFFSET)-vy, spriteFrame.Width, spriteFrame.Height); }

	bool isFinishedAction()				{ return finishedAction; }
	bool isAttacking()					{ return attack; }

	void setAttacking(bool a)			{ attack = a; }
	
	void setXPos(int x)					{ xPos = x;}
	void setYPos(int y)					{ yPos = y;}

	void setCurrentFrame(int c)			{ currentFrame = c; }
	void setState(EPlayerAction s)		{ state = s; }

	void setCanvas(Graphics^ c)			{ canvas = c; }

};
