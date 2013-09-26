// Assignment2_Single_Screen_Game.cpp : main project file.

#include "stdafx.h"
#include "FranticAlien.h"

using namespace Assignment2_Single_Screen_Game;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew FranticAlien());
	return 0;
}
