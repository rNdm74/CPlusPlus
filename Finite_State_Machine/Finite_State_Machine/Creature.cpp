#include "StdAfx.h"
#include "Creature.h"

Creature::Creature(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight,String^ imageFileName, int startRadius)
		 :Thing(startCanvas, startRandom, startWorldWidth, startWorldHeight, imageFileName, startRadius)
	{
	}

void Creature::UpdateState(array<Thing^>^ foodInWorld, array<Thing^>^ obstaclesInWorld)
	{
		switch(creatureState)
		{
			case WANDERING:
				if(foundCookie(foodInWorld)) creatureState = EATING;
				else if(hitGem(obstaclesInWorld)) creatureState = ORIENTING;
				break;
			case EATING:
				if(finishedEating(foodInWorld)) creatureState = WANDERING;
				break;
			case ORIENTING:
				if(finishedOrienting(obstaclesInWorld)) creatureState = WANDERING;
				break;
		}
	}

bool Creature::foundCookie(array<Thing^>^ foodInWorld)
	{
		bool hit = false;

		for(int object = 0; object < foodInWorld->Length; object++)
		{
			if(foodInWorld[object] != nullptr)
			{
				if(collided(foodInWorld[object]))
				{
					myFoodIndex = object;
					
					hit = true;

					break;
				}
			}										
		}

		return hit;
	}

bool Creature::hitGem(array<Thing^>^ obstaclesInWorld)
	{
		bool hit = false;

		for(int object = 0; object < obstaclesInWorld->Length; object++)
		{			
			if(collided(obstaclesInWorld[object]))
			{
				hit = true;

				break;
			}				
		}

		return hit;
	}

bool Creature::finishedEating(array<Thing^>^ foodInWorld)
	{
		if(eatingTicks > eatingTime)
		{
			eatingTicks = 0;			

			radius += 2;	

			foodInWorld[myFoodIndex] = nullptr;

			return true;
		}

		return false;
	}

bool Creature::finishedOrienting(array<Thing^>^ obstaclesInWorld)
	{

		int index;

		for(int object = 0; object < obstaclesInWorld->Length; object++)
		{			
			if(collided(obstaclesInWorld[object]))
			{				
				index = object;
				break;
			}				
		}

		if(ComputeDistance(obstaclesInWorld[index]) > 30)
		{
			ChangeRandomDirection();

			return true;
		}
		
		return false;
	}

void Creature::PerformAction()
	{
		switch(creatureState)
		{
			case WANDERING:
				if(wanderingTicks > wanderingLimit)
				{
					wanderingTicks = 0;

					ChangeRandomDirection();					
				}
				else
				{
					Move();

					wanderingTicks++;
				}
				break;
			case EATING:
				eatingTicks++;
				break;
			case ORIENTING:	
				double radiansAngle = angle * 0.01745;
				location.X -= Math::Cos(radiansAngle) * speed;
				location.Y -= Math::Sin(radiansAngle) * speed;				
				break;
		}
	}

int Creature::findNearIndex(array<Thing^>^ otherGuys)
	{		
		return 0;
	}
