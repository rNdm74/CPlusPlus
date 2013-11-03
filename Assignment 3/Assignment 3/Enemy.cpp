#include "StdAfx.h"
#include "Enemy.h"

Enemy::Enemy(Graphics^ startCanvas, String^ startFileName, array<Point>^ startSpriteState, int startX, int startY)
	  :Sprite(startCanvas, startFileName, startSpriteState, startX, startY)
{
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
	 Bitmap^ spriteBitmap = spriteSheet->Clone(spriteFrame, format);
	 
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

void Enemy::DrawHud(int newXPos, int newYPos)
{	 
	 //
	 // Draw sprites frame to the screen
	 //	 
	 Bitmap^ spriteBitmap = spriteSheet->Clone(spriteFrame, format);
	 
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
	 canvas->DrawImage(spriteBitmap, newXPos + (xOFFSET / 2) - xOFFSET, newYPos + (yOFFSET / 2) - yOFFSET, xOFFSET / 2.5, yOFFSET / 2.5);
	 
	 delete spriteBitmap;
}

void Enemy::UpdateState(Sprite^ otherSprite)
	{		
		switch(spriteAction)
		{
			case WAITING:
				if(attacking)
				{
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
					otherSprite->setWaiting(true);
				}
				break;
			case USE_ABILITY:
				if(waiting)
				{
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
				spriteState = HURT;
				facingDirection = RIGHT;
								
				xPos += xVel;
				yPos += yVel;

				yVel += 2;

				loseTicks++;
				break;
			case USE_ABILITY:	
				ExecuteAbility();
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
				otherSprite->setState(HURT);
				otherSprite->setHurt(true);
				otherSprite->setHealth(10 * safe_cast<int>(selectedAbility));
			}		

			attackTicks++;

			attackFinished = finishedAnimation;			
			break;
		case WALK_BACKWARD:	
			otherSprite->setHurt(false);
			otherSprite->setState(IDLE);
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

void Enemy::ExecuteAbility()
{
	switch(selectedAbility)
	{
		case IDLE:
			break;
		case HURT:
			break;
		case BOSS_HURT:
			moveDistance = 70;
			break;
		case LESSER_ICE:
			moveDistance = 70;			
			break;
		case GREATER_ICE:
			break;
		case WALK:
			break;
		case LESSER_WAND:
			break;
		case DODGE:
			break;
		case ELECTRIC_STORM:
			break;
		case GREATER_WAND:
			break;
		case WHIRLWIND:
			break;
		case HEAL:
			break;
	}	
}