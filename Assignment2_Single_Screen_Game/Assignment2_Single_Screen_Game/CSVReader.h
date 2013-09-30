#pragma once

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

/// <summary>
/// Summary for CSV Reader
///
///	   Note: The CSV Reader will read files outside of the program and load  
///          into arrays to be used in the game.
///
/// </summary>

ref class CSVReader
	{
	private:
		StreamReader^ reader;

		array<String^>^ items;

		array<int,2>^ coinMap;
		array<int,2>^ objectMap;
		array<int,2>^ tileMap;

	private:
		array<int,2>^ populateMap(String^ filename);

	public:
		CSVReader(String^ tileMapFileName, String^ objectMapFileName, String^ coinMapFileName);

		array<int,2>^ getCoinMap()		{ return coinMap; }
		array<int,2>^ getObjectMap()	{ return objectMap; }
		array<int,2>^ getTileMap()		{ return tileMap; }
	};
