#include "StdAfx.h"
#include "Hud.h"

Hud::Hud(Graphics^ startCanvas)
{
	dbGraphics = startCanvas;

	hud = Image::FromFile("hud.png");
	inventory = Image::FromFile("inventory.png");
	drawHud = hud;


	playerHealthImage = gcnew Bitmap(132, 132, PixelFormat::Format32bppArgb);
	playerManaImage = gcnew Bitmap(132, 132, PixelFormat::Format32bppArgb);	
	enemyHealthImage = gcnew Bitmap(132, 132, PixelFormat::Format32bppArgb);

	playerHealthCanvas = Graphics::FromImage(playerHealthImage);
	playerManaCanvas = Graphics::FromImage(playerManaImage);
	enemyHealthCanvas = Graphics::FromImage(enemyHealthImage);

	playerHealthCanvas->FillEllipse(Brushes::DarkRed, Rectangle(0,0,132,132)); 
	playerManaCanvas->FillEllipse(Brushes::DarkBlue, Rectangle(0,0,132,132));
	enemyHealthCanvas->FillEllipse(Brushes::DarkRed, Rectangle(0,0,132,132)); 

	for(int x = 0; x < 132; x++)
		for(int y = 0; y < playerHealth; y++)
			playerHealthImage->SetPixel(x, y, Color::Transparent);
		
	for(int x = 0; x < 132; x++)
		for(int y = 0; y < enemyHealth; y++)
			enemyHealthImage->SetPixel(x, y, Color::Transparent);

	for(int x = 0; x < 132; x++)
		for(int y = 0; y < mana; y++)
			playerManaImage->SetPixel(x, y, Color::Transparent);
}

void Hud::UpdateHealth(Player^ player)
{
	//
	// Health Hud Information
	//			
	playerHealth = player->getHealth();

	if(playerHealth > 132) playerHealth = 132;

	if(healthRegen > 15 && playerHealth >= 0)
	{
		if(powerupTick > powerupTime)
		{
			powerupTick = 0;
			player->setPowerup(false);
			powerup = false;
		}

		playerHealthCanvas->FillEllipse(((powerup) ? Brushes::DarkGoldenrod : Brushes::DarkRed), Rectangle(0,0,132,132));
		
		for(int x = 0; x < 132; x++)
			for(int y = 0; y < playerHealth; y++)
				playerHealthImage->SetPixel(x, y, Color::Transparent);

		if(powerup)
		{
			player->setMana(-1);
			player->setHealth(-1);
			powerupTick++;
		}
			

		healthRegen = 0;
	}
}

void Hud::UpdateHealth(Player^ player, Enemy^ enemy)
{
	//
	// Health Hud Information
	//			
	enemyHealth = enemy->getHealth();

	if(enemyHealth > 132) enemyHealth = 132;

	if(enemyRegen > 15 && enemyHealth >= 0)
	{
		if(poisonTick > poisonTime && enemyHealth > 10)
		{
			poisonTick = 0;
			player->setPoison(false);
			poison = false;
		}

		enemyHealthCanvas->FillEllipse(((poison) ? Brushes::DarkGreen : Brushes::DarkRed), Rectangle(0,0,132,132));
		
		for(int x = 0; x < 132; x++)
			for(int y = 0; y < enemyHealth; y++)
				enemyHealthImage->SetPixel(x, y, Color::Transparent);

		if(poison && enemyHealth > 10)
		{
			enemy->setHealth(1);
			poisonTick++;
		}
		  

		enemyRegen = 0;
	}
}

void Hud::UpdateMana(Player^ player)
{
	//
	// Mana Hud Information
	//
	mana = player->getMana();

	if(mana > 132) mana = 132;

	if(manaRegen > 25 && mana >= 0)
	{
		playerManaCanvas->FillEllipse(((powerup) ? Brushes::DarkGoldenrod : Brushes::DarkBlue), Rectangle(0,0,132,132));

		for(int x = 0; x < 132; x++)
			for(int y = 0; y < mana; y++)
				playerManaImage->SetPixel(x, y, Color::Transparent);	

		
		manaRegen = 0;
	}
}

void Hud::Update(Player^ player, Enemy^ enemy)
{
	UpdateHealth(player);
	UpdateMana(player);	
	UpdateHealth(player, enemy);
	

	//
	// Regeneration time
	//
	enemyRegen++;
	healthRegen++;	
	manaRegen++;
}

void Hud::Draw()
{
	dbGraphics->DrawImageUnscaledAndClipped(enemyHealthImage, Rectangle(862, 15, 132, 132));

	dbGraphics->DrawImageUnscaledAndClipped(playerHealthImage, Rectangle(18, 581, 132, 132));
	dbGraphics->DrawImageUnscaledAndClipped(playerManaImage, Rectangle(176, 581, 132,132));
	
	dbGraphics->DrawImage(drawHud, 0, 0, 1024, 768);
}
