#pragma once
#include "block.h"

ref class T :
public Block
	{
	public:
		T(int startX, Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};
