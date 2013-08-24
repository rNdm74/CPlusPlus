#include "StdAfx.h"
#include "GameManager.h"

GridManager::GridManager(Graphics^ dbGraphics, Rectangle clientRectangle)
{
	rGen = gcnew Random();
	graphics = dbGraphics;
	screenBounds = clientRectangle;


	pfc = gcnew PrivateFontCollection();
	pfc->AddFontFile("PressStart2P.ttf");

	background = Image::FromFile("background5.jpg");

	font = gcnew Font(pfc->Families[0], 16, FontStyle::Regular);
	fontBrush = gcnew SolidBrush(Color::CornflowerBlue);

	grid = gcnew GameGrid(Point(302,-30), graphics, GAMEGRID_COLS, GAMEGRID_ROWS);
	preview = gcnew Grid(Point(50,510), graphics, PREVIEW_COLS, PREVIEW_ROWS); 

	blocks = gcnew array<Block^>(1000);

		

	blockStats = gcnew array<int>(7);
	blockTypes = gcnew array<EBlockType>
	{
		I_BLOCK,
		J_BLOCK, 
		L_BLOCK, 
		O_BLOCK, 
		S_BLOCK, 
		T_BLOCK,
		Z_BLOCK
	};

	for(int b = 0; b < blocks->Length; b++)
		blocks[b] = generateBlock();

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
	{
		updateStats(blocks[blockInPlay]->getBlockType());
		blockInPlay++;
	}
		
	if(time > waitTime - (grid->getPlayerLevel() * 20))
	{
		blocks[blockInPlay]->moveDown();
		
		time = 0;
	}

	time++;

	grid->update();
}

void GridManager::updateStats(EBlockType type)
	{		
		for(int i = 0; i < blockTypes->Length; i++)
			if(type == blockTypes[i]) blockStats[i]++;		
	}

void GridManager::render()
{
	graphics->DrawImageUnscaledAndClipped(background, screenBounds);

	grid->draw();
	blocks[blockInPlay]->draw();
	blocks[blockInPlay+1]->drawPreview();
	

	graphics->DrawString
	(
		//col + "," + row, 
		"LEVEL:	"+ grid->getPlayerLevel().ToString() +
		"\n\n" + 
		"LINES:	" + grid->getPlayerLines().ToString() +
		"\n\n" + 
		"SCORE:	" + grid->getPlayerScore().ToString() + 
		"\n\n\n\n" +
		"HELP" +
		"\n\n\n" +
		"LEFT:MOVE\n\n"+
		"RIGHT:MOVE\n\n"+
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
		"\n\n\n\n"+
		"PLACED"+		
		"\n\n"+
		"I:	"+ blockStats[0] +  
		"\n\n"+ 
		"J:	"+  blockStats[1] + 
		"\n\n"+ 
		"L:	"+  blockStats[2] +   
		"\n\n"+
		"O:	" +  blockStats[3] + 
		"\n\n"+
		"S:	"+  blockStats[4] + 
		"\n\n"+
		"T:	"+  blockStats[5] + 
		"\n\n"+
		"Z:	"+  blockStats[6] + 
		"\n\n",
		font, 
		fontBrush, 
		757, 
		50
	);
}

Block^ GridManager::generateBlock()
{
	switch(rGen->Next(blockTypes->Length))
	{
		case 0:
			return gcnew I(START_X, Color::FromArgb(ALPHA, Color::Red), grid, preview);
		case 1:
			return gcnew J(START_X, Color::FromArgb(ALPHA, Color::White), grid, preview);
		case 2:
			return gcnew L(START_X, Color::FromArgb(ALPHA, Color::Violet), grid, preview);
		case 3:
			return gcnew O(START_X, Color::FromArgb(ALPHA, Color::Blue), grid, preview);
		case 4:
			return gcnew S(START_X, Color::FromArgb(ALPHA, Color::Green), grid, preview);
		case 5:
			return gcnew T(START_X, Color::FromArgb(ALPHA, Color::Orange), grid, preview);
		case 6:
			return gcnew Z(START_X, Color::FromArgb(ALPHA, Color::LightBlue), grid, preview);
		default:
			return nullptr;
	}
}