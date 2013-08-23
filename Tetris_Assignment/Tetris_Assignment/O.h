#pragma once
#include "block.h"

ref class O :
public Block
	{
	public:
		O(int startX, Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};
