#pragma once

#include "GameObject.h";

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Physics
{
private:
public:
	bool checkCollision(GameObject^ o1, GameObject^ o2);
};