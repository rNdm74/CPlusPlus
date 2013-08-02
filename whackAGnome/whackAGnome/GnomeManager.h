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
		GnomeManager(Graphics^ g, int gnomeCount);

		void drawAllGnomes();
		void drawOneGnome(int index);
		void eraseAllGnomes();
		void eraseOneGnome(int index);

		void hitGnome(int index, Point p);

		int getHamsters();

		//set
		void setRGen(Random^ r){ rGen = r; }

		//get
		Random^ getRGen(){ return rGen; }
		array<Gnome^>^ getGnomes(){ return gnomes; }
	};
