#include "StdAfx.h"
#include "GridManager.h"

GridManager::GridManager(Graphics^ dbGraphics)
{
	rGen = gcnew Random();
	graphics = dbGraphics;

	pfc = gcnew PrivateFontCollection();
	pfc->AddFontFile("PressStart2P.ttf");
	background = Image::FromFile("background5.jpg");

	font = gcnew Font(pfc->Families[0], 16, FontStyle::Regular);
	fontBrush = gcnew SolidBrush(Color::CornflowerBlue);

	grid = gcnew Grid(Point(302,-60), graphics, font);

	blocks = gcnew array<Block^>(100);

	for(int b = 0; b < blocks->Length; b++)
		blocks[b] = getGameBlock();	

	blockInPlay = 0;
	waitTime = 150;
}

void GridManager::moveLeft()
{
	blocks[blockInPlay]->moveLeft();
}

void GridManager::moveRight()
{
	blocks[blockInPlay]->moveRight();
}

void GridManager::moveDown()
{
	blocks[blockInPlay]->moveDown();
}

void GridManager::moveRotate()
{
	blocks[blockInPlay]->moveRotate();	
}



void GridManager::update()
{
	if(blocks[blockInPlay]->isPlaced())
		blockInPlay++;

	grid->update();

	 

	if(time > waitTime - (grid->getPlayerLevel() * 20))
	{
		blocks[blockInPlay]->moveDown();
		
		time = 0;
	}

	time++;	
}

void GridManager::render()
{
	graphics->DrawImageUnscaledAndClipped(background, Rectangle(0, 0, 1024, 768));

	grid->draw();
	blocks[blockInPlay]->draw();

	graphics->DrawString
	(
		//col + "," + row, 
		"LEVEL:	"+ grid->getPlayerLevel().ToString() +
		"\n\n" + 
		"LINES:	" + grid->getPlayerLines().ToString() +
		"\n\n" + 
		"SCORE:	" + grid->getPlayerScore().ToString() + 
		"\n\n\n\n\n" +
		"HELP" +
		"\n\n" +
		"LEFT:\n\n"+
		"RIGHT:\n\n"+
		"UP:ROTATE\n\n"+
		"DOWN:DROP\n\n\n\n"+
		"NEXT:",
		font, 
		fontBrush, 
		50, 
		50
	);

	graphics->DrawString
	(			 
		"STATISTICS"+
		"\n\n\n\n\n" +
		"I:	"+ 
		"\n\n"+ 
		"J:	"+ 
		"\n\n"+ 
		"L:	"+  
		"\n\n"+
		"O:" +
		"\n\n"+
		"S:"+
		"\n\n"+
		"T:"+ 
		"\n\n"+
		"Z:"+
		"\n\n",
		font, 
		fontBrush, 
		737, 
		50
	);
}

Block^ GridManager::getGameBlock()
{
	int startX = 6;
	int alpha = 99;
	switch(rGen->Next(7))
	{
		case 0:
			return gcnew I(startX, Color::FromArgb(alpha, Color::Red), grid);
		case 1:
			return gcnew J(startX, Color::FromArgb(alpha, Color::White), grid);
		case 2:
			return gcnew L(startX, Color::FromArgb(alpha, Color::Violet), grid);
		case 3:
			return gcnew O(startX, Color::FromArgb(alpha, Color::Blue), grid);
		case 4:
			return gcnew S(startX, Color::FromArgb(alpha, Color::Green), grid);
		case 5:
			return gcnew T(startX, Color::FromArgb(alpha, Color::Orange), grid);
		case 6:
			return gcnew Z(startX, Color::FromArgb(alpha, Color::LightBlue), grid);
		default:
			return nullptr;
	}
}