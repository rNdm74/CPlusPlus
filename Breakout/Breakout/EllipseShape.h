#pragma once
#include "shape.h"

ref class EllipseShape :
public Shape
	{
	public:
		EllipseShape(int startXPos, int startYPos, int startWidth, int startHeight, 
			Graphics^ startCanvas, int startXVel, int startYVel, 
			Color startColor);

		virtual void draw() override;
	};
