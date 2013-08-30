#pragma once

using namespace System::Media;
using namespace System::Resources;

ref class Sound
{
private:
	SoundPlayer^ player;
	ResourceManager^ rManager;

public:
	bool Play;

public:
	Sound(ResourceManager^ rm);
	void play(System::String^ file);
};
