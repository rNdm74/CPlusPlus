#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#define SPEED 4

ref class GameObject
{
protected:
	PointF vel;
	RectangleF rect;
	Point direction;
	
	Pen^ pen;
	Brush^ brush;
	Graphics^ canvas;

	bool visible;

public:
	GameObject^ Next;

public:
	GameObject(RectangleF startRect, PointF startVel, Graphics^ startGraphics);
	virtual void update();
	virtual void render();
	virtual void shoot();
	bool collision(GameObject^ go);
	
	RectangleF getBounds() { return rect; }
	float getYPos(){ return rect.X; }

	bool isVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
};
