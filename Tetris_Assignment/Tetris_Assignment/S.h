#pragma once
#include "block.h"

ref class S :
public Block
	{
	public:
		S(Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};
