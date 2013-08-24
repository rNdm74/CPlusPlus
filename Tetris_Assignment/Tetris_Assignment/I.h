#pragma once
#include "block.h"

ref class I :
public Block
	{
	public:
		I(int startX, Color color, Grid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
