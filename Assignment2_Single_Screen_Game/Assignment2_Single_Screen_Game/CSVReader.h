#pragma once

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

/// <summary>
/// Summary for Sprite
///
///	   Note: If you change the name of this class, you will need to change the
///          'Resource File Name' property for the managed resource compiler tool
///          associated with all .resx files this class depends on.  Otherwise,
///          the designers will not be able to interact properly with localized
///          resources associated with this form.
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
