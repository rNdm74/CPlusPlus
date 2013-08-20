#pragma once
#include "block.h"

ref class L :
public Block
	{
	private:
		

	public:
		L(array<Point>^ square, Color color, Grid^ grid);
		virtual void rotate() override;
	};

