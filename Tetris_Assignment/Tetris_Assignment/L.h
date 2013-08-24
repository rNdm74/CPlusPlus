#pragma once
#include "block.h"

ref class L :
public Block
	{
	public:
		L(int startX, Color color, Grid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};

