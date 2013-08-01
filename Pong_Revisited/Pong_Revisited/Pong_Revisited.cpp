// Pong_Revisited.cpp : main project file.

#include "stdafx.h"
#include "Pong.h"

using namespace Pong_Revisited;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Pong());
	return 0;
}
