#pragma once

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class CSVReader
	{
	private:
		StreamReader^ reader;
		array<String^>^ items;
		array<int,2>^ tileMap;
	public:
		CSVReader();

		array<int,2>^ getTileMap()	{ return tileMap; }
	};
