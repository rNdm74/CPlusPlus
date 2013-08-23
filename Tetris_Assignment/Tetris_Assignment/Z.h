#pragma once
#include "block.h"

ref class Z :
public Block
	{
	public:
		Z(int startX, Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};
