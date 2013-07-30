#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class GameObject
{
private:

protected:
	float xPos;
	float yPos;
	float width;
	float height;

public:
	GameObject(void);
	
	float getX() {return xPos;}
	float getY() {return yPos;}
	float getWidth() {return width;}
	float getHeight() {return height;}
	float getCenterY() {return yPos + height / 2;}

	void render(Graphics^ g);
};
