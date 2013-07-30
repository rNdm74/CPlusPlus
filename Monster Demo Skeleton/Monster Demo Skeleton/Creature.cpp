#include "StdAfx.h"
#include "Creature.h"

Creature::Creature()
	{
		eCreatureType = ECreatureType::MONSTER;
	}
Creature::Creature(ECreatureType eCT)
	{
		eCreatureType = eCT;		
	}

void Creature::Speak()
	{
		if(eCreatureType == ECreatureType::MONSTER) MessageBox::Show("I am a Monster! ROAR!");
		if(eCreatureType == ECreatureType::WITCH) MessageBox::Show("I am a Witch! Hehehe!");
	}
