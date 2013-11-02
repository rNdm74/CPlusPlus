#pragma once

#include "Constants.h"
#include "Player.h"
#include "Enemy.h"

using namespace System::Drawing;

ref class Hud
{
private:
	Graphics^ dbGraphics;

	Image^ hud;

	Bitmap^ playerHealthImage;
	Bitmap^ playerManaImage;
	Graphics^ playerHealthCanvas;
	Graphics^ playerManaCanvas;
	Bitmap^ enemyHealthImage;
	Graphics^ enemyHealthCanvas;

	int enemyHealth, playerHealth, mana;
	long enemyRegen, healthRegen, manaRegen;

private:
	void UpdateHealth(Player^ player);
	void UpdateHealth(Enemy^ enemy);
	void UpdateMana(Player^ player);

public:
	Hud(Graphics^ startCanvas);

	void Update(Player^ player, Enemy^ enemy);
	void Draw();



	//GETS

	//SETS
};
