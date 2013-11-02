#pragma once
#include "sprite.h"

ref class Player :
public Sprite
{
private:
	bool enemyTurn;
public:
	Player(Graphics^ startCanvas, String^ startFileName, array<Point>^ startSpriteState, int startX, int startY);

	virtual void Draw(int newXPos, int newYPos) override;

	// FSM Methods
	virtual void UpdateState(Sprite^ otherSprite) override;
	virtual void PerformAction() override;

	virtual void ExecuteAbility(Sprite^ otherSprite) override;

	virtual void UpdateAbility() override;
	virtual void PerformAbility(Sprite^ otherSprite) override;
		

	bool enemyChooseAttack()	{ return enemyTurn; }
	void setChooseAttack(bool b){ enemyTurn = b; }
};
