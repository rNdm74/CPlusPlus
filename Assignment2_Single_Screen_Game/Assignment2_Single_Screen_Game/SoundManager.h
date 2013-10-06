#pragma once

using namespace System::Media;

ref class SoundManager
	{
	public:
		SoundPlayer^ collectCoin;
		SoundPlayer^ collectFlag;
		SoundPlayer^ playerHurt;
		SoundPlayer^ levelComplete;
		SoundPlayer^ levelOver;

	public:
		SoundManager();
	};
