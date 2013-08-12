#pragma once
#include "shape.h"

ref class EllipseShape :
public Shape
	{
	public:
		EllipseShape(float startXPos, float startYPos, float startWidth, float startHeight, 
			Graphics^ startCanvas, float startXVel, float startYVel, 
			Color startColor);

		virtual void draw() override;
	};
