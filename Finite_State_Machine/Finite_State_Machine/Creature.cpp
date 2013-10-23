#include "StdAfx.h"
#include "Creature.h"

Creature::Creature(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight,String^ imageFileName, int startRadius)
		 :Thing(startCanvas, startRandom, startWorldWidth, startWorldHeight, imageFileName, startRadius)
	{
	}

void Creature::UpdateState(array<Thing^>^ foodInWorld, array<Thing^>^ obstaclesInWorld)
	{
		//
		// Updates the state of the creature based on specific conditions.
		//
		// If the creature is WANDERING the creature will check if
		// a cookie is found in the world, it will change its state to EATING
		// And if a gem is hit its state will change to ORIENTING.
		//
		// If the Creature is EATING it will not change to WANDERING unless it has finished
		// eating the cookie.
		//
		// If the creature is ORIENTING it will not start WANDERING until it has finished
		// orienting itself from the obstacle.
		//
		switch(creatureState)
		{
			case WANDERING:
				if(foundCookie(foodInWorld)) 
				{
					creatureState = EATING;
				}
				else if(hitGem(obstaclesInWorld)) 
				{
					creatureState = ORIENTING;
				}
				break;
			case EATING:
				if(eatingTicks > eatingTime)
				{
					finishedEating(foodInWorld);

					creatureState = WANDERING;
				}
				break;
			case ORIENTING:
				if(hasFinishedOrienting(obstaclesInWorld)) 
				{					
					creatureState = WANDERING;
				}
				break;
		}
	}

void Creature::PerformAction()
	{
		switch(creatureState)
		{
			case WANDERING:
				if(wanderingTicks > wanderingLimit)
				{
					wanderingTicks = 0;				// Resets ticks

					ChangeRandomDirection();		// Change creatures direction
				}
				else
				{
					Move();							// Move creature

					wanderingTicks++;				// Tracks wandering time
				}
				break;
			case EATING:
				eatingTicks++;						// Tracks eating time
				break;
			case ORIENTING:	
				
				double radiansAngle = angle * 0.01745;			// Reverses creature
				location.X -= Math::Cos(radiansAngle) * speed;
				location.Y -= Math::Sin(radiansAngle) * speed;				
				break;
		}
	}

bool Creature::foundCookie(array<Thing^>^ foodInWorld)
	{
		//
		// Cycles through the food in the world and records 
		// and returns if the creature has found a cookie
		//
		bool found = false;

		for(int object = 0; object < foodInWorld->Length; object++)
		{
			if(foodInWorld[object] != nullptr)		// There is food in the array
			{
				if(collided(foodInWorld[object]))   // Hit a cookie
				{
					myFoodIndex = object;			// Records the object index
					
					found = true;					// found cookie
				}
			}	
		}

		return found;
	}

bool Creature::hitGem(array<Thing^>^ obstaclesInWorld)
	{
		//
		// Cycles through the obstacles in the world
		// and checks if the creature has hit an obstacle 
		//
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

void Creature::finishedEating(array<Thing^>^ foodInWorld)
	{
		//
		// Will return true when the creature has finished eating cookie
		//
		if(eatingTicks > eatingTime)			// When finished eating
		{
			eatingTicks = 0;					// Reset eating ticks			

			radius += 2;						// Grow the creature after eating cookie	

			foodInWorld[myFoodIndex] = nullptr; // Remove cookie from the array
		}
	}

bool Creature::hasFinishedOrienting(array<Thing^>^ obstaclesInWorld)
	{
		//
		// When creature has moved away from the object 
		// change his direction and return it is finished
		//
		int index = findNearIndex(obstaclesInWorld);

		sensingRange = ComputeDistance(obstaclesInWorld[index]); // Works out distance between creature and obstacle
		
		if(sensingRange > 50)
		{
			ChangeRandomDirection();						// Chooses a new direction

			return true;									// Creature finished orienting
		}		
		
		return false;										// Not finished orienting
	}



int Creature::findNearIndex(array<Thing^>^ otherGuys)
	{
		for(int object = 0; object < otherGuys->Length; object++)
		{
			if(otherGuys[object] != nullptr)		// There is food in the array
			{
				if(collided(otherGuys[object]))		// Hit a cookie
				{					
					return object;					// found cookie
				}
			}	
		}

		return 0;
	}
