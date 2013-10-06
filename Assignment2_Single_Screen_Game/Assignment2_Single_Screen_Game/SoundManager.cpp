#include "StdAfx.h"
#include "SoundManager.h"

SoundManager::SoundManager()
	{
		collectCoin = gcnew SoundPlayer("hitsound.wav");
		collectFlag = gcnew SoundPlayer("scored.wav");
		playerHurt = gcnew SoundPlayer("hurt.wav");
		levelComplete = gcnew SoundPlayer("levelcomplete.wav");
		levelOver = gcnew SoundPlayer("levelcomplete.wav");
	}
