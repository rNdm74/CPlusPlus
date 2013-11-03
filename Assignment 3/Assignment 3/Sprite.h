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
	String^ fileName;
	String^ frameName;
	
	int currentFrame;
	int frameTime;
	int resetFrame;

	array<Point>^ spriteSheetState;
	array<int, 3>^ spriteSheetData;
	ArrayList^ list;

	Rectangle spriteFrame;

	Graphics^ canvas;

	Bitmap^ spriteSheet;
	PixelFormat format;

	EState spriteState;
	EAction spriteAction;
	EState selectedAbility;
	EDirection facingDirection;
	EAbility spriteAbility;

	int health;
	int mana;

	int attackTime;
	int moveDistance;
	int moveTicks;	
	int attackTicks;
	int healTicks;
	int loseTicks;


	static int nextBattleDistance = 170;
	static int healed = 50;
	static int loseTime = 10;

	int battle;	

	int right;

	int xPos;
	int yPos;

	int xVel;
	int yVel;


	int xOFFSET;	 
	int yOFFSET;

	int scale;

	bool hurt;
	bool usedAbility;

	bool alive;

	bool turnOver;
	bool attacking;
	bool roundWon;
	bool roundLose;
	bool attackIsOver;

	bool attackStarted;
	bool attackFinished;
	bool finishedAnimation;
	bool waiting;

public:
	Sprite^ Next;

public:
	Sprite(Graphics^ startCanvas, String^ startFileName, array<Point>^ startSpriteState, int startX, int startY);
	
	void Move();	
	void Update();
	virtual void Draw(int newXPos, int newYPos);

	// FSM Methods
	virtual void UpdateState(Sprite^ otherSprite);
	virtual void PerformAction(Sprite^ otherSprite);

	virtual void UpdateAbility();
	virtual void PerformAbility(Sprite^ otherSprite);
	virtual void ExecuteAbility();


	// GETS	
	int  getXPos()							{ return xPos; }
	int  getYPos()							{ return yPos; }
	int  getHealth()						{ return health; }
	int  getMana()							{ return mana; }
	int  getBattle()						{ return battle; }
	bool isWaiting()						{ return waiting; }
	bool isAttackStarted()					{ return attackStarted; }
	bool isAttackFinihed()					{ return attackFinished; }
	bool isFinishedAnimation()				{ return finishedAnimation; }
	bool isHurt()							{ return hurt; }
	bool hasUsedAbility()					{ return usedAbility; }
	bool isAlive()							{ return alive; }

	Rectangle getCollisionRectangle(int vx, int vy)	{ return Rectangle((xPos - xOFFSET) - vx, (yPos - yOFFSET)-vy, spriteFrame.Width, spriteFrame.Height); }

	// SETS
	void setXPos(int x)						{ xPos = x;}
	void setYPos(int y)						{ yPos = y;}
	void setHealth(int h)					{ health += h; }
	void setMana(int m)						{ mana += m; }
	void setCurrentFrame(int c)				{ currentFrame = c; }
	void setState(EState s)					{ spriteState = s; }
	void setSelectedAbility(EState s)		{ selectedAbility = s; }
	void setAttackStarted()					{ attacking = true; }
	void setHurt(bool h)					{ hurt = h; }
	void setAlive(bool a)					{ alive = a; }
	void setWaiting(bool w)					{ waiting = w; }
};
