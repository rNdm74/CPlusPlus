#pragma once
#include "block.h"

ref class S :
public Block
	{
	public:
		S(int startX, Color color, Grid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
