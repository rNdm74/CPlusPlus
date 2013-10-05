#pragma once

#include "Constants.h"

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for FileReader
///
///	   Note: The File Reader will read files outside of the program and load  
///          into arrays to be used in the game.
///
/// </summary>

ref class FileReader
	{
	private:
		StreamReader^ reader;

		array<String^>^ items;

		array<int,3>^ map3D;
		array<int,2>^ map2D;

		Random^ rGen;

	private:
		array<int,2>^ getMap(String^ filename);
		array<int,3>^ getMap(String^ filename, int dim0, int dim1, int dim2);

	public:
		FileReader(Random^ startRGen);

		array<int,3>^ getSpriteSheetData(int startObjectNumber);
		
		array<int,2>^ getCoinMap(int level)		{ return getMap("level"+ level +"coin.map"); }
		array<int,2>^ getSpawnMap(int level)	{ return getMap("level"+ level +"spawn.map"); }
		array<int,2>^ getTileMap(int level)		{ return getMap("level"+ level +".map"); }

		array<int,3>^ getPlayerMap()			{ return getMap("player.map", 6, 11, 4); }
		array<int,3>^ getAlienMap()				{ return getMap("alien.map", 5, 11, 4); }
		array<int,3>^ getItemMap()				{ return getMap("flag.map", 5, 4, 4); }
	};
