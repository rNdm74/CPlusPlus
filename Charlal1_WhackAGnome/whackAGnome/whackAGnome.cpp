// whackAGnome.cpp : main project file.

#include "stdafx.h"
#include "Game.h"

using namespace whackAGnome;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Game());
	return 0;
}
