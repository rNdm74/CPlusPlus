// Tetris_Assignment.cpp : main project file.

#include "stdafx.h"
#include "Tetris.h"

using namespace Tetris_Assignment;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true); 

	// Create the main window and run it
	Application::Run(gcnew Tetris());
	return 0;
}
