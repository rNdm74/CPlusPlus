#pragma once

#include "GameObject.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class GameObjectList
	{
	private:
		GameObject^ head;
		GameObject^ tail;

	public:
		GameObjectList();
		void addGameObject(GameObject^ newGameObject);
		void deleteGameObject(GameObject^ gameObjectToDelete);
		int countGameObjects();

		void inputGameObjects(KeyEventArgs^  e);
		void updateGameObjects();
		void renderGameObjects();

		GameObject^ getHead() { return head; }
	};
