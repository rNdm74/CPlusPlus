#pragma once
#include "block.h"

ref class O :
public Block
	{
	public:
		O(array<Point>^ square, Color color, Grid^ grid);
		virtual void rotate() override;
	};
