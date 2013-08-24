#pragma once
#include "block.h"

ref class J :
public Block
	{
	public:
		J(int startX, Color color, Grid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
