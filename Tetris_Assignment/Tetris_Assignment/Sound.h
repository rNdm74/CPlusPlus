#pragma once

using namespace System::Media;

ref class Sound
{
private:
	SoundPlayer^ player;

public:
	bool Play;

public:
	Sound();
	void play(System::String^ file);
};
