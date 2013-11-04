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
	public:
		FileReader();

		array<int,2>^ getMap(String^ filename);
	};
