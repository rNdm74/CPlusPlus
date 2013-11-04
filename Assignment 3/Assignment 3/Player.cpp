#include "StdAfx.h"
#include "Player.h"

Player::Player(Graphics^ startCanvas, String^ startFileName, Point startLocation, ArrayList^ startFrameList)
	   :Sprite(startCanvas, startFileName, startLocation, startFrameList)
{
	// Angle player flys when killed
	radiansAngle = 220 * 0.01745;

	// Sets angle and power
	xVel = Math::Cos(radiansAngle) * 30;
	yVel = Math::Sin(radiansAngle) * 40;

	// Sets the facing direction of the player
	facingDirection = RIGHT;

	// Points that player will clamp to when moving between battles
	battleStartPoints = gcnew array<int>
	{
		1024 + 250,
		2048 + 250,
		3072 + 250,
		4096 + 250
	};
}

void Player::Draw(int newXPos, int newYPos)
{	 
	 //
	 // Draw sprites frame to the screen
	 //	 
	 Bitmap^ spriteBitmap = spriteSheet->Clone(spriteFrame, PixelFormat::Format32bppArgb);
	 	 
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
					ExecuteAbility();
				}
				else if(health >= 131)
				{
					spriteAction = LOSE;
				}
				break;

			case WIN:
				if(otherSprite->isBoss() && otherSprite->isAlive() == false)
				{
					spriteAction = GAMEOVER;					
				}
				else if(battleSelection > 0 && xPos > battleStartPoints[battleScreen])
				{
					battleScreen++;
					nextBattle = false;
					selectedAbility = IDLE;
					spriteState = IDLE;					
					spriteAction = WAITING;					
				}
				break;

			case LOSE:
				if(loseTicks > loseTime)
				{
					alive = false;
					loseTicks = 0;
					gameover = true;
					spriteAction = WAITING;					
				}
				break;

			case USE_ABILITY:
				if(otherSprite->isAlive() == false)
				{
					moveTicks = 0;
					spriteAction = HOME;
				}
				else if(waiting)
				{
					spriteAction = WAITING;
				}				
				break;

			case HOME:
				if(moveTicks > moveDistance)
				{					
					moveTicks = 0;
					spriteAction = WIN;
				}

			case GAMEOVER:
				if(winTicks > winTime)
				{
					gameover = true;
				}
				spriteState = DODGE;				
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
				spriteState	= WALK;
				facingDirection	= RIGHT;
				Move();
				if(xPos > 1025 * (battleSelection + 1) && nextBattle == false)
				{
					nextBattle = true;
					battleSelection++;
				}
				moveTicks++;
				break;

			case LOSE:
				spriteState = HURT;
				facingDirection = RIGHT;								
				xPos += xVel;
				yPos += yVel;
				yVel += GRAVITY;
				loseTicks++;
				break;

			case USE_ABILITY:					
				
				UpdateAbility();
				PerformAbility(otherSprite);
				break;	

			case HOME:				
				facingDirection	= LEFT;
				spriteState	= WALK;
				Move();
				moveTicks++;
				break;

			case GAMEOVER:
				winTicks++;
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
			if(healTicks > healTime)
			{
				potion = "";
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

				setMana(manaCost);

				otherSprite->setState(HURT);
				otherSprite->setHurt(true);
				otherSprite->setHealth(healthCost);
			}	

			attackFinished = finishedAnimation;
			attackTicks++;			
			break;

		case WALK_BACKWARD:	
			otherSprite->setHurt(false);
			otherSprite->setState(IDLE);
			usedAbility	= false;
			attackTicks	= 0;
			spriteState	= WALK;
			facingDirection	= LEFT;
			Move();
			moveTicks++;
			break;

		case FINISHED:
			otherSprite->setWaiting(false);
			moveTicks = 0;
			healTicks = 0;
			spriteState	= IDLE;
			selectedAbility	= IDLE;
			facingDirection	= RIGHT;
			spriteAction = WAITING;	
			attacking = false;
			waiting	= true;
			turnOver = true;
			break;

		case HEALTH_POTION:
			if(potion == "health")
			{
				health--;
				if(health < 0) health = 0;
			}
			else
			{
				mana--;
				if(mana < 0) mana = 0;
			}
			spriteState	= selectedAbility;
			attackFinished = finishedAnimation;
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
			healthCost = 40 - battleSelection;
			manaCost = 40;
			break;
		case GREATER_ICE:
			attackTime = 18;
			moveDistance = 10;
			healthCost = 50;
			manaCost = 50;
			break;
		case LESSER_WAND:
			attackTime = 8;
			moveDistance = 60;
			healthCost = 10;
			manaCost = 10;
			break;
		case ELECTRIC_STORM:
			attackTime = 18;
			moveDistance = 10;
			healthCost = 60;
			manaCost = 60;
			break;
		case GREATER_WAND:
			attackTime = 8;
			moveDistance = 60;
			healthCost = 20;
			manaCost = 20;
			break;
		case WHIRLWIND:
			attackTime = 8;
			moveDistance = 60;
			healthCost = 30;
			manaCost = 40;
			break;
		case HEAL:
			moveDistance = 0;			
			break;
	}	
}