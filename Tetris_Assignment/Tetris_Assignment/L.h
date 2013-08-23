#pragma once
#include "block.h"

ref class L :
public Block
	{
	public:
		L(int startX, Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};

