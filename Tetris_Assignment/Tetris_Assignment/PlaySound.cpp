#include "StdAfx.h"
#include "PlaySound.h"

PlaySound::PlaySound(System::String^ file)
{
	SoundPlayer^ player = gcnew SoundPlayer();
	player->SoundLocation = file;
	player->Load();
	player->Play();
}

PlaySound::PlaySound(System::String^ file, bool sync)
{
	SoundPlayer^ player = gcnew SoundPlayer();
	player->SoundLocation = file;
	player->Load();

	(sync) ? player->PlaySync() : player->Play();
}


