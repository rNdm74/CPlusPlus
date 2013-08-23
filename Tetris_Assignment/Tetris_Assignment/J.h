#pragma once
#include "block.h"

ref class J :
public Block
	{
	public:
		J(int startX, Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};
