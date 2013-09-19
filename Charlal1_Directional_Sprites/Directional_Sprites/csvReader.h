#pragma once

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#define N_COLS 60	// X Tiles
#define N_ROWS 30 	// Y tiles

ref class CsvReader
	{
	private:
		StreamReader^ reader;
		array<String^>^ items;
		array<int,2>^ tileMap;
	public:
		CsvReader();

		array<int,2>^ getTileMap()	{ return tileMap; }
	};
