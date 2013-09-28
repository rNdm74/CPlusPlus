#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class ObjectMap
{
private:
	array<int, 2>^ objectMap;

public:
	ObjectMap(array<int, 2>^ startObjectMap);

	Point getSpawnPosition(int spriteType, int spriteHeight);
};
