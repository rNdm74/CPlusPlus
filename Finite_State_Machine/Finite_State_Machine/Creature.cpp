#include "StdAfx.h"
#include "Creature.h"

Creature::Creature(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight,String^ imageFileName)
		 :Thing(startCanvas, startRandom, startWorldWidth, startWorldHeight, imageFileName)
	{
	}

void Creature::UpdateState(array<Thing^>^ foodInWorld, array<Thing^>^ obstaclesInWorld)
	{
		switch(creatureState)
		{
			case WANDERING:
				break;
			case EATING:
				break;
			case ORIENTING:
				break;
		}
	}

void Creature::PerformAction()
	{
		switch(creatureState)
		{
			case WANDERING:
				break;
			case EATING:
				break;
			case ORIENTING:
				break;
		}
	}

int Creature::findNearIndex(array<Thing^>^ otherGuys)
	{
		return 0;
	}
