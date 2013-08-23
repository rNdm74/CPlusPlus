#pragma once
#include "block.h"

ref class L :
public Block
	{
	public:
		L(Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};

