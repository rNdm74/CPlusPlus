#pragma once
#include "block.h"

ref class I :
public Block
	{
	public:
		I(int startX, Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};
