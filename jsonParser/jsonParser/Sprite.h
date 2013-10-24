#pragma once



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
	array<Rectangle>^ frames;

	Graphics^ canvas;

	Bitmap^ spriteSheet;
	PixelFormat format;

	int xPos;
	int yPos;

	int scale;

public:
	Sprite(Graphics^ startCanvas, String^ startFileName, String^ startFrameName, int startX, int startY);
	void draw();
	void drawPlayer();
	void update(int startFrame, int endFrame);
	void updateAllFrames();

	int getXPos()				{ return xPos; }
	int getYPos()				{ return yPos; }
	

	void setXPos(int x)			{ xPos = x;}
	void setYPos(int y)			{ yPos = y;}

};
