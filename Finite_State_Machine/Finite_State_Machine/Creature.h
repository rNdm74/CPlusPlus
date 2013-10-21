#pragma once
#include "thing.h"

public enum ECreatureState {WANDERING, EATING, ORIENTING};

ref class Creature :
public Thing
	{
	private:
		static const int eatingTime = 10;
		static const int wanderingLimit = 100;
			
		ECreatureState creatureState;
		int sensingRange;
		int eatingTicks;
		int wanderingTime;
		int wanderingTicks;

		int myFoodIndex;

	public:
		Creature(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight,String^ imageFileName);

		// FSM Methods
		void UpdateState(array<Thing^>^ foodInWorld, array<Thing^>^ obstaclesInWorld);
		void PerformAction();

		int findNearIndex(array<Thing^>^ otherGuys);
	};
