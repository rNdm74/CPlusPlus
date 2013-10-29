// Assignment 3.cpp : main project file.

#include "stdafx.h"
#include "ApprenticeTrial.h"

using namespace Assignment3;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew ApprenticeTrial());
	return 0;
}
