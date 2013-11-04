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
	Graphics^ canvas;

	String^ fileName;
	
	
	
	ArrayList^ list;

	Rectangle spriteFrame;

	

	Bitmap^ spriteSheet;

	EState spriteState;
	EAction spriteAction;
	EState selectedAbility;
	EDirection facingDirection;
	EAbility spriteAbility;

	String^ potion;


	int currentFrame;
	int frameTime;
	int resetFrame;	

	int health;
	int mana;

	int attackTime, attackTicks;
	int moveDistance, moveTicks;

	int healTicks;
	int loseTicks;
	int winTicks;
	


	static int nextBattleDistance = 150;
	static int healTime = 50;
	static int loseTime = 20;
	static int winTime = 20;

	int battle;	

	int xPos, yPos;
	int xVel, yVel;
	int xOFFSET, yOFFSET;

	bool boss;
	bool hurt;
	bool usedAbility;

	bool alive;

	bool turnOver;
	bool attacking;
	bool roundWon, roundLose;
	bool attackIsOver;

	bool attackStarted;
	bool attackFinished;
	bool finishedAnimation;
	bool waiting;

public:
	Sprite^ Next;

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


	// GETS	

	int  getXPos()							{ return xPos; }
	int  getYPos()							{ return yPos; }
	int  getHealth()						{ return health; }
	int  getMana()							{ return mana; }
	int  getBattle()						{ return battle; }
	String^ getFilename()					{ return fileName; }
	bool isBoss()							{ return boss; }
	bool isWaiting()						{ return waiting; }
	bool isAttackStarted()					{ return attackStarted; }
	bool isAttackFinihed()					{ return attackFinished; }
	bool isFinishedAnimation()				{ return finishedAnimation; }
	bool isHurt()							{ return hurt; }
	bool hasUsedAbility()					{ return usedAbility; }
	bool isAlive()							{ return alive; }

	Rectangle getCollisionRectangle(int vx, int vy)	{ return Rectangle((xPos - xOFFSET) - vx, (yPos - yOFFSET)-vy, spriteFrame.Width, spriteFrame.Height); }

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
