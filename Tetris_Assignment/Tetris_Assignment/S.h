#pragma once
#include "block.h"

ref class S :
public Block
	{
	public:
		S(int startX, Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};
