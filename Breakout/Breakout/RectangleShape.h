#pragma once
#include "shape.h"

ref class RectangleShape :
public Shape
	{
	public:
		RectangleShape(int startXPos, int startYPos, int startWidth, int startHeight, 
			Graphics^ startCanvas, int startXVel, int startYVel, 
			Color startColor);

		virtual void draw() override;
	};
