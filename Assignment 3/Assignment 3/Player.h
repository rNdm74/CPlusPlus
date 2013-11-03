#pragma once
#include "sprite.h"

ref class Player :
public Sprite
{
private:
	

public:
	Player(Graphics^ startCanvas, String^ startFileName, array<Point>^ startSpriteState, int startX, int startY);

	virtual void Draw(int newXPos, int newYPos) override;

	// FSM Methods
	virtual void UpdateState(Sprite^ otherSprite) override;
	virtual void PerformAction(Sprite^ otherSprite) override;

	virtual void ExecuteAbility() override;

	virtual void UpdateAbility() override;
	virtual void PerformAbility(Sprite^ otherSprite) override;
		

	bool enemyChooseAttack()		{ return turnOver; }
	void setChooseAttack(bool t)	{ turnOver = t; }
};
