#include "StdAfx.h"
#include "GamePlay.h"

GamePlay::GamePlay(ResourceManager^ rm, Graphics^ dbGraphics, Rectangle clientRectangle, Font^ gameFont, Brush^ fontBrush, Sound^ sound)
		 : Game(rm, dbGraphics, screenBounds, gameFont, fontBrush, sound)
{
	// Create random instance
	rGen = gcnew Random();
	
	// Load background image
	//background = Image::FromFile("background.jpg");

	// Create gamegrid and preview
	grid = gcnew GameGrid(rm, Point(302,-30), graphics, sound, GAMEGRID_COLS, GAMEGRID_ROWS);
	preview = gcnew Grid(rm, Point(757,480), graphics, PREVIEW_COLS, PREVIEW_ROWS); 

	// Create arrays for tracking block stats
	tetriminoStats = gcnew array<int>(7);
	tetriminoTypes = gcnew array<ETetriminoType>
	{
		I_TETRIMINO,
		J_TETRIMINO, 
		L_TETRIMINO, 
		O_TETRIMINO, 
		S_TETRIMINO, 
		T_TETRIMINO,
		Z_TETRIMINO
	};

	// Create first two tetriminos
	tetriminoInPlay = generateTetrimino();
	nextTetrimino = generateTetrimino();

	// Initialize game update time
	waitTime = 50;
}

void GamePlay::moveLeft()
{
	tetriminoInPlay->moveLeft();
	gSound->play("SFX_PieceMoveLR");
}

void GamePlay::moveRight()
{
	tetriminoInPlay->moveRight();
	gSound->play("SFX_PieceMoveLR");
}

void GamePlay::moveDown()
{
	tetriminoInPlay->moveDown();
	gSound->play("SFX_PieceFall");
}

void GamePlay::moveRotate()
{
	tetriminoInPlay->moveRotate();	
}

EGameState GamePlay::input(KeyEventArgs^  e)
{
	Point p = tetriminoInPlay->getCurPosition()[2];

	// If block visible in game grid 
	if(p.Y > 2)
	{
		if(e->KeyCode == Keys::Left) moveLeft();
		if(e->KeyCode == Keys::Right) moveRight();						
		if(e->KeyCode == Keys::Up) moveRotate();	
		if(e->KeyCode == Keys::Down) moveDown();
		
		if(e->KeyCode == Keys::S) gSound->Play = !gSound->Play;
		if(e->KeyCode == Keys::Space)
		{
			setDrop(true);
			gSound->play("SFX_PieceHardDrop");			
		}
	}

	if(e->KeyCode == Keys::P) return MENU;
	if(e->KeyCode == Keys::Escape) return MENU;

	return PLAY;
}

void GamePlay::update()
{
	grid->update();
	
	// If tetrimino is placed
	if(tetriminoInPlay->isPlaced())
	{
		setDrop(false);
		updateStats(tetriminoInPlay->getTetriminoType());
		//random block gen
		tetriminoInPlay = nextTetrimino;
		nextTetrimino = generateTetrimino();
		//blockInPlay++;
	}

	// Tetrimino hard drop
	if(drop) tetriminoInPlay->moveDown();		
		
	// Tetrimino update time based on player level
	if(time > waitTime - (grid->getPlayerLevel()* 5))
	{
		tetriminoInPlay->moveDown();		
		time = 0;
	}

	// Increase game time
	time++;	
}

void GamePlay::render()
{
	// Draw background
	graphics->DrawImageUnscaledAndClipped(background , screenBounds);

	// Draw game grid
	grid->draw();

	// Draw tetrimino in play
	tetriminoInPlay->draw();

	// Draw preview
	nextTetrimino->drawPreview();
	
	// Draw main player hud
	graphics->DrawString
	( 
		"LEVEL:"+ grid->getPlayerLevel().ToString() +
		"\n\n"+ 
		"LINES:"+ grid->getPlayerLines().ToString() +
		"\n\n"+ 
		"SCORE:"+ grid->getPlayerScore().ToString() + 
		"\n\n\n\n"+
		"\n\n\n"+
		"HELP"+
		"\n\n\n"+
		"LEFT:MOVE"+
		"\n\n"+
		"RIGHT:MOVE"+
		"\n\n"+
		"DOWN:MOVE"+
		"\n\n"+
		"UP:ROTATE"+
		"\n\n"+		
		"SPACE:DROP"+
		"\n\n"+
		"S:SOUND " + ((gSound->Play) ? "ON" : "OFF")+
		"\n\n"+	
		//"P:PAUSE"+
		//"\n\n"+		
		"ESC:PAUSE",
		font, 
		brush, 
		50, 
		50
	);

	// Draw stats player hud
	graphics->DrawString
	(			 
		"STATISTICS"+
		"\n\n\n"+
		"    I:	"+ tetriminoStats[0] +  
		"\n\n"+ 
		"    J:	"+  tetriminoStats[1] + 
		"\n\n"+ 
		"    L:	"+  tetriminoStats[2] +   
		"\n\n"+
		"    O:	" +  tetriminoStats[3] + 
		"\n\n"+
		"    S:	"+  tetriminoStats[4] + 
		"\n\n"+
		"    T:	"+  tetriminoStats[5] + 
		"\n\n"+
		"    Z:	"+  tetriminoStats[6] + 
		"\n\n\n"+
		"TOTAL:	"+ getTotalStats()+
		"\n\n\n\n"+
		"NEXT",
		font, 
		brush, 
		727, 
		50
	);	
}

void GamePlay::updateStats(ETetriminoType type)
	{	
		// Update stats based on dropped block
		for(int i = 0; i < tetriminoTypes->Length; i++)
			if(type == tetriminoTypes[i]) tetriminoStats[i]++;		
	}



Tetrimino^ GamePlay::generateTetrimino()
{
	// Return a randomly created tetrimino
	switch(rGen->Next(tetriminoTypes->Length))
	{
		case 0:
			return gcnew I(rManager, Color::FromArgb(ALPHA, Color::Red), grid, preview);
		case 1:
			return gcnew J(rManager, Color::FromArgb(ALPHA, Color::Yellow), grid, preview);
		case 2:
			return gcnew L(rManager, Color::FromArgb(ALPHA, Color::Magenta), grid, preview);
		case 3:
			return gcnew O(rManager, Color::FromArgb(ALPHA, Color::Blue), grid, preview);
		case 4:
			return gcnew S(rManager, Color::FromArgb(ALPHA, Color::Cyan), grid, preview);
		case 5:
			return gcnew T(rManager, Color::FromArgb(ALPHA, Color::Green), grid, preview);
		case 6:
			return gcnew Z(rManager, Color::FromArgb(ALPHA, Color::Orange), grid, preview);
		default:
			return nullptr;
	}
}

bool GamePlay::isGameOver()
{
	// Loop through tetrimino points
	for(int pos = 0; pos < tetriminoInPlay->getCurPosition()->Length; pos++)
	{ 
		Point p = tetriminoInPlay->getCurPosition()[pos];

		// If outside of game grid game is over
		if(tetriminoInPlay->isPlaced() && p.Y < 3)
		{
			gSound->play("SFX_GameOver");
			return true;
		}
	}

	// Default game is running
	return false;
}

int GamePlay::getTotalStats()
{
	// Addition of all block statistics return total
	int total = 0; 

	for(int i=0;i<tetriminoStats->Length; i++)
		total += tetriminoStats[i];
	
	return total;
}
