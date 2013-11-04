#pragma once

#include "Constants.h"

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

ref class Sprite
{
protected:
	EState spriteState;
	EAction spriteAction;
	EState selectedAbility;
	EDirection facingDirection;
	EAbility spriteAbility;

	Graphics^ canvas;
	Bitmap^ spriteSheet;
	Rectangle spriteFrame;

	ArrayList^ list;	

	String^ fileName;
	String^ potion;

	static int nextBattleDistance = 150;
	static int healTime = 50;
	static int loseTime = 20;
	static int winTime = 50;

	int currentFrame, frameTime, resetFrame;
	int health, mana;
	int healthCost, manaCost;
	int attackTime, attackTicks;
	int moveDistance, moveTicks;
	int healTicks, loseTicks, winTicks;
	int battleSelection;
	int xPos, yPos;
	int xVel, yVel;
	int xOFFSET, yOFFSET;

	bool alive, boss, hurt, usedAbility;
	bool turnOver, attacking;
	bool roundWon, roundLose;
	bool waiting, attackIsOver;
	bool attackStarted, attackFinished;
	bool finishedAnimation;

public:
	Sprite(Graphics^ startCanvas, String^ startFileName, Point startLocation, ArrayList^ startFrameList);
	
	void Move();	
	void Update();

	virtual void Draw(int newXPos, int newYPos);

	// FSM Methods
	virtual void UpdateState(Sprite^ otherSprite);
	virtual void PerformAction(Sprite^ otherSprite);

	virtual void UpdateAbility();
	virtual void PerformAbility(Sprite^ otherSprite);
	virtual void ExecuteAbility();
	
	Rectangle getCollisionRectangle(int vx, int vy);

	// GETS	
	int  getXPos()							{ return xPos; }
	int  getYPos()							{ return yPos; }
	int  getHealth()						{ return health; }
	int  getMana()							{ return mana; }
	int  getBattleSelection()				{ return battleSelection; }
	String^ getFilename()					{ return fileName; }
	bool isBoss()							{ return boss; }
	bool isWaiting()						{ return waiting; }
	bool isAttackStarted()					{ return attackStarted; }
	bool isAttackFinihed()					{ return attackFinished; }
	bool isFinishedAnimation()				{ return finishedAnimation; }
	bool isHurt()							{ return hurt; }
	bool hasUsedAbility()					{ return usedAbility; }
	bool isAlive()							{ return alive; }

	// SETS
	void setLocation(Point p)				{ xPos = p.X; yPos = p.Y; }
	void setXPos(int x)						{ xPos = x;}
	void setYPos(int y)						{ yPos = y;}
	void setHealth(int h)					{ health += h; }
	void setMana(int m)						{ mana += m; }
	void setPotion(String^ p)				{ potion = p; }
	void setCurrentFrame(int c)				{ currentFrame = c; }
	void setState(EState s)					{ spriteState = s; }
	void setSelectedAbility(EState s)		{ selectedAbility = s; }
	void setAttackStarted()					{ attacking = true; }
	void setHurt(bool h)					{ hurt = h; }
	void setBoss(bool b)					{ boss = b; }
	void setAlive(bool a)					{ alive = a; }
	void setWaiting(bool w)					{ waiting = w; }
};
