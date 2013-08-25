#pragma once

using namespace System::Media;

ref class PlaySound
{
public:
	PlaySound(System::String^ file);
	PlaySound(System::String^ file, bool sync);
};
