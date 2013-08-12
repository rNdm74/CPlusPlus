#pragma once
#include "shape.h"

ref class RectangleShape :
public Shape
	{
	public:
		RectangleShape(float startXPos, float startYPos, float startWidth, float startHeight, 
			Graphics^ startCanvas, float startXVel, float startYVel, 
			Color startColor);

		virtual void draw() override;
	};
