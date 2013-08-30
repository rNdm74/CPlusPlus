#include "StdAfx.h"
#include "Sound.h"

Sound::Sound(ResourceManager^ rm)
{
	rManager = rm;
	Play = true;	
}

void Sound::play(System::String^ file)
{	
	//
	player = gcnew SoundPlayer(rManager->GetStream(file));

	//player->SoundLocation = rManager->GetString(file);
	//player->LoadAsync();

	if(Play) player->Play();
}

