#pragma once

#include "Gnome.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class GnomeManager
	{
	private:
		int nGnomes;
		array<Gnome^>^ gnomes;
		Random^ rGen;
		Graphics^ canvas;

	public:
		// Constructor
		GnomeManager(Graphics^ g, int gnomeCount);

		// Functions
		void drawAllGnomes();
		void drawOneGnome(int index);
		void eraseAllGnomes();
		void eraseOneGnome(int index);
		void visibleGnome(int index);
		void hitGnome(Point p);
		int getHitHamsters();
		bool isGnomeHamster(int index);
	};
