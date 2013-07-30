#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum ECreatureType
		{
			WITCH = 0, 
			MONSTER = 1,
		};

ref class Creature
	{
	private:  
		ECreatureType eCreatureType;

	public:
		Creature();
		Creature(ECreatureType eCreatureType);
		void Speak();
	};
