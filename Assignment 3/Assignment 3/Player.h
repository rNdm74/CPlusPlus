#pragma once
#include "Sprite.h"

ref class Player :
public Sprite
{
private:
	double radiansAngle;
	bool generatedWeapon;
	bool nextBattle;
	bool gameover;
	int battleScreen;
	array<int>^ battleStartPoints;

	bool poison;
	bool powerup;

	
	
	
public:
	Player(Graphics^ startCanvas, String^ startFileName, Point startLocation, ArrayList^ startFrameList);

	virtual void Draw(int newXPos, int newYPos) override;

	// FSM Methods
	virtual void UpdateState(Sprite^ otherSprite) override;
	virtual void PerformAction(Sprite^ otherSprite) override;

	virtual void ExecuteAbility() override;

	virtual void UpdateAbility() override;
	virtual void PerformAbility(Sprite^ otherSprite) override;
	
	bool isPoisonUsed()				{ return poison; }
	void setPoison(bool p)			{ poison = p; }
	bool isPowerupUsed()			{ return powerup; }
	void setPowerup(bool p)			{ powerup = p; }

	bool isGeneratedWeapon()		{ return generatedWeapon; }
	void setGeneratedWeapon(bool w)	{ generatedWeapon = w; }

	int getBattleScreen()			{ return battleScreen; }
	bool isGameOver()				{ return gameover; } 
	bool enemyChooseAttack()		{ return turnOver; }
	void setChooseAttack(bool t)	{ turnOver = t; }
};
