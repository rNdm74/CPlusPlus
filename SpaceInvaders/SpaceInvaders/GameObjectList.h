#pragma once
#include "gameobject.h"

ref class GameObjectList
{
private:
	GameObject^ head;
	GameObject^ tail;

public:
	GameObjectList();
	int countGameObjects();
	void add(GameObject^ newGameObject);
	void remove(GameObject^ gameObjectToDelete);
	void update();
	void render();
};
