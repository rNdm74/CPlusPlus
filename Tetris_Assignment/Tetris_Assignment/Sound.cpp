#include "StdAfx.h"
#include "Sound.h"

Sound::Sound()
{
	Play = true;	
}

void Sound::play(System::String^ file)
{	
	player = gcnew SoundPlayer();

	player->SoundLocation = file;
	player->LoadAsync();

	if(Play) player->Play();
}

