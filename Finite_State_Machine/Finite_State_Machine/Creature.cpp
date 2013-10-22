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
			}
		}

		return hit;
	}

bool Creature::finishedEating(array<Thing^>^ foodInWorld)
	{
		//
		// Will return true when the creature has finished eating cookie
		//

		bool finished = false;

		if(eatingTicks > eatingTime)			// When finished eating
		{
			eatingTicks = 0;					// Reset eating ticks			

			radius += 2;						// Grow the creature after eating cookie	

			foodInWorld[myFoodIndex] = nullptr; // Remove cookie from the array

			finished = true;					// Finished eating cookie
		}

		return finished;
	}

bool Creature::finishedOrienting(array<Thing^>^ obstaclesInWorld)
	{
		//
		// When creature has moved away from the object 
		// change his direction and return it is finished
		//
		int index;

		for(int object = 0; object < obstaclesInWorld->Length; object++)
		{
			if(collided(obstaclesInWorld[object]))
			{				
				index = object;
				break;
			}				
		}

		double distance = ComputeDistance(obstaclesInWorld[index]);
		
		if(distance > 50)
		{
			ChangeRandomDirection();						// Chooses a new direction

			return true;									// Creature finished orienting
		}		
		
		return false;										// Not finished orienting
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
