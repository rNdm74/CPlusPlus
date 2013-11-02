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
	 //
	 //
	 
	 //
	 // Flips image on the X axis based on direction
	 //
	 xOFFSET = 0;	 
	 yOFFSET = spriteFrame.Height;

	 if(facingDirection == LEFT) 
	 {
		 spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);
	 }	
	 //
	 // Draws bitmap to the screen
	 //
	 canvas->DrawImage(spriteBitmap, newXPos - xOFFSET, newYPos - yOFFSET);	
	 //canvas->DrawRectangle(gcnew Pen(Color::Black), getCollisionRectangle(newXPos, newYPos));
	 
	 delete spriteBitmap;
}

void Player::UpdateState(Sprite^ otherSprite)
	{	
		

		switch(spriteAction)
		{
			case WAITING:
				enemyTurn = false;
				break;
			case HOME:
				break;
			case ATTACKING:
				waiting = false;
				ExecuteAbility(otherSprite);
				break;
			case FINISHED_ATTACKING:
				break;			
		}		
	}

void Player::PerformAction()
	{
		switch(spriteAction)
		{
			case WAITING:
				
				break;
			case HOME:
				break;
			case ATTACKING:				
				break;
			case FINISHED_ATTACKING:
				break;			
		}		
	}

void Player::UpdateAbility()
{
	switch(spriteAbility)
	{
		case WALK_FORWARD:
			if(moveTicks > moveDistance)
			{
				spriteAbility = ATTACK;				
			}
			else if(selectedAbility == HEAL)
			{
				spriteAbility = HEALTH_POTION;
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
			if(attackFinished)
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
				otherSprite->setHealth(10 * safe_cast<int>(selectedAbility));				
			}	
			attackTicks++;

			attackFinished = finishedAnimation;
			break;
		case WALK_BACKWARD:				
			usedAbility = false;
			otherSprite->setHurt(false);
			otherSprite->setState(IDLE);
			attackTicks = 0;
			spriteState = WALK;
			facingDirection = LEFT;
			Move();
			moveTicks++;
			break;
		case FINISHED:
			moveTicks = 0;
			spriteState = IDLE;
			facingDirection = RIGHT;
			spriteAction = WAITING;
			waiting = true;
			enemyTurn = true;
			break;
		case HEALTH_POTION:
			setHealth(-20);
			if(health < 0) health = 0;
			spriteState = selectedAbility;
			attackFinished = finishedAnimation;
			break;
	}
}

void Player::ExecuteAbility(Sprite^ otherSprite)
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

	UpdateAbility();
	PerformAbility(otherSprite);
}