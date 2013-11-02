#include "StdAfx.h"
#include "Enemy.h"

Enemy::Enemy(Graphics^ startCanvas, String^ startFileName, array<Point>^ startSpriteState, int startX, int startY)
	  :Sprite(startCanvas, startFileName, startSpriteState, startX, startY)
{
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
	 // Draws bitmap to the screen
	 //

	 xOFFSET = spriteFrame.Width;	 
	 yOFFSET = spriteFrame.Height;
	 
	 canvas->DrawImage(spriteBitmap, newXPos - xOFFSET, newYPos - yOFFSET);	
	 canvas->DrawRectangle(gcnew Pen(Color::Black), getCollisionRectangle(newXPos, newYPos));
	 
	 delete spriteBitmap;
}

void Enemy::UpdateState(Sprite^ otherSprite)
	{		
		switch(spriteAction)
		{
			case WAITING:
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

void Enemy::PerformAction()
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

void Enemy::UpdateMeleeAbility()
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
	}
}

void Enemy::PerformMeleeAbility(Sprite^ otherSprite)
{
	switch(meleeAbility)
	{
		case WALK_FORWARD:
			facingDirection = LEFT;
			Move();
			moveTicks++;
			break;
		case MELEE_ATTACK:			
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
		case MELEE_FINISHED:
			moveTicks = 0;
			spriteState = IDLE;
			facingDirection = LEFT;
			spriteAction = WAITING;
			waiting = true;
			break;
	}
}

void Enemy::UpdateMagicAbility()
{
	switch(meleeAbility)
	{
		case MAGIC_ATTACK:
			break;
		case MAGIC_FINISHED:			
			break;
	}
}

void Enemy::PerformMagicAbility(Sprite^ otherSprite)
{
	switch(meleeAbility)
	{
		case MAGIC_ATTACK:
			break;
		case MAGIC_FINISHED:		
			break;
	}
}

void Enemy::ExecuteAbility(Sprite^ otherSprite)
{
	//move forward
	//attack
	//move backward
	//return true
	

	switch(selectedAbility)
	{
		case IDLE:
			break;
		case HURT:
			break;
		case BOSS_HURT:
			moveDistance = 70;
			UpdateMeleeAbility();
			PerformMeleeAbility(otherSprite);
			break;
		case LESSER_ICE:
			moveDistance = 70;
			UpdateMeleeAbility();
			PerformMeleeAbility(otherSprite);
			break;
		case GREATER_ICE:
			break;
		case WALK:
			break;
		case LESSER_WAND:
			//UpdateMeleeAbility();
			//PerformMeleeAbility(otherSprite);
			//
			////move to enemy position		:: WALK
			////attack enemy					:: SELECTED_ABILITY
			////move back to start position	:: WALK
			////face enemy
			break;
		case DODGE:
			break;
		case ELECTRIC_STORM:
			break;
		case GREATER_WAND:
			//UpdateMeleeAbility();
			//PerformMeleeAbility(otherSprite);
			////move to enemy position		:: WALK
			////attack enemy					:: SELECTED_ABILITY
			////move back to start position	:: WALK
			////face enemy
			break;
		case WHIRLWIND:
			//UpdateMeleeAbility();
			//PerformMeleeAbility(otherSprite);
			////move to enemy position		:: WALK
			////attack enemy					:: SELECTED_ABILITY
			////move back to start position	:: WALK
			////face enemy
			break;
		case HEAL:
			break;
	}
}