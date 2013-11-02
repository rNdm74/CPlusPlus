#pragma once
#include "sprite.h"

ref class Enemy :
public Sprite
{
public:
	Enemy(Graphics^ startCanvas, String^ startFileName, array<Point>^ startSpriteState, int startX, int startY);

	virtual void Draw(int newXPos, int newYPos) override;

	// FSM Methods
	virtual void UpdateState(Sprite^ otherSprite) override;
	virtual void PerformAction() override;
	virtual void ExecuteAbility(Sprite^ otherSprite) override;

	void UpdateMeleeAbility();
	void PerformMeleeAbility(Sprite^ otherSprite);
	void UpdateMagicAbility();
	void PerformMagicAbility(Sprite^ otherSprite);

	
};
