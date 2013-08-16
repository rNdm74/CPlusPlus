#pragma once
#include "gameobject.h"

ref class GameObjectList
{
private:
	GameObject^ head;
	GameObject^ tail;

public:
	GameObjectList();
	int length();
	GameObject^ get(int item);
	void add(GameObject^ newGameObject);
	void remove(GameObject^ gameObjectToDelete);
	void update();
	void render();
};
