// Assignment3_Final_Game.cpp : main project file.

#include "stdafx.h"
#include "Dirty_Monkey.h"

using namespace Assignment3_Final_Game;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Dirty_Monkey());
	return 0;
}
