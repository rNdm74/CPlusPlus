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
	Image^ inventory;

	Image^ drawHud;

	Bitmap^ playerHealthImage;
	Bitmap^ playerManaImage;
	Graphics^ playerHealthCanvas;
	Graphics^ playerManaCanvas;
	Bitmap^ enemyHealthImage;
	Graphics^ enemyHealthCanvas;

	int enemyHealth, playerHealth, mana;
	long enemyRegen, healthRegen, manaRegen;

	bool poison;
	bool powerup;
	static int poisonTime = 20;
	int poisonTick;
	static int powerupTime = 50;
	int powerupTick;

private:
	void UpdateHealth(Player^ player);
	void UpdateHealth(Player^ player, Enemy^ enemy);
	void UpdateMana(Player^ player);

public:
	Hud(Graphics^ startCanvas);

	void Update(Player^ player, Enemy^ enemy);
	void Draw();



	//GETS
	bool isPoisonUsed()				{ return poison; }
	void setPoison(bool p)			{ poison = p; }
	bool isPowerupUsed()			{ return powerup; }
	void setPowerup(bool p)			{ powerup = p; }


	//SETS
	void showInventory() { drawHud = inventory; }
	void hideInventory() { drawHud = hud; }

};
