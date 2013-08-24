#pragma once
#include "block.h"

ref class O :
public Block
	{
	public:
		O(int startX, Color color, Grid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
