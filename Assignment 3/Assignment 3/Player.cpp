#include "StdAfx.h"
#include "Player.h"

Player::Player(Graphics^ startCanvas, String^ startFileName, array<Point>^ startSpriteState, int startX, int startY)
	   :Sprite(startCanvas, startFileName, startSpriteState, startX, startY)
{
	facingDirection = RIGHT;	
}

void Player::Draw(int newXPos, int newYPos)
{	 
	 //
	 // Draw sprites frame to the screen
	 //	 
	 Bitmap^ spriteBitmap = spriteSheet->Clone(spriteFrame, format);
	 	 
	 //
	 // Flips image on the X axis based on direction
	 //
	 if(facingDirection == LEFT) spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);
	 
	 //
	 //
	 //
	 xOFFSET = 0;	 
	 yOFFSET = spriteFrame.Height;

	 //
	 // Draws bitmap to the screen
	 //
	 canvas->DrawImage(spriteBitmap, newXPos - xOFFSET, newYPos - yOFFSET);
	 
	 delete spriteBitmap;
}

void Player::UpdateState(Sprite^ otherSprite)
	{
		switch(spriteAction)
		{
			case WAITING:
				if(attacking && otherSprite->isAlive())
				{
					spriteAbility = START_ABILITY;
					spriteAction = USE_ABILITY;
				}
				else if(otherSprite->isAlive() == false)
				{
					spriteAction = WIN;
				}
				break;
			case WIN:
				if(moveTicks > nextBattleDistance)
				{
					nextBattle = false;
					health = 0;
					selectedAbility = IDLE;
					spriteState = IDLE;					
					spriteAction = WAITING;					
				}
				break;
			case LOSE:
				break;
			case USE_ABILITY:
				if(waiting)
				{
					spriteAction = WAITING;
				}	
				else if(otherSprite->isAlive() == false)
				{
					spriteAction = WIN;
				}
				break;		
		}		
	}

void Player::PerformAction(Sprite^ otherSprite)
	{
		switch(spriteAction)
		{
			case WAITING:				
				moveTicks = 0;
				turnOver = false;
				break;

			case WIN:
				spriteState = WALK;

				Move();

				if(xPos > 1025 * (battle + 1) && nextBattle == false)
				{
					nextBattle = true;
					battle++;
				}

				if(xPos > 250 + (1024 * (battle + 1)))
				{
					xPos = 250 + (1024 * (battle + 1));					
				}

				moveTicks++;
				break;

			case LOSE:				
				break;

			case USE_ABILITY:					
				ExecuteAbility();
				UpdateAbility();

				PerformAbility(otherSprite);
				break;			
		}		
	}

void Player::UpdateAbility()
{
	switch(spriteAbility)
	{
		case START_ABILITY:
			if(selectedAbility == HEAL)
			{
				spriteAbility = HEALTH_POTION;
			}
			else
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

		case HEALTH_POTION:
			if(healTicks > healed)
			{				
				spriteAbility = FINISHED;				
			}
			break;
	}
}

void Player::PerformAbility(Sprite^ otherSprite)
{
	switch(spriteAbility)
	{		
		case WALK_FORWARD:
			waiting = false;
			spriteState = WALK;
			facingDirection = RIGHT;
			Move();
			moveTicks++;
			break;

		case ATTACK:			
			moveTicks = 0;
			
			spriteState = selectedAbility;

			if(attackTicks > attackTime && usedAbility == false)
			{
				usedAbility = true;

				setMana(5 * safe_cast<int>(selectedAbility));

				otherSprite->setState(HURT);
				otherSprite->setHurt(true);
				otherSprite->setHealth(5 * safe_cast<int>(selectedAbility));
			}	

			attackTicks++;

			attackFinished = finishedAnimation;
			break;

		case WALK_BACKWARD:	
			otherSprite->setHurt(false);
			otherSprite->setState(IDLE);

			usedAbility			= false;			
			
			attackTicks			= 0;

			spriteState			= WALK;
			facingDirection		= LEFT;

			Move();

			moveTicks++;
			break;

		case FINISHED:
			otherSprite->setWaiting(false);

			moveTicks			= 0;
			healTicks			= 0;

			spriteState			= IDLE;
			selectedAbility		= IDLE;
			facingDirection		= RIGHT;
			spriteAction		= WAITING;	

			attacking			= false;
			waiting				= true;
			turnOver			= true;
			break;

		case HEALTH_POTION:
			health--;

			if(health < 0) health = 0;

			spriteState			= selectedAbility;
			attackFinished		= finishedAnimation;

			healTicks++;
			break;
	}
}

void Player::ExecuteAbility()
{
	switch(selectedAbility)
	{
		case LESSER_ICE:
			attackTime = 30;
			moveDistance = 10;
			break;
		case GREATER_ICE:
			attackTime = 18;
			moveDistance = 10;
			break;
		case LESSER_WAND:
			attackTime = 8;
			moveDistance = 60;
			break;
		case ELECTRIC_STORM:
			attackTime = 18;
			moveDistance = 10;
			break;
		case GREATER_WAND:
			attackTime = 8;
			moveDistance = 60;
			break;
		case WHIRLWIND:
			attackTime = 8;
			moveDistance = 60;
			break;
		case HEAL:
			moveDistance = 0;			
			break;
	}	
}