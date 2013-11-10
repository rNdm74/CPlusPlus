#include "StdAfx.h"
#include "Enemy.h"

Enemy::Enemy(Graphics^ startCanvas, String^ startFileName, Point startLocation, ArrayList^ startFrameList)
	  :Sprite(startCanvas, startFileName, startLocation, startFrameList)
{
	rGen = gcnew Random();

	radiansAngle = 300 * 0.01745;			// Reverses creature

	xVel = Math::Cos(radiansAngle) * 20;
	yVel = Math::Sin(radiansAngle) * 30;

	facingDirection = LEFT;

	waiting = true;
}

void Enemy::Draw(int newXPos, int newYPos)
{	 
	 //
	 // Draw sprites frame to the screen
	 //	 
	 Bitmap^ spriteBitmap = spriteSheet->Clone(spriteFrame, PixelFormat::Format32bppArgb);
	 
	 //
	 // Flips image on the X axis based on direction
	 //
	 if(facingDirection == RIGHT) spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);	
	 
	 //
	 // Get frame offsets
	 //
	 xOFFSET = spriteFrame.Width;	 
	 yOFFSET = spriteFrame.Height;
	 
	 //
	 // Draws bitmap to the screen
	 //
	 canvas->DrawImage(spriteBitmap, newXPos - xOFFSET, newYPos - yOFFSET);	
	 
	 delete spriteBitmap;
}



void Enemy::UpdateState(Sprite^ otherSprite)
	{		
		switch(spriteAction)
		{
			case WAITING:
				if(attacking)
				{
					turn = true;
					spriteAbility = START_ABILITY;
					spriteAction = USE_ABILITY;
				}
				else if(health >= 131)
				{
					spriteAction = LOSE;
				}				
				break;

			case WIN:
				break;

			case LOSE:
				if(loseTicks > loseTime)
				{
					alive = false;
					loseTicks = 0;
					spriteAction = WAITING;
				}
				break;

			case USE_ABILITY:
				if(waiting)
				{
					turn = false;
					spriteAction = WAITING;
				}				
				break;		
		}		
	}

void Enemy::PerformAction(Sprite^ otherSprite)
	{
		switch(spriteAction)
		{
			case WAITING:
				break;

			case WIN:
				break;

			case LOSE:
				usedAbility	= false;
				spriteState = HURT;
				facingDirection = RIGHT;								
				xPos += xVel;
				yPos += yVel;
				yVel += GRAVITY;
				loseTicks++;
				break;
			case USE_ABILITY:	
				ExecuteAbility(otherSprite);
				UpdateAbility();
				PerformAbility(otherSprite);
				break;		
		}		
	}

void Enemy::UpdateAbility()
{
	switch(spriteAbility)
	{
		case START_ABILITY:
			if(attacking)
			{
				spriteAbility = WALK_FORWARD;
			}
			break;
		case WALK_FORWARD:
			if(moveTicks > moveDistance)
			{
				spriteAbility = ATTACK;
			}
			break;
		case ATTACK:
			if(attackFinished)
			{
				spriteAbility = WALK_BACKWARD;				
			}			
			break;
		case WALK_BACKWARD:
			if(moveTicks > moveDistance)
			{
				spriteAbility = FINISHED;
			}
			break;	
	}
}

void Enemy::PerformAbility(Sprite^ otherSprite)
{
	switch(spriteAbility)
	{
		case START_ABILITY:			
			break;
		case WALK_FORWARD:
			waiting = false;
			facingDirection = LEFT;
			Move();
			moveTicks++;
			break;
		case ATTACK:			
			moveTicks = 0;
			
			spriteState = selectedAbility;

			if(attackTicks > attackTime && otherSprite->isHurt() == false)
			{
				usedAbility = true;
				hit = true;
				otherSprite->setState(HURT);
				otherSprite->setHurt(true);
				otherSprite->setHealth(healthCost);
			}	
			else
			{
				hit = false;
			}

			attackTicks++;

			attackFinished = finishedAnimation;			
			break;
		case WALK_BACKWARD:	
			otherSprite->setHurt(false);
			otherSprite->setState(IDLE);
			usedAbility	= false;
			attackTicks = 0;
			spriteState = IDLE;
			facingDirection = RIGHT;
			Move();
			moveTicks++;
			break;
		case FINISHED:
			otherSprite->setWaiting(false);
			moveTicks = 0;
			spriteState = IDLE;
			facingDirection = LEFT;
			spriteAction = WAITING;
			waiting = true;
			attacking = false;
			break;
	}
}

void Enemy::ExecuteAbility(Sprite^ otherSprite)
{
	int damageOffset = rGen->Next(10);

	if(fileName == "floppit" || fileName == "fluppit")
	{
		switch(selectedAbility)
		{
			case BOSS_HURT:					// Desecrate
				attackTime = 8;
				moveDistance = 70;
				healthCost = 1;
				break;
			case LESSER_ICE:				// Tentishock
				attackTime = 8;
				moveDistance = 70;	
				healthCost = 2;
				break;
			case GREATER_ICE:				// Oil Spill
				attackTime = 8;
				moveDistance = 70;
				healthCost = 3;
				break;		
		}
	}
	else
	{
		switch(selectedAbility)
		{
			case BOSS_HURT:					// Desecrate
				attackTime = 10;
				moveDistance = 0;
				healthCost = 1;
				break;
			case LESSER_ICE:				// Tentishock
				attackTime = 10;
				moveDistance = 0;
				healthCost = 2;
				break;
			case GREATER_ICE:				// Oil Spill
				attackTime = 10;
				moveDistance = 0;
				healthCost = 3;
				break;		
		}
	}

	// Increases difficulty as the game progresses
	healthCost *= damageOffset + otherSprite->getBattleSelection();
}