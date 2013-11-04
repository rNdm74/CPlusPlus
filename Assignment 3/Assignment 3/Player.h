#pragma once
#include "Sprite.h"

ref class Player :
public Sprite
{
private:
	double radiansAngle;
	bool nextBattle;
	bool gameover;
	int battleScreen;
	array<int>^ battleStartPoints;
	
	
public:
	Player(Graphics^ startCanvas, String^ startFileName, Point startLocation, ArrayList^ startFrameList);

	virtual void Draw(int newXPos, int newYPos) override;

	// FSM Methods
	virtual void UpdateState(Sprite^ otherSprite) override;
	virtual void PerformAction(Sprite^ otherSprite) override;

	virtual void ExecuteAbility() override;

	virtual void UpdateAbility() override;
	virtual void PerformAbility(Sprite^ otherSprite) override;
		

	bool isGameOver()				{ return gameover; } 
	bool enemyChooseAttack()		{ return turnOver; }
	void setChooseAttack(bool t)	{ turnOver = t; }
};
