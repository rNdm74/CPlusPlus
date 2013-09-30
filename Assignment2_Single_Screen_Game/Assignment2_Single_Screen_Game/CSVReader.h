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

	private:
		array<int,2>^ getMap(String^ filename);
		array<int,3>^ getMap(String^ filename, int dim0, int dim1, int dim2);

	public:
		CSVReader();

		array<int,2>^ getCoinMap()		{ return getMap("coinmap.csv"); }
		array<int,2>^ getObjectMap()	{ return getMap("objectmap.csv"); }
		array<int,2>^ getTileMap()		{ return getMap("tilemap.csv"); }
		array<int,3>^ getPlayerMap()	{ return getMap("playerMap.csv", 5, 11, 4); }
		array<int,3>^ getAlienMap()		{ return getMap("alienMap.csv", 5, 11, 4); }
		array<int,3>^ getItemMap()		{ return getMap("itemMap.csv", 5, 2, 4); }
	};
