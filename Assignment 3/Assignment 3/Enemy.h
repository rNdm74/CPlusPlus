#pragma once
#include "sprite.h"

ref class Enemy :
public Sprite
{
public:
	Enemy(Graphics^ startCanvas, String^ startFileName, array<Point>^ startSpriteState, int startX, int startY);

	virtual void Draw(int newXPos, int newYPos) override;
	void DrawHud(int newXPos, int newYPos);

	// FSM Methods
	virtual void UpdateState(Sprite^ otherSprite) override;
	virtual void PerformAction(Sprite^ otherSprite) override;
	virtual void ExecuteAbility() override;

	virtual void UpdateAbility() override;
	virtual void PerformAbility(Sprite^ otherSprite) override;

	
};
