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

void Player::UpdateMeleeAbility()
{
	switch(meleeAbility)
	{
		case WALK_FORWARD:
			if(moveTicks > moveDistance)
			{
				meleeAbility = MELEE_ATTACK;				
			}
			break;
		case MELEE_ATTACK:
			if(attackFinished)
			{				
				meleeAbility = WALK_BACKWARD;				
			}			
			break;
		case WALK_BACKWARD:
			if(moveTicks > moveDistance)
			{
				meleeAbility = MELEE_FINISHED;
			}
			break;
		case MAGIC_ATTACK:
			if(attackFinished)
			{
				meleeAbility = MELEE_FINISHED;				
			}
			break;
		case MAGIC_FINISHED:			
			break;
	}
}

void Player::PerformMeleeAbility(Sprite^ otherSprite)
{
	switch(meleeAbility)
	{
		case WALK_FORWARD:
			spriteState = WALK;
			facingDirection = RIGHT;
			Move();
			moveTicks++;
			break;
		case MELEE_ATTACK:			
			moveTicks = 0;
			
			spriteState = selectedAbility;

			if(attackTicks > attackTime && usedAbility == false)
			{
				usedAbility = true;
				setMana(5 * safe_cast<int>(selectedAbility));
				otherSprite->setState(HURT);				
			}	
			attackTicks++;

			attackFinished = finishedAnimation;
			break;
		case WALK_BACKWARD:	
			usedAbility = false;
			otherSprite->setState(IDLE);
			attackTicks = 0;
			spriteState = WALK;
			facingDirection = LEFT;
			Move();
			moveTicks++;
			break;
		case MELEE_FINISHED:
			moveTicks = 0;
			spriteState = IDLE;
			facingDirection = RIGHT;
			spriteAction = WAITING;
			waiting = true;
			enemyTurn = true;
			break;
		case MAGIC_ATTACK:
			spriteState = selectedAbility;

			if(attackTicks > attackTime)
			{
				otherSprite->setState(HURT);				
			}	

			attackTicks++;

			attackFinished = finishedAnimation;
			break;
		case MAGIC_FINISHED:	
			otherSprite->setState(IDLE);
			attackTicks = 0;
			spriteState = IDLE;
			spriteAction = WAITING;
			waiting = true;
			enemyTurn = true;
			break;
	}
}

void Player::UpdateMagicAbility()
{
	/*switch(magicAbility)
	{
		
	}*/
}

void Player::PerformMagicAbility(Sprite^ otherSprite)
{
	/*switch(magicAbility)
	{
		
		
	}*/
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

	UpdateMeleeAbility();
	PerformMeleeAbility(otherSprite);
}